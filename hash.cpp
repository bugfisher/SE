//============================================================================
// Name        : Assign_9.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include<iomanip>
using namespace std;
#define max 10

class with{
private:
	struct hash{
		long int p;		//phone number
		int link;
	};
	struct hash h[max];			//a hash table
public:
	with();
	void getdata();
	void display();
	int search(long int);
	void display_2(int );
};

with :: with(){
	for(int i=0;i<max;i++){				//initialize
		h[i].p = -5;
		h[i].link = -1;
	}
}

void with :: getdata(){

	long int phone,phone_t;
	int index,t_index,t,a;
	while(1){
	cout << "Enter phone number : ";
	cin >> phone;
		if(phone > 0){
			if(search(phone)==-1){
			break;
			}
			else{
				cout << "Already Exists\n";
			}
		}
		else{
			cout << "Please enter valid phone number \n";
		}
	}
	index = phone % max;
	t_index = index;
	t = h[t_index].p % max;

	if(h[index].p < 0){			//if it is empty
		h[index].p = phone;
	}

	else if( t == index){		//if some number is present
		while(h[t_index].link != -1){		//chaining
			t_index = h[t_index].link;
		}
		a = t_index;
		if(a == max-1){
			a = 0;
		}
		while(h[a].p > 0){
			a++;
			if(a==index){
				break;
			}
		}
		if(a==index){
			cout << "table is full";
			return;
		}
		h[t_index].link = a;
		h[a].p = phone;
	}
	else{				//if another number is present replacement will take place
		phone_t = h[index].p;
		t_index = phone_t % max;
		int start = t_index;
		//replacement
		while(h[t_index].link != index){
			t_index = h[t_index].link;
		}
		h[t_index].link = h[h[t_index].link].link;
		start++;
		if(start == max-1){
			start = 0;
		}
		while(start != t_index){
			if(h[start].p <0){
				break;
			}
			start ++;
			if(start == max){
				start = 0;
			}
		}
		if(start == t_index){
			cout << "table is full";
			return;
		}
		//fill the empty space
			h[start].p = phone_t;
			h[start].link = -1;
			t_index = phone_t % max;
			while(h[t_index].link != -1){
				t_index = h[t_index].link;
			}
			h[t_index].link = start;
		h[index].p = phone;
		h[index].link = -1;
	}
}
void with :: display(){
	cout <<  "Index" << setw(20) <<"Phone number" << setw(20) << "link" << endl;
	for(int i=0;i<max;i++){
		cout<< setw(30) << setiosflags(ios::left) <<i << setw(30) << setiosflags(ios::left)  << h[i].p << setw(30) << setiosflags(ios::left) << h[i].link << endl;
	}
}

int with :: search(long int n){
	int index = n%max;
	int c=0;
	if(h[index].p == n){
		c = index;
	}
	else if(h[index].p % max == index){
		while(h[index].link != -1){
			if(h[index].p == n){
				c = index;
			}
			index = h[index].link;
		}
		if(h[index].p == n){
			c = index;
		}

	}
	if(c==0){
		return -1;		//not present
	}
	else{
		//cout << "Present\n";
		return c;
	}
}
void with :: display_2(int i){
	cout << h[i].p << endl;
}

class without{			//class for without replacement
private:
	struct hash{
		long int p;		//phone number
		int link;
	};
	struct hash h[max];			//a hash table
public:
	without();
	void getdata();
	void display();
	int search(long int );
	void display_1(int);
};

void without :: display_1(int i){
	cout << h[i].p << endl;
}
without :: without(){
	for(int i=0;i<max;i++){				//initialize
		h[i].p = -5;
		h[i].link = -1;
	}

}

int without :: search(long int n){
	int index = n%max,c=0;
	if(h[index].p == n){
		c = index;
	}
	else if(h[index].p % max == index){
		while(h[index].link != -1){
			if(h[index].p == n){
						c = index;
					}

			index = h[index].link;
		}
		if(h[index].p == n){
			c++;
		}

	}
	else{
		for(int i=0;i<max;i++){
			if(h[index].p == n){
						c = index;
					}
		}
	}
	if(c==0){
		//cout << "Not Present\n";
		return -1;
	}
	else{
		//cout << "Present\n";
		return c;
	}
}

