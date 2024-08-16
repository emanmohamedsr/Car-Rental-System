#pragma once
#include <iostream>
using namespace std;

#include "Reservation.h" 

class RentalAgreement
{
private:
	int m_period;
	float m_rentalRate;
	double m_insuranceCharges;
public:
	RentalAgreement();

	void set_period(int,int);
	void set_rentalRate(float);
	void set_insuranceCharges(double);

	int getPeriod();

	 
	friend ostream& operator<<(ostream& out, const RentalAgreement& R2);
};

