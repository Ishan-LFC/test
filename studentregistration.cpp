#include "studentregistration.h"

StudentRegistration::StudentRegistration(Person a, QString q)
    :Registration(a), m_Qualification(q)
{

}

double StudentRegistration::calculateFee()
{
    return STANDARD_FEE/2;
}

//Add qualification
QString StudentRegistration::toString()
{
    return Registration::toString().append("Qualification: ").append(m_Qualification);

}


