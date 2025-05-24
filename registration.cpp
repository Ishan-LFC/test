#include "registration.h"

Registration::Registration(Person a)
    : m_Attendee(a)
{

}

Person Registration::getAttendee() const
{
    return m_Attendee;
}

QDate Registration::getBookingDate() const
{
    return m_BookingDate;
}

void Registration::setBookingDate(QDate d)
{
    m_BookingDate = d;
}

void Registration::setAttendee(Person a)
{
    m_Attendee = a;
}

double Registration::calculateFee() const
{
    return STANDARD_FEE;
}

//Displa info
QString Registration::toString() const
{
    return QString("Attendee: %1, BookingDate: %2")
        //.arg(m_Attendee)
        .arg(m_BookingDate.toString());

}
