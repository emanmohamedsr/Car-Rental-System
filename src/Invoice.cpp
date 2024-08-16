#include "Invoice.h"

Invoice::Invoice()
{
}

Invoice::Invoice(Car car, Customer customer,double taxes, float rentalRate, double insuranceCharges, int start, int end)
{
	//car
	C1 = car;
	//customer
	C2 = customer;
	//reservation 
	R1.setstartDate(start);
	R1.setendDate(end);
	//rental agreement
	R2.set_period(start, end);
	//if start was 12  the period will be negative so we will add to it [12]
	//start=12 | end=2 | period=-10
	(R2.getPeriod() < 0 ? R2.set_period(start, end + 12) : R2.set_period(start, end));
	R2.set_rentalRate(rentalRate);
	R2.set_insuranceCharges(insuranceCharges);
	//invoice
	m_taxes = taxes;
	m_rentalCharges = rentalRate * (end - start);//rate*period
	m_totalDue = m_rentalCharges + insuranceCharges + taxes;
}



int Invoice::getReservationID()
{
	return C1.getCarId();
}

int Invoice::getRESstart()
{
	return R1.getstarDate();
}

int Invoice::getRESend()
{
	return R1.getendDate();
}

double Invoice::getTotalamount()
{
	return m_totalDue;
}

void Invoice::operator-=(double x)
{
	   this->m_totalDue -= x;
}



ostream& operator<<(ostream& out, const Invoice& i)
{
	//car
	out << i.C1;
	//rental information
	out << "->** rental information ....  " << endl;
	out << i.R1; //          reservation class               start , end
	out << i.R2; //       rental agreement class      period, rental rate, insurance
	out << "Renatl charges : " << i.m_rentalCharges << endl;
	out << "Taxes : " << i.m_taxes << endl;
	out << "Total amount due : " << i.m_totalDue << endl;
	//customer
	out << i.C2;
	return out;
}


