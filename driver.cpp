#include<iostream>
#include"Saving.h"
#include"Checking.h"
#include<fstream>
#include <iterator>
#include "LinkedList.h"


using namespace std;

void clearFile()  //empties database
{
	ofstream ofs;
	ofs.open("accounts.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}
void resave(int c,LinkedList &l)  //resave data to database
{

	clearFile();
	l.save();


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
void read(int c, LinkedList &l)  //reads data from database
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
		if (type == "saving")
		{
			l.add(new Saving(10, name, lname, bal, id));

		}
		else if (type == "checking")
		{
			l.add(new Checking(15, name, lname, bal, id));

		}
	}
}

int main()
{
	int count = 0;
	LinkedList l;
	count = noOfAccounts();
	read(count,l);



	char ch = 'Y';
	while (ch != 'N')
	{
		system("cls");
			cout <<"\n\t|               Banking Program                 |\n"
				 <<"\t+-----------------------------------------------+\n"
				 <<"\t|1. Add Client                                  |\n"
				 <<"\t|2. View all Clients                            |\n"
				 <<"\t|3. View all Checking Accounts and Their Assets |\n"
				 <<"\t|4. View all Saving Accounts and Their Assets   |\n"
				 <<"\t|5. Perform a Transaction                       |\n"
				 <<"\t|6. Remove a Client                             |\n"
				 <<"\t|7. Edit a Client                               |\n"
				 <<"\t|                                               |\n"
				 <<"\t|'N' to Stop                                    |\n"
				 <<"\t+-----------------------------------------------+\n\n";


		cout << "\n\nSelect (1-7|N) ";
		cin >> ch;

		switch(ch)
		{
		case '1':
		{
			//Saving new clients
			system("cls");
					string name,lname,type;
					double initBalance;
					cout <<"\n\t|                Adding Client                  |\n"
						 <<"\t+-----------------------------------------------+\n"
						 << "\tEnter Full Name of Client: ";
					cin >> name >> lname;
					cout <<"\tEnter initial balance: ";
					cin >> initBalance;
					cout << "\n\tEnter Type of Account"
						 	 <<"\n\t\t'S' for Saving"
						   <<"\n\t\t'C' for Checking: ";
					cin >> type;

					//Polymorphism to assign type of accounts
					Account * a;   //parent class
			if (type == "S")
			{
				a = new Saving(10, name,lname,initBalance,count);

				l.add(a);
				count++;
			}
			else if(type=="C")
			{
		     a = new Checking(15, name,lname,initBalance,count);
			 l.add(a);

			 count++;

			}

			resave(count,l);



		}
		case '2':
		{
			//viewing clients and account
			system("cls");
					cout <<"\n\t|                   Accounts                    |\n"
						 <<"\t+-----------------------------------------------+\n";
			l.print();
			system("pause");
			break;
		}
		case '3':
		{
			//viewing checking accountss
			cout <<"\n\t|              Checking Accounts                |\n"
					 <<"\t+-----------------------------------------------+\n";
			l.printChecking();

			system("pause");
			break;
		}
		case '4':
		{
			//viewing saving accounts
			system("cls");
			cout <<"\n\t|               Savings Accounts                |\n"
					 <<"\t+-----------------------------------------------+\n";
			l.printSaving();
			system("pause");
			break;
		}
		case '5':
		{

			//withdraw and depositing cash
			system("cls");
		 cout <<"\n\t|                 Transactions                  |\n"
					<<"\t+-----------------------------------------------+\n";
			l.transaction();

			resave(count, l);
			system("pause");

			break;
		}
		case '6':
		{
			//deleting a client from database
			system("cls");
			cout <<"\n\t|                   Deletion                    |\n"
					 <<"\t+-----------------------------------------------+\n";
			l.deleteNode();
			system("pause");
			resave(count, l);
			break;
		}
		case '7':
		{
			//Editing the Account on basis of names
			cout <<"\n\t|               Editing Account                 |\n"
					 <<"\t+-----------------------------------------------+\n";
			l.editNode();
			system("pause");
			resave(count, l);
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
			resave(count,l);
			break; }
		}
	}
}