void without :: getdata(){

	long int phone;
	int index,t_index,t,a,i;
	while(1){
	cout << "Enter phone number : ";
	cin >> phone;

		if(phone > 0){
			if(search(phone) == -1){
			break;
			}
			else{
				cout << "Already Exists\n";
			}
		}
		else{
			cout << "Please enter valid phone number \n";
		}
	}
	index = phone % max;
	t_index = index;
	t = h[t_index].p % max;

	if(h[index].p < 0){			//if it is empty
		h[index].p = phone;
	}

	else if( t == index){		//if some number is present
		while(h[t_index].link != -1){		//chaining
			t_index = h[t_index].link;
		}
		a = t_index;
		while(h[a].p > 0){
			a++;
			if(a==index){
				break;
			}
		}
		if(a==index){
			cout << "table is full\n";
			return;
		}
		h[t_index].link = a;
		h[a].p = phone;
	}
	else{
		for( i=0;i<max;i++){
			if(h[i].p % max == index){
				break;
			}
		}
		if(i < max-1){
			while(h[i].link != -1){		//chaining
						i = h[i].link;
					}
			a = i;
			while(h[a].p > 0){
				a++;
			}
			h[i].link = a;
			h[a].p = phone;

		}
		else{		//put it in empty location
			int start = index+1;
			if(start == max-1){
				start = 0;
			}
			while(start != index){
				if(h[start].p <0){
					h[start].p = phone;
					break;
				}
				start ++;
				if(start == max){
					start = 0;
				}
			}
			if(start == index){
				cout << "table is full\n";
				return;
			}
		}
	}
}

void without :: display(){
	cout <<"Index" << setw(20)<< "Phone number" << setw(20) << "link" << endl;
	for(int i=0;i<max;i++){
		cout<< i << setw(30) << h[i].p << setw(30) << h[i].link << endl;
	}
}

int main() {
	int choice,ch,con;
	long int n;
	without a;
	with b;
	do{
		cout << "-----------MENU-------------\n";
		cout << "1.WITH CHAINING WITHOUT REPLACEMENT\n2.WITH CHAINING WITH REPLACEMENT";
		cout << "\n3.EXIT\n";
		cin >> choice;
		switch(choice){
		case 1:

			do{
				cout << "-----------------WITHOUT REPLACEMENT------------------\n";
				cout << "\t1.ENTER DETAILS\n\t2.DISPLAY\n\t3.SEARCH\n\t4.TO MAIN MENU\n";
				cin >> ch;
				switch(ch){
				case 1:
					a.getdata();
					break;
				case 2:
					a.display();
					break;
				case 3:
					cout << "Enter phone number to be searched\n";
					cin >> n;
					con = a.search(n);
					if(con == -1){
						cout << "Not Present\n";
					}
					else{
						a.display_1(con);
					}
					break;
				case 4:
					break;
				default:
					cout << "PLEASE ENTER VALID CHOICE\n";
				}
			}
			while(ch!=4);
			break;
		case 2:
			do{
				cout << "-----------------WITH REPLACEMENT------------------\n";
				cout << "\t1.ENTER DETAILS\n\t2.DISPLAY\n\t3.SEARCH\n\t4.TO MAIN MENU\n";
				cin >> ch;
				switch(ch){
				case 1:
					b.getdata();
					break;
				case 2:
					b.display();
					break;
				case 3:
					cout << "Enter phone number to be searched\n";
					cin >> n;
					con = b.search(n);
					if(con == -1){
							cout << "Not Present\n";
						}
						else{
							b.display_2(con);
						}
					break;
				case 4:
					break;
				default:
					cout << "PLEASE ENTER VALID CHOICE\n";
				}
			}
			while(ch!=4);
			break;
		case 3:
			break;
		default:
			cout << "PLEASE ENTER VALID CHOICE\n";
		}
	}
	while(choice!=3);
}
