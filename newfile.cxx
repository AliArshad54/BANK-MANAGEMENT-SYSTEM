#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
class Bank{
	private:
		string username,password;
		string username1,password1;
		int total;
		struct person{
			string name,email,ID;
			int contact,cash;
		}person[100];
	public:
		Bank(){
			total=0;
		}
		void choice();
		void start();
		void signUp();
		void login();
		void Data();
		void show();
		void update();
		void search();
		void transactions();
		void del();
};
int main(){
	Bank b;
	b.start();
	b.signUp();
	b.login();
}
void Bank::choice(){
	char ch;
	while(true){
   	cout<<"\n\nPRESS..!!"<<endl;
	cout<<"1. Create new account"<<endl;
	cout<<"2. View customers list"<<endl;
	cout<<"3. Update information of existing account"<<endl;
	cout<<"4. Check the details of an existing account"<<endl;
	cout<<"5. For transactions"<<endl;
	cout<<"6. Remove existing account"<<endl;
	cout<<"7. Exit"<<endl;
	ch=getch();
	system("CLS");
	switch(ch){
		case '1':
			Bank::Data();
			break;
		case '2':
			Bank::show();
			break;
		case '3':
			Bank::update();
			break;
		case '4':
			Bank::search();
			break;
		case '5':
			Bank::transactions();
			break;
		case '6':
			Bank::del();
			break;
		case '7':
			exit(0);
			break;
		default:
			cout<<"\aInvalid input"<<endl;
	        break;
	}
    }
}
void Bank::start(){
			char arr[]={'B','A','N','K',' ','M','A','N','A','G','E','M','E'
			,'N','T',' ','S','Y','S','T','E','M'};
			cout<<"\n\n\n\n\n\t\t\t";
			for(int i=0;i<24;i++){
				cout<<arr[i];
				Sleep(30);
			}
			Sleep(1000);
			system("cls");
		}
		void Bank::signUp(){
			cout<<"\n\n\t\tBank Management System"<<endl;
			cout<<"\n\t\t  SIGN UP"<<endl;
			cout<<"\t\tEnter Username: ";
			cin>>username;
			cout<<"\t\tEnter Password: ";
			cin>>password;
			cout<<"\t\tYour new id is creating please wait";
			for(int i=0;i<5;i++){
				cout<<".";
				Sleep(100);
			}
		}
		void Bank::login(){
			system("cls");
			cout<<"\n\n\t\t LOGIN"<<endl;
			cout<<"\t\tEnter Username: ";
			cin>>username1;
			cout<<"\t\tEnter Password: ";
			cin>>password1;
			if(username==username1&&password==password1){
				system("cls");
				Bank::choice();
			}
			else if(username!=username1&&password==password1){
				cout<<"\t\t\aInvalid username please try again";
				Sleep(3000);
				Bank::login();
			}
			else if(username==username1&&password!=password1){
				cout<<"\t\t\aInvalid password please try again";
				Sleep(3000);
				Bank::login();
			}
			else{
				cout<<"\t\t\aInvalid username and password please try again";
				Sleep(3000);
				Bank::login();
			}
		}
		void Bank::Data(){
			cout<<"\nEnter data of person"<<endl<<endl;
			cout<<"Enter Name: ";
			cin>>person[total].name;
			cout<<"Enter ID: ";
			cin>>person[total].ID;
			cout<<"Enter Contact: ";
			cin>>person[total].contact;
			cout<<"Enter Email: ";
			cin>>person[total].email;
			cout<<"Enter Cash: ";
			cin>>person[total].cash;
			total++;
		}
		void Bank::show(){
			for(int i=0;i<total;i++){
				cout<<"\nData of person "<<i+1<<endl;
				cout<<"Name: "<<person[i].name<<endl;
				cout<<"ID: "<<person[i].ID<<endl;
				cout<<"Contact: "<<person[i].contact<<endl;
				cout<<"Email: "<<person[i].email<<endl;
				cout<<"Cash: "<<person[i].cash<<endl;
			}
		}
		void Bank::update(){
			string id;
			cout<<"Enter ID of person for update"<<endl;
			cin>>id;
			for(int i=0;i<total;i++){
				if(id==person[i].ID){
				cout<<"\nPrevious data of person "<<i+1<<endl;
				cout<<"Name: "<<person[i].name<<endl;
				cout<<"ID: "<<person[i].ID<<endl;
				cout<<"Contact: "<<person[i].contact<<endl;
				cout<<"Email: "<<person[i].email<<endl;
				cout<<"Cash: "<<person[i].cash<<endl;
				cout<<"\nEnter new data"<<endl<<endl;
				cout<<"Enter Name: ";
			cin>>person[i].name;
			cout<<"Enter ID: ";
			cin>>person[i].ID;
			cout<<"Enter Contact: ";
			cin>>person[i].contact;
			cout<<"Enter Email: ";
			cin>>person[i].email;
			cout<<"Enter Cash: ";
			cin>>person[i].cash;
			cout<<"Your required data is updated"<<endl;
			break;
				}
				if(i==total-1){
					cout<<"No such record found"<<endl;
				}
			}
		}
		void Bank::search(){
			string id;
			cout<<"Enter ID of person for check"<<endl;
			cin>>id;
			for(int i=0;i<total;i++){
				if(id==person[i].ID){
				cout<<"\nData of person "<<i+1<<endl;
				cout<<"Name: "<<person[i].name<<endl;
				cout<<"ID: "<<person[i].ID<<endl;
				cout<<"Contact: "<<person[i].contact<<endl;
				cout<<"Email: "<<person[i].email<<endl;
				cout<<"Cash: "<<person[i].cash<<endl;
				break;
				}
				if(i==total-1){
					cout<<"No such record found"<<endl;
				}
			}
		}
		void Bank::transactions(){
			string id;
			char ch;
			int cash;
			cout<<"Enter id of person which you want to transaction"<<endl;
			cin>>id;
			for(int i=0;i<total;i++){
				if(id==person[i].ID){
					cout<<"Name: "<<person[i].name<<endl;
			     	cout<<"ID: "<<person[i].ID<<endl;
			    	cout<<"Contact: "<<person[i].contact<<endl;
				    cout<<"Email: "<<person[i].email<<endl;
					cout<<"\nExisting Cash "<<person[i].cash<<endl;
				    cout<<"\nPress 1 to deposit cash"<<endl;
				    cout<<"Press 2 to withdraw cash"<<endl;
				    ch=getch();
				    switch(ch){
				    	case '1':
				    		cout<<"Enter cash which you want to deposit"<<endl;
				    		cin>>cash;
				    		person[i].cash+=cash;
				    		cout<<"New amount is "<<person[i].cash<<endl;
				    		break;
				    	case '2':
				    		back:
				    		cout<<"Enter cash which you want to withdraw"<<endl;
				    		cin>>cash;
				    		if(cash>person[i].cash){
				    			cout<<"Your existing cash is just "<<person[i].cash<<endl;
				    			Sleep(3000);
								goto back;
							}
				    		person[i].cash-=cash;
				    		cout<<"New amount is "<<person[i].cash<<endl;
				    		break;
				    	default:
				    		cout<<"\aInvalid Input"<<endl;
				    		break;
					}
					break;
				}
				if(i==total-1){
					cout<<"No such record found"<<endl;
				}
			}
		}
		void Bank::del(){
				if(total!=0){
				char ch;
				cout<<"Press 1 to remove specific record"<<endl;
				cout<<"Press 2 to remove full record"<<endl;
				ch=getch();
				if(ch=='1'){
						string id;
						cout<<"Enter id of person which you want to remove"<<endl;
						cin>>id;
						for(int i=0;i<total;i++){
							if(id==person[i].ID){
								for(int j=i;j<total;j++){
									person[j].name=person[j+1].name;
									person[j].ID=person[j+1].ID;
									person[j].email=person[j+1].email;
									person[j].contact=person[j+1].contact;
									person[j].cash=person[j+1].cash;
									total--;
									cout<<"Your required record is deleted"<<endl;
									break;
								}
							}
							if(i==total-1){
				         	cout<<"No such record found"<<endl;
				            }
						}
		         	}
		         	else if(ch=='2'){
		         		total=0;
		         		cout<<"All record is deleted"<<endl;
					 }
					 else{
					 	cout<<"\aInvalid Input"<<endl;
					 }
						
				}
			
			else{
				cout<<"No data is entered"<<endl;
			}
		}
		
