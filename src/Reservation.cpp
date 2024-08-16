#include "Reservation.h"

Reservation::Reservation() :m_startDate(0), m_endDate(0) {}

void Reservation::setstartDate(int s)
{
    m_startDate = s;
}


void Reservation::setendDate(int e)
{
    m_endDate = e;
}

int Reservation::getstarDate()
{
    return m_startDate;
}

int Reservation::getendDate()
{
    return m_endDate;
}

ostream& operator<<(ostream& out, const Reservation& R)
{
    out << "Reservation date is [" << R.m_startDate << ":" << R.m_endDate << "]\n";
    return out;
}