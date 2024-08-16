#include "RentalAgreement.h"

RentalAgreement::RentalAgreement():m_period(0), m_rentalRate(0.0), m_insuranceCharges(0.0){}

void RentalAgreement::set_period(int s, int e)
{
    m_period = e - s;
}

void RentalAgreement::set_rentalRate(float r)
{
    m_rentalRate = r;
}

void RentalAgreement::set_insuranceCharges(double i)
{
    m_insuranceCharges = i;
}

int RentalAgreement::getPeriod()
{
    return m_period;
}

ostream& operator<<(ostream& out, const RentalAgreement& R2)
{
    out << "Rental period is (" << R2.m_period << ") hours\n";
    out << "Rental rate : " << R2.m_rentalRate
        << "\nIncurance charges : " << R2.m_insuranceCharges << endl;
    return out;
}