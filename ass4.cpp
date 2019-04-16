//============================================================================
// Name        : ass4.cpp
// Author      : vivek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stackAdt.h"
#include "treeAdt.h"
using namespace std;



void get_postfix(char postfix[])
{

	cout<<"Enter postfix expression"<<endl;


		cin>>postfix;



}



node* create_tree(char postfix[])
{
	Stack<struct node*>s;
	int i;
	char x;
	i=0;
	while(postfix[i]!='\0')
	{
		x=postfix[i];

		if(isalnum(x))
		{
			node* node1;

			node1 = new node;

			node1->data=x;
			s.push(node1);
		}
		else
		{
			node *node1,*temp,*temp1;
			node1 = new node;
			node1->data=x;
			temp=s.pop();
			node1->rchild=temp;

			temp1=s.pop();
			node1->lchild=temp1;
			s.push(node1);
		}
		i++;

	}
	node* root;
	root=s.pop();
	return root;

}

int main() {

	int ch,ch1,ch2,ch4;
	char postfix[30];
	node *root;
	treeadt t;
	do
	{	cout<<endl<<"\tMENU"<<endl;
		cout<<"1.CREATE EXPRESSION TREE"<<endl;
		cout<<"2.TRAVERSE TREE"<<endl;
		cout<<"3.EXIT\n"<<endl;
		cout<<"PLEASE CHOOSE ONE OPTION"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			 get_postfix(postfix);
			root=create_tree(postfix);
			cout<<"TREE SUCESSFULLY CREATED!"<<endl;
			break;
		case 2:
			cout<<"PRESS 1 TO DISPLAY USING RECURSIVE FUNCTION"<<endl;
			cout<<"PRESS 2 TO DISPLAY USING ITERATIVE FUNCTION"<<endl;
			cin>>ch1;
			switch(ch1)
			{
			case 1:
				cout<<endl<<"1.TRAVERSE INORDER(Recursive)"<<endl;
				cout<<"2.TRAVERSE PREORDER(Recursive)"<<endl;
				cout<<"3.TRAVERSE POSTORDER(Recursive)"<<endl;
				cout<<"PLEASE CHOOSE ONE OPTION!"<<endl;
				cin>>ch2;
				switch(ch2)
				{
					case 1:	cout<<"Inorder traversal: ";
							t.btrinorder(root);
							cout<<endl;
							break;
					case 2:cout<<"Preorder traversal: ";
							t.btnrpreorder(root);
							cout<<endl;
							break;
					case 3:
							cout<<"Postorder Traversal: ";
							t.btnrpostorder(root);
							cout<<endl;
							break;
					default:
							cout<<endl<<"Please enter correct choice!"<<endl;
				}
							break;
			case 2:
				cout<<endl<<"1.TRAVERSE INORDER(Non-Recursive)"<<endl;
				cout<<"2.TRAVERSE PREORDER(Non-Recursive)"<<endl;
				cout<<"3.TRAVERSE POSTORDER(Non-Recursive)"<<endl;
				cout<<"PLEASE CHOOSE ONE OPTION!"<<endl;
				cin>>ch4;
				switch(ch4)
				{
				case 1:	cout<<"Inorder traversal: ";
						t.btnrinorder(root);
						cout<<endl;
				     	break;
				case 2:cout<<"Preorder traversal: ";
				    	t.btnrpreorder(root);
						cout<<endl;
						break;
				case 3:
						cout<<"Postorder Traversal: ";
						t.btnrpostorder(root);
						cout<<endl;
						break;
				default:
						cout<<endl<<"Please enter correct choice!"<<endl;
				}
				break;
				case 3:

					break;
			default:cout<<"PLEASE ENTER CORRECT CHOICE"<<endl;

						}

			}
		cout<<"THANK YOU!"<<endl;




	}while(ch!=3);








	return 0;
}
