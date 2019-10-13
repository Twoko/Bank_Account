#ifndef ACCOUNT_H
#define ACCOUNT_H


#include<iostream>
#include <string>
#include"Client.h"
using namespace std;

class Account
{
public:
	double balance;  //holds balance of account
public:	
	Client owner;   //object of type Client specifying the account owner

public:
	Account(string,string,string,double,int);
	void deposit(double amount);   
	void withdraw(double amount);
	virtual void showDetails(); //display info of account
	void save();
};


#endif