#include "Customer.h"

Customer::Customer() 
{
    m_phoneNumber = "Null"; 
    m_address = "Null";
    m_customerName= "Null";
}

Customer::~Customer()
{
}

ostream& operator<<(ostream& out, const Customer& c)
{
    out << "The customer information ... "
        << "\n*Name : " << c.m_customerName
        << "\n*Address : " << c.m_address
        << "\n*Phone Number : "<<c.m_phoneNumber;
    

    return out;
}

istream& operator>>(istream& in, Customer& c)
{
    cout << "Enter customer information ... "
        << "\n*Name : ";
    in >> c.m_customerName;
    cout << "*Address : ";
    in >> c.m_address;
    cout << "Phone Number : ";
    in >> c.m_phoneNumber;
    return in;

}