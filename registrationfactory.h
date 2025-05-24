#ifndef REGISTRATIONFACTORY_H
#define REGISTRATIONFACTORY_H
#include "registration.h"
#include "person.h"
#include "studentregistration.h"
#include "guestregistration.h"

class RegistrationFactory
{
public:
    RegistrationFactory();
    Registration* fact(QString details, Person p, QString q);
};
#endif // REGISTRATIONFACTORY_H
