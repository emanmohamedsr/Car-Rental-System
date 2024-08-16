#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Customer.h"
#include "Car.h"

class Reservation 
{
private:
    //to make sure that period does not intersect of invoice arrar in car rental system calss 
    int m_startDate;
    int m_endDate;
public:
    //give initial values
    Reservation(); 

    void setstartDate(int s);
    void setendDate(int e);
    //to check period -> car can have more than one reservation
    int getstarDate();
    int getendDate();
    //overload operator "<<" -> [print in invoice calss]
    friend ostream& operator <<(ostream& out, const Reservation& R);

};


