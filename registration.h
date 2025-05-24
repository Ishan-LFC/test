#ifndef REGISTRATION_H
#define REGISTRATION_H
#include "person.h"
#include <QDate>
#include <QObject>
#include <QMetaObject>
//class Person; - Called a forward class declaration

class Registration : QObject
{
    Q_OBJECT //FOR QmetaObject
public:
    Registration(Person a);
    const double STANDARD_FEE = 250;
    Person getAttendee() const;
    QDate getBookingDate() const;
    void setBookingDate(QDate d);
    void setAttendee(Person a);
    virtual double calculateFee()const; //Polymorphism - virtual
    virtual QString toString() const; //Anything that doesnt change member variables are const
private:
    Person m_Attendee;
    QDate m_BookingDate;
};

#endif // REGISTRATION_H

