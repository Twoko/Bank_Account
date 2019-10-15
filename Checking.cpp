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
	cout << "\t Id of Owner: " << this->owner.getId()
		 << "\n\t Account Owner Name: " << this->owner.getName() << " " << this->owner.getLName()
		 << "\n\t Account Type: " << this->owner.getAccountType()
		 << "\n\t Account Balance: " << this->balance
		 << "\n\t Account Interest: " << this->interestRate << "%"
		 << "\n\t+-----------------------------------------------+\n";
}
