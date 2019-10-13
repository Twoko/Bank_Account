#ifndef CLIENT_H
#define CLIENT_H


#include<iostream>
#include <string>
using namespace std;

class Client
{

	string FirstName,LastName; //stores names of Owner
	string accountType;  // specifies account type
	int id;
public:
	int getId();
	void setId(int i);
	string getName();
	string getLName();
	string getAccountType();
	void setName(string name);
	void setLName(string lname);
	void setAccountType(string type);

};

#endif
