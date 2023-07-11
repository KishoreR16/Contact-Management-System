/*Create a contact management system using C++ programming.*/
#include "file2.cpp"
#include<math.h>
#include<fstream>
void get_details_from_file();
void display()
{
	cout<<setw(20)<<"1  "<<"CALL"<<endl;
	cout<<setw(20)<<"2  "<<"SEARCH CONTACT"<<endl;
	cout<<setw(20)<<"3  "<<"DELETE CONTACT"<<endl;
	cout<<setw(20)<<"4  "<<"UPDATE CONTACT"<<endl;
	cout<<setw(20)<<"5  "<<"ADD CONTACT"<<endl;
	cout<<setw(20)<<"6  "<<"DISPLAY"<<endl;
	cout<<setw(20)<<"7  "<<"PHONE CALL HISTORY"<<endl;
	cout<<setw(20)<<"8  "<<"EXIT"<<endl;
}

class Contacts
{
	public:
	string contact_name;
	string phone_number;
	string company_name;
};
Contacts contacts[100];
int index=0;

void call()                                        
{
	ofstream of("Duration.txt",ios::app);
	cout<<"enter the phone number you want to call:";
	string s;
	cin>>s;
	int flag=0;
	for(int i=0;i<index;i++)
	{
		if(contacts[i].phone_number==s)
		{
			time_Manage time;
			int a=time.getHour();
			int b=time.getMinutes();
			int c=time.getSeconds();
			
			cout<<setw(30)<<"------------------------------"<<endl;
			cout<<setw(30)<<"Speaking to "<<contacts[i].contact_name<<endl;
			cout<<setw(30)<<"------------------------------"<<endl;
			
			cout<<"press 'e' to end the call"<<endl;
			char c1;
			cin>>c1;
			int final1,final2,final3;
			if(c1=='e')
			{
				int d=time.getHour();
				int e=time.getMinutes();
				int f=time.getSeconds();
				final1=abs(a-d);
				final2=abs(b-e);
				final3=abs(c-f);
				cout<<"call duration-->";
				cout<<final1<<":"<<final2<<":"<<final3<<endl;
			}
			of<<"Phone_Number:"<<contacts[i].phone_number<<endl;
			of<<"Contact_Name:"<<contacts[i].contact_name<<endl;
			of<<"Company_Name:"<<contacts[i].company_name<<endl;
			of<<"Duration:"<<final1<<":"<<final2<<":"<<final3<<endl;
			flag=1;
			break;
		}	
	}
	if(flag==0)
	{
		cout<<"Number not found,please recheck the number"<<endl;
	}
}

void search_contact()
{
	cout<<"enter the contact number you want to search";
	string s;
	cin>>s;
	int flag=0;
	for(int i=0;i<index;i++)
	{
		if(contacts[i].phone_number==s)
		{
			cout<<"Number is found in your call list"<<endl;
			cout<<setw(40)<<"------------------------------"<<endl;
			cout<<setw(40)<<"CONTACT DETAILS"<<endl;
			cout<<setw(40)<<"------------------------------"<<endl;
			cout<<setw(20)<<"NAME"<<setw(20)<<contacts[i].contact_name<<endl;
			cout<<setw(20)<<"PHONE NO"<<setw(20)<<contacts[i].phone_number<<endl;
			cout<<setw(20)<<"COMPANY NAME"<<setw(20)<<contacts[i].company_name<<endl;
			cout<<setw(40)<<"------------------------------"<<endl;
			flag=1;
		}
		
	}
	if(flag==0)
	{
		cout<<"Number not found in your contacts"<<endl;
	}
	
}

