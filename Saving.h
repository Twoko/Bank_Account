#ifndef SAVING_H
#define SAVING_H


#include<iostream>
#include <string>
#include"Account.h"
using namespace std;

class Saving: public Account
{
	int interestRate;
public:
	Saving(int,string,string,double,int);
	void showDetails();


};
#endif