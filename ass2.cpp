#include <iostream>//header file declaration
#include "queueadt.h"
using namespace std;

int main()//main function
{
    int ch,no;//variable declaration
    queueadt q;//class variable declaration
    while(1)
    {
        cout<<"MENU"<<endl;//menu
        cout<<"1.INSERT PATIENTS DATA"<<endl;
        cout<<"2.SERVE PATIENTS"<<endl;
        cout<<"3.DISPLAY LIST OF PATIENTS"<<endl;
        cout<<"4.EXIT"<<endl;
        cout<<"ENTER YOUR CHOICE"<<endl;
        cin>>ch;

        switch(ch)//switch statement
        {
        case 1://insert data
            cout<<"HOW MANY PATIENTS DATA YOU WANT TO ENTER"<<endl;
            cin>>no;

            for(int i=0;i<no;i++)//loop to insert the data in sorted order
            {
                q.enqueue();
            }
            q.display();
            break;

        case 2://delete data
            cout<<"HOW MANY PATIENTS DATA YOU WANT TO SERVE"<<endl;
            cin>>no;

            for(int i=0;i<no;i++)//loop to delete data
            {
                q.dequeue();
            }
            q.display();
            break;

        case 3://display
            q.display();
            break;

        case 4://exit
            return 0;
        }
    }
}
