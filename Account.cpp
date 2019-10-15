#include"Account.h"
#include<iostream>
#include <string>
#include <fstream>
using namespace std;

Account::Account(string name,string type,string lname,double balance,int id) //constructor
{
	this->owner.setName(name);
	this->owner.setLName(lname);
	this->balance = balance;
	this->owner.setAccountType(type);
	this->owner.setId(id);
}


void Account::withdraw(double amount)  //withdraw cash
{
	if(balance>=amount)
	this->balance -= amount;
	else
	{
		cout << "\nNot enough balance";
	}

}
void Account::deposit(double amount)  //deposit cash
{
	if (amount >= 0)
		this->balance += amount;
	else
	{
		cout << "\nInvalid Input Entered";
	}
}
void Account::showDetails()   //display details
{
	cout << "\n\t|Id of Owner: " << this->owner.getId();
	cout << "\n\t|Account Owner Name: " << this->owner.getName()<<" "<<this->owner.getLName();
	cout << "\n\t|Account Type: " << this->owner.getAccountType();
	cout << "\n\t|Account Balance: " << this->balance<<"\n";

}
void Account::save()   //writing to database
{

		ofstream file;
		file.open("accounts.txt", std::fstream::app);
		file << this->owner.getId()<<" "<<this->owner.getName()<<" "<<this->owner.getLName()<<" "<<this->owner.getAccountType()<<" "<<this->balance<<"\n";
		file.close();
}
