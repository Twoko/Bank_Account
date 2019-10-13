#include<iostream>
#include"Saving.h"
#include"Checking.h"
#include<fstream>
#include <list>
#include <iterator>

using namespace std;

void clearFile()  //empties database
{
	ofstream ofs;
	ofs.open("accounts.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}
void resave(Account ** acc, int c,list<Account*>l)  //resave data to database
{

	clearFile();
	Account* a;
	list <Account*> ::iterator it;
	for (it = l.begin(); it != l.end(); ++it)
	{
		a = *it;
		a->save();
	}

}
int noOfAccounts()  //returns no of lines
{
	int count = 0;
	string line;

	/* Creating input filestream */
	ifstream file("accounts.txt");
	while (getline(file, line))
		count++;
	if (count >= 0)
		return count;
	else
		return 0;

}
void read(Account ** acc,int c, list <Account*> &l)  //reads data from database
{
	string word;
	ifstream file("accounts.txt");
    for (int i=0;i<c;i++)
	{
		int id;
		string name,lname,type;
		int bal;
		file >> id;
		file >> name;
		file >> lname;
		file >> type;
		file >> bal;
		if (type == "saving")    // storing data according to account types
		{
			l.push_back(new Saving(10, name, lname, bal, id));

		}
		else if (type == "checking")
		{
			l.push_back(new Checking(15, name, lname, bal, id));

		}
	}
}

int main()
{
	int count = 0;
	count = noOfAccounts();
	list <Account*> acc;   //creating a linked list of type Account
	Account ** data=new Account*[200];
	read(data,count,acc);
	char ch = 'Y';
	while (ch != 'N')
	{
		system("cls");
		cout << "\n\n1. Add Client";
		cout << "\n2. View all Clients";
		cout << "\n3. View all Checking accounts and their assets";
		cout << "\n4. View all Saving accounts and their assets";
		cout << "\n5. Perform a transaction";
		cout << "\n6. Remove a client";
		cout << "\n7. Edit a client";
		cout << "\n'N' to stop";

		cout << "\n\nSelect (1-7|N) : ";
		cin >> ch;

		switch(ch)
		{
		case '1':
		{
			//Saving new clients

			string name,lname,type;
			cout << "\nEnter First Name of Client : ";
			cin >> name;
			cout << "\nEnter Last Name of Client : ";
			cin >> lname;
			cout << "\nEnter Type of Account : 'S' for saving/ 'C' for checking ";

			cin >> type;

			//Polymorphism to assign type of accounts
			Account * a;   //parent class
			if (type == "S")
			{
				a = new Saving(10, name,lname,0,count);

				acc.push_back(a);
				count++;
			}
			else if(type=="C")
			{
		     a = new Checking(15, name,lname,0,count);
			 acc.push_back(a);

			 count++;

			}

			resave(data, count,acc);



		}
		case '2':
		{

			//viewing clients and account
			cout << "\n\n------------  ACCOUNTS ------------------";
			Account* a;
			list <Account*> ::iterator it;
			for (it = acc.begin(); it != acc.end(); ++it)
			{
				a = *it;
				a->showDetails();
			}
			system("pause");
			break;
		}
		case '3':
		{
			//viewing checking accountss
			cout << "\n\n------------ CHECKING ACCOUNTS ------------------";
			Account* a;
			list <Account*> ::iterator it;
			for (it = acc.begin(); it != acc.end(); ++it)
			{
				a = *it;
				if (a->owner.getAccountType() == "checking")
                     a->showDetails();
			}

			system("pause");
			break;
		}
		case '4':
		{
			//viewing saving accounts

			Account* a;
			list <Account*> ::iterator it;

			cout << "\n\n------------ SAVING ACCOUNTS ------------------";

			for (it = acc.begin(); it != acc.end(); ++it)
			{
				a = *it;
				if (a->owner.getAccountType() == "saving")
					a->showDetails();
			}
			system("pause");
			break;
		}
		case '5':
		{

			//withdraw and depositing cash
			string name,lname;
			cout << "Enter the FIRST name of Client? ";
			cin >> name;
			cout << "Enter the Last name of Client? ";
			cin >> lname;
			bool status = true;

			Account* a;
			list <Account*> ::iterator it;
			for (it = acc.begin(); it != acc.end(); ++it)
			{
				a = *it;
				if (a->owner.getName() == name && a->owner.getLName() == lname)   // searching for client
				{
					cout << "D for deposit || W for withdraw ";
					char t;
					cin >> t;
					cout << "Enter Amount";
					double amount;
					cin >> amount;

					cout << name;
					status = false;
					if (t == 'D' || t=='d')
					{
						a->deposit(amount);
					}
					else if (t == 'W' || t=='w')
					{
						a->withdraw(amount);
					}
				}

			}
			if (!status)
			{
				cout << "\n\n------------ TRANSACTION SUCCESSFULL ------------------";
			}
			if (status)
			{
				cout << "\n\n**********************************No such client exists*********************************";
			}

			system("pause");
			resave(data, count, acc);
			break;
		}
		case '6':
		{
			//deleting a client from database
			string name,lname;
			cout << "Enter the name of Client? ";
			cin >> name;
			cout << "Enter the Last name of Client? ";
			cin >> lname;
			bool status = true;

			Account* a,* del;
			list <Account*> ::iterator it;
			for (it = acc.begin(); it != acc.end(); ++it)
			{
				a = *it;
				if (a->owner.getName() == name && a->owner.getLName() == lname)
				{
					del = a;
					status = false;


				}

			}
			if (!status)
			{
				acc.remove(del);       //deleting from linked list

				cout << "\n\n------------ DELETED ACCOUNT SUCCESSFULLY ------------------\n";
			}

			if (status)
			{
				cout << "\n\n***********************No such client exists***********************************\n";
			}
            system("pause");
			resave(data, count, acc);
			break;
		}
		case '7':
		{
			//Editing the Account on basis of names

			string name, lname;
			cout << "Enter the name of Client you want to edit? ";
			cin >> name;
			cout << "Enter the SECOND name of Client you want to edit? ";
			cin >> lname;
			bool status = true;

			Account* a, *del;
			list <Account*> ::iterator it;
			for (it = acc.begin(); it != acc.end(); ++it)
			{
				a = *it;
				if (a->owner.getName() == name && a->owner.getLName() == lname)
				{
					string fN, lN, aT;
					int b;
					cout << "\n\n\nEnter new First Name: ";    //Enter new Data
					cin >> fN;
					cout << "\n\n\nEnter new Last Name: ";
					cin >> lN;
					cout << "\n\n\nEnter New Balance: ";
					cin >> b;
					cout << "\n\n\nEnter new Account Type (saving/checking): ";
					cin >> aT;
					a->owner.setName(fN);   // updating the details
					a->owner.setLName(lN);
					a->owner.setAccountType(aT);
					a->balance = b;
					status = false;

				}

			}

			if (!status)
			{
				cout << "\n\n------------ EDITED ACCOUNT SUCCESSFULLY ------------------\n";
			}
			if (status)
			{
				cout << "\n\n***********************No such client exists***********************************\n";
			}
			system("pause");
			resave(data, count, acc);
			break;
		}
		case 'N':
		{
			exit(0);  //Exit in case of pressing N
		}
		default:
		{
			cout << "\n\n Invalid Choice .  ReEnter ";
			system("pause");
			resave(data,count,acc);   // resave data
			break; }
		}
	}
}
