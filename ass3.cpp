//============================================================================
// Name        : tree.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "treeAdt.h"
using namespace std;

int main()
{
    int hieght,i,ch=0,no=0,k=0;
	treeadt t;
	struct node*root1=NULL;
	struct node*root2=NULL;
	while(1)
    {
        cout<<endl<<"MENU";
        cout<<endl<<"1.INSERT (RECCURSSIVE)";
        cout<<endl<<"2.DISPLAY";
        cout<<endl<<"3.COPY";
        cout<<endl<<"4.DEPTH";
        cout<<endl<<"5.LEAF NODE";
        cout<<endl<<"ENTER YOUR CHOICE";
        cin>>ch;

        switch(ch)
        {
        case 1:
            cout<<endl<<"HOW MANY NUMBERS DO YOY WANT TO INSERT";
            cin>>no;

            for(int i=0;i<no;i++)
                root1=t.insertr(root1);

            cout<<endl<<"TREE CREATED! ";
            cout<<endl;
            cout<<"PREORDER"<<"\t";
            t.btrpreorder(root1);
            cout<<endl;
            cout<<"INORDER"<<"\t";
            t.btrinorder(root1);
            cout<<endl;
            cout<<"postORDER"<<"\t";
            t.btrpostorder(root1);
            break;

        case 2:
            cout<<endl;
            cout<<"PREORDER"<<"\t";
            t.btrpreorder(root1);
            cout<<endl;
            cout<<"INORDER"<<"\t";
            t.btrinorder(root1);
            cout<<endl;
            cout<<"postORDER"<<"\t";
            t.btrpostorder(root1);
            cout<<endl;
		   t.level_order(root1,0);
            break;

        case 3:
            root2=t.copy_tree(root1);
            cout<<endl;
            cout<<"PREORDER"<<"\t";
            t.btrpreorder(root2);
            cout<<endl;
            cout<<"INORDER"<<"\t";
            t.btrinorder(root2);
            cout<<endl;
            cout<<"postORDER"<<"\t";
            t.btrpostorder(root2);

            break;

        case 4:
            hieght=t.depth(root1);
            cout<<endl;
            cout<<"DEPTH OF TREE"<<hieght;
            break;

        case 5:
            cout<<endl<<"NO. OF LEAF NODE IN THE TREE";
            k=t.leafnode(root1);
            cout<<endl;
            cout<<k;
            break;

        default:
            cout<<"ENTER CORRECT CHOICE"<<endl;
            break;
        }
    }
}
