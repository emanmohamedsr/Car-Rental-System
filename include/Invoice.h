#pragma once

#include "RentalAgreement.h"

class Invoice
{
private:
	double m_rentalCharges{};
	double m_totalDue{};
	double m_taxes{};

	Car C1;
	Customer C2;
	Reservation R1;
	RentalAgreement R2;
public:
	Invoice();
	Invoice(Car car, Customer customer, double taxes, float rentalRate, double insuranceCharges, int start, int end);

	int getReservationID();
	//to check period
	int getRESstart();
	int getRESend();

	double getTotalamount();

	void operator-=(double x);
	friend ostream& operator<<(ostream& out, const Invoice& i);
	
};

