#include"Client.h"
#include<iostream>
#include <string>
using namespace std;

void Client::setAccountType(string type)
{
	if (type == "checking" || type == "saving")
	{
		accountType = type;
	}
	else
	{
		cout << "Wrong Account Type";
	}
}
string Client::getAccountType()
{
	return accountType;
}
int Client::getId()
{
	return this->id;
}
void Client::setId(int i)
{
	if (i >= 0)
	{
		this->id = i;
	}
	else
	{
		cout << "\n*********Invalid Id Submitted*********";
	}
}
string Client::getName()
{
	return FirstName;
}
void Client::setName(string name)
{
	FirstName = name;
}
string Client::getLName()
{
	return LastName;
}
void Client::setLName(string lname)
{
	LastName = lname;
}
