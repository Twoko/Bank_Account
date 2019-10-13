#include"Checking.h"
#include<iostream>
#include <string>
using namespace std;

Checking::Checking(int rate, string name,string lname,double b,int id) :Account(name, "checking",lname,b,id)
{
	if (rate >= 0)
		this->interestRate = rate;
	else
	{
		cout << "Invalid Interest Rate";
	}

}
void Checking::showDetails()
{
	cout << "\n\nId of Owner: " << this->owner.getId();
	cout << "\nAccount Owner Name : " << this->owner.getName() << " " << this->owner.getLName();
	cout << "\nAccount Type : " << this->owner.getAccountType();
	cout << "\nAccount Balance : " << this->balance;
	cout << "\nAccount Interest : " << this->interestRate << "%\n";
}
