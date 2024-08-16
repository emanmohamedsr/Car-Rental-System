#pragma once
#include <string>
#include <iostream>
using namespace std;
class Customer 
{
private:
	//data of customer
	string m_customerName;
	string m_address;
	string m_phoneNumber;
public:
	//give intial values 
	Customer();
	virtual ~Customer();

	//operator overloading ">>" & "<<"
	friend ostream& operator<<(ostream& out, const Customer& c);
	friend istream& operator>>(istream& in, Customer& c);

};

