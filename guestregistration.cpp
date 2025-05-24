#include "guestregistration.h"

GuestRegistration::GuestRegistration(Person a, QString q)
    :Registration(a), m_Catergory(q)
{

}

double GuestRegistration::calculateFee()
{
    return STANDARD_FEE*0.10;

}

QString GuestRegistration::toString()
{
    return QString("Fee: %1")
        .arg(STANDARD_FEE);

}
