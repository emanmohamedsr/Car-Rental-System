#include "Car.h"
//default constructor
Car::Car() : Available(true), m_carID(0), m_model("Null"), m_make("Null"), m_year(0) {}
Car::Car(int carID, string model, string make, int year, bool available) :m_carID(carID), m_model(model), m_make(make), m_year(year), Available(available)
{
}
//set availability
void Car::setAvailability(bool b)
{
    Available = b;
}
//check availability
bool Car::getAvailability() const
{
    return Available;
}
//to search for car in car list array
int Car::getCarId() const
{
    return m_carID;
}
//overload operator "<<"
ostream& operator<<(ostream& out, const Car& c1)
{
    out << "The Car information...\n"
        << "ID: " << c1.m_carID << "\nModel: " << c1.m_model << "\nMake: " << c1.m_make
        << "\nYear: " << c1.m_year << "\nAvailability: " << (c1.Available==1?"Yes":"No") << endl;

    return out;
}
//overlad operator ">>"
istream& operator>>(istream& in, Car& c1)
{
    cout << "Enter car information .... \n"
        << "ID : ";
    in >> c1.m_carID;
    cout << "Model : ";
    in >> c1.m_model;
    cout << "Make : ";
    in >> c1.m_make;
    cout << "Year : ";
    in >> c1.m_year;

    return in;
}
