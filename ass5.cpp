//============================================================================
// Name        : ass5.cpp
// Author      : vivek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "treeadt.h"
using namespace std;




int main() {
	treeadt t;
	struct node *root,*temp,*root2;
	root=NULL;
	root2=NULL;
	int ch,key,search;
	do
	{
		cout<<endl<<"1.INSERT IN BINARY SEARCH TREE"<<endl;
		cout<<"2.DISPLAY BINARY SEARCH TREE"<<endl;
		cout<<"3.SEARCH IN BINARY SEARCH TREE"<<endl;
		cout<<"4.DELETE IN BINARY SEARCH TREE"<<endl;
		cout<<"5.CREATE MIRROR TREE"<<endl;
		cout<<"6.EXIT"<<endl<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			if(root==NULL)
			{
				cout<<"ENTER ROOT KEY ELEMENT"<<endl;
				cin>>key;
				root=t.insertBST(root,key);
			}
			else
			{
			cout<<"ENTER KEY ELEMENT TO BE INSERTED"<<endl;
			cin>>key;
			t.insertBST(root,key);

			}
			cout<<"ELEMENT SUCESSFULLY INSERTED!"<<endl;
			break;
		case 2:
			cout<<"DISPLAYING LEVEL ORDER"<<endl;
			t.level_order(root,0);
			cout<<endl<<endl;
			cout<<"INORDER TRAVERSAL: ";
			t.btrinorder(root);
			cout<<endl;
			cout<<"PREORDER TRAVERSAL: ";
			t.btrpreorder(root);
			cout<<endl;
			cout<<"POSTORDER TRAVERSAL: ";
			t.btrpostorder(root);
			cout<<endl<<endl;

			break;
		case 3:
			cout<<"ENTER ELEMENT TO BE SEARCHED"<<endl;
			cin>>search;
			temp=t.search(root,search);
			if(temp==NULL)
			{
				cout<<"ELEMENT NOT FOUND"<<endl;
			}
			else
			{
				cout<<"ELEMENT FOUND:"<<temp->key<<endl;
			}
			break;
		case 4:
			break;
		case 5:
			cout<<"CREATING MIRROR TREE"<<endl;
			root2=t.copy_tree(root);
			cout<<endl;
			cout<<"ORIGINAL TREE IS: ";
			t.btrinorder(root);
			cout<<"MIRROR TREE IS: ";
			t.btrinorder(root2);
			cout<<endl;

		}
	}while(ch!=7);






	/*root=t.insertBST(root,9);
	t.level_order(root,0);*/


}
