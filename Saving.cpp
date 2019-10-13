#include"Saving.h"
#include<iostream>
#include <string>
using namespace std;

Saving::Saving(int rate,string name,string lname,double balance,int id):Account(name,"saving",lname,balance,id)
{
	if(rate>=0)
	this->interestRate = rate;
	else
	{
		cout << "Invalid Interest Rate";
	}

}
void Saving::showDetails()
{

	cout << "\n\nId of Owner: " << this->owner.getId();
	cout << "\nAccount Owner Name : " << this->owner.getName() << " " << this->owner.getLName(); cout << "\nAccount Type : " << this->owner.getAccountType();
	cout << "\nAccount Balance : " << this->balance;
	cout << "\nAccount Interest : " << this->interestRate<<"%\n";
}
