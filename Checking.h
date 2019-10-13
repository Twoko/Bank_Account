#ifndef CHECKING_H
#define CHECKING_H


#include<iostream>
#include <string>
#include"Account.h"
using namespace std;

class Checking : public Account
{
	int interestRate;
public:
	Checking(int, string,string,double,int);
	void showDetails();


};

#endif