void delete_contact()
{
	cout<<"enter the phone number you want to delete";
	string s;
	cin>>s;
	ifstream of1("Contacts.txt");
	ofstream of2("Contacts_temp.txt");
	string str1,str2;
	int flag=0;
	while(of1>>str1)
	{
		str2=str1.substr(13);
		if(str2==s)
		{
			of1>>str1;
			of1>>str1;
			flag=1;
		}
		else
		{
			of2<<str1<<endl;
			of1>>str1;
			of2<<str1<<endl;
			of1>>str1;
			of2<<str1<<endl;
		}
	}
	if(flag==0)
	{
		cout<<"Contact number not found"<<endl;
	}
	else
	{
		cout<<"Contact Number deleted"<<endl; 		//removing contact number in contact page
		ifstream of3("Duration.txt");
		ofstream of4("Duration_temp.txt");
		while(of3>>str1)
		{
			str2=str1.substr(13);
			if(str2==s)
			{
				of3>>str1;
				of3>>str1;
				of3>>str1;
			}
			else
			{
				of4<<str1<<endl;
				of3>>str1;
				of4<<str1<<endl;
				of3>>str1;
				of4<<str1<<endl;
				of3>>str1;
				of4<<str1<<endl;
			}
		}
		of3.close();
		of4.close();
		remove("Duration.txt");
		rename("Duration_temp.txt","Duration.txt");
	}
	of1.close();
	of2.close();
	remove("Contacts.txt");
	rename("Contacts_temp.txt","Contacts.txt");
	index=0;
	get_details_from_file();
	
	
}

void update_contact()
{
	cout<<"enter the phone number you like to update";
	string s,str1,str2;
	cin>>s;
	int flag=0;
	ifstream of1("Contacts.txt");
	ofstream of2("Contacts_temp.txt");
	for(int i=0;i<index;i++)
	{
		if(contacts[i].phone_number==s)
		{
			string s1;
			cout<<"enter the company name you want to update";
			cin>>s1;
			while(of1>>str1)
			{
				of2<<str1<<endl;
				of1>>str1;
				of2<<str1<<endl;
				of1>>str1;
				if(contacts[i].phone_number==s)
				{
					of2<<"Company_Name:"<<s1<<endl;
				}
				else
				{
					of2<<str1<<endl;
				}
				
				
			}
			of1.close();
			of2.close();
			remove("Contacts.txt");
			rename("Contacts_temp.txt","Contacts.txt");
			contacts[i].company_name=s1;
			cout<<setw(40)<<"------------------------------"<<endl;
			cout<<setw(40)<<"UPDATED CONTACT DETAILS"<<endl;
			cout<<setw(40)<<"------------------------------"<<endl;
			cout<<setw(20)<<"NAME"<<setw(20)<<contacts[i].contact_name<<endl;
			cout<<setw(20)<<"PHONE NO"<<setw(20)<<contacts[i].phone_number<<endl;
			cout<<setw(20)<<"COMPANY NAME"<<setw(20)<<contacts[i].company_name<<endl;
			cout<<setw(40)<<"------------------------------"<<endl;
			flag=1;
			ifstream of1("Duration.txt");
			ofstream of2("Duration_temp.txt");
			while(of1>>str1)
			{
				of2<<str1<<endl;
				of1>>str1;
				of2<<str1<<endl;
				of1>>str1;
				if(contacts[i].phone_number==s)
				{
					of2<<"Company_Name:"<<s1<<endl;
				}
				else
				{
					of2<<str1<<endl;
				}
				of1>>str1;
				of2<<str1<<endl;
				
			}
			of1.close();
			of2.close();
			remove("Duration.txt");
			rename("Duration_temp.txt","Duration.txt");
		}
	}
	if(flag==0)
	{
		cout<<"number is not found in your contact list"<<endl;
	}
	
}

void add_contact()
{ 
	ofstream of("Contacts.txt",ios::app);
	cin.ignore();
	string str;
	cout<<"\nenter the phone number to add : ";
	getline(cin,str);
	of<<"Phone_Number:"<<str<<endl;
	contacts[index].phone_number=str;
	cout<<"\nenter the contact name : ";
	getline(cin,str);
	of<<"Contact_Name:"<<str<<endl;
	contacts[index].contact_name=str;
	cout<<"\nenter the company name : ";
	getline(cin,str);
	of<<"Company_Name:"<<str<<endl;
	contacts[index].company_name=str;
	index++;
	of.close();
}

