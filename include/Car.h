#pragma once

#include <string>
#include <iostream>
using namespace std;
class Car {
private:
    //data of each car
    int m_carID;
    string m_model;
    string m_make;
    int m_year;
    bool Available;
    
    
   
    
   
public:
    //give intial value
    Car();
    Car(int id,string model,string make,int year,bool avalaible);
    //set availadility -> to change availability if car is taken  
    void setAvailability(bool);
    //get availadility -> to check
    bool getAvailability() const;
    //get car id -> to search a car
    int getCarId()const;
    //overlaod operators "<<" & ">>"
    friend ostream& operator<<(ostream& out, const Car& c1);
    friend istream& operator>>(istream& in, Car& c1);

};

