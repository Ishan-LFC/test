#include "registrationfactory.h"

RegistrationFactory::RegistrationFactory()
{

}

Registration *RegistrationFactory::fact(QString details, Person p, QString q)
{
    if(details == "Registration")
        return new Registration(p);
    if(details == "Student Registration")
        return new StudentRegistration(p, q);
    if(details == "Guest Registration")
        return new GuestRegistration(p, q);

    return nullptr;
}