void display_contacts()
{
	cout<<setw(60)<<"---------------------------------------------------"<<endl;
	cout<<setw(20)<<"NAME"<<setw(20)<<"PHONE NO"<<setw(20)<<"COMPANY NAME"<<endl;
	cout<<setw(60)<<"---------------------------------------------------"<<endl;
	for(int i=0;i<index;i++)
	{
		cout<<setw(20)<<contacts[i].contact_name;
		cout<<setw(20)<<contacts[i].phone_number;
		cout<<setw(20)<<contacts[i].company_name<<endl;
	}
	cout<<setw(60)<<"---------------------------------------------------"<<endl;
}

void history_contacts()
{
	cout<<"enter a phone number to check the history"<<endl;
	string s,str1,str2;
	cin>>s;
	ifstream of("Duration.txt");
	int count=0;
	while(of>>str1)
	{
		str2=str1.substr(13);
		if(str2==s)
		{
			cout<<setw(20)<<str1<<endl;
			of>>str1;
			cout<<setw(20)<<str1<<endl;
			of>>str1;
			cout<<setw(20)<<str1<<endl;
			of>>str1;
			cout<<setw(20)<<str1<<endl<<endl;
			count++;
		}else
		{
			of>>str1;
			of>>str1;
			of>>str1;
			
			
		}
	}
	cout<<endl;
	cout<<setw(20)<<"Total count:"<<count<<endl;
	of.close();
	
	
}

void get_details_from_file()				//getting details from file
{
	ifstream of("Contacts.txt");
	string str1,str2;
	while(of>>str2)
	{
		str1=str2.substr(13);
		contacts[index].phone_number=str1;
		of>>str2;
		str1=str2.substr(13);
		contacts[index].contact_name=str1;
		of>>str2;
		str1=str2.substr(13);
		contacts[index].company_name=str1;
		index++;
	}of.close();
}

int main()
{
	
	cout<<setw(40)<<"========================="<<endl;
	cout<<setw(40)<<"CONTACT MANAGEMENT SYSTEM"<<endl;
	cout<<setw(40)<<"========================="<<endl;
	get_details_from_file();
	int choice;
	do
	{
		cout<<endl;
		display();
		cout<<"choose a option to perform the corresponding function"<<endl;
		cout<<"enter your choice";
		cin>>choice;
		system("cls");
		switch(choice)
		{
			case 1:
				cout<<setw(30)<<"-------------------------------"<<endl;
				cout<<setw(20)<<"CALL"<<endl;
				cout<<setw(30)<<"-------------------------------"<<endl;
				call();
				break;
			case 2:
				cout<<setw(30)<<"-------------------------------"<<endl;
				cout<<setw(20)<<"SEARCH CONTACT"<<endl;
				cout<<setw(30)<<"-------------------------------"<<endl;
				search_contact(); 
				break;
			case 3:
				cout<<setw(30)<<"-------------------------------"<<endl;
				cout<<setw(20)<<"DELETE CONTACT"<<endl;
				cout<<setw(30)<<"-------------------------------"<<endl;
				delete_contact();
				break;
			case 4:
				cout<<setw(30)<<"-------------------------------"<<endl;
				cout<<setw(20)<<"UPDATE CONTACT"<<endl;
				cout<<setw(30)<<"-------------------------------"<<endl;
				update_contact();
				break;
			case 5:
				cout<<setw(30)<<"-------------------------------"<<endl;
				cout<<setw(20)<<"ADD CONTACT"<<endl;
				cout<<setw(30)<<"-------------------------------"<<endl;
				add_contact();
				break;
			case 6:
				cout<<setw(30)<<"-------------------------------"<<endl;
				cout<<setw(20)<<"DISPLAY CONTACTS"<<endl;
				cout<<setw(30)<<"-------------------------------"<<endl;
				display_contacts();
				break;
			case 7:
				cout<<setw(30)<<"-------------------------------"<<endl;
				cout<<setw(20)<<"PHONE CALL HISTORY"<<endl;
				cout<<setw(30)<<"-------------------------------"<<endl;
				history_contacts();
				break;
				
		}
		
		
	}while(choice!=8);
	return 0;
}