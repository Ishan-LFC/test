#ifndef GUESTREGISTRATION_H
#define GUESTREGISTRATION_H
#include "registration.h"

class GuestRegistration : public Registration
{
public:
    GuestRegistration(Person a, QString q);
    double calculateFee();
    QString toString();
private:
    QString m_Catergory;
};

#endif // GUESTREGISTRATION_H
