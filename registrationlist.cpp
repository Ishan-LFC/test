#include "registrationlist.h"
#include "person.h"
#include <QMessageBox>
#include <QMetaObject>

RegistrationList::RegistrationList()
{

}

void RegistrationList::addRegistration(Registration *r)
{
    const QMetaObject* meta = r->metaObject();//Inherits from Object - Registration
    //QString className = QString(meta->className());
    if (QString(meta->className()) == "Registration")
        m_AttendeeList.append(r);
    if (QString(meta->className()) == "Guest")
        listGuest.append(r);
    if (QString(meta->className()) == "Student")
        listStudent.append(r);

}

//returns a string representation of the entire booking list
QString RegistrationList::toString()
{
    QString result;
    foreach (Registration * r, m_AttendeeList)
    {
        result.append(r->toString());
        result.append("\n--\n");
    }
    return result;
}

QList<Registration *> RegistrationList::getList(QString type) const
{
    if(type == "Registration")
        return m_AttendeeList;
    if (type == "Guest")
        return listGuest;
    if (type == "Student")
        return listStudent;
    return QList<Registration*>();
}


//Determine if two names are the same
void RegistrationList::testRegistration(Registration *r)
{
    foreach(Registration* t, m_AttendeeList)
    {
        if(!(t->getAttendee().getEmail() == t->getAttendee().getEmail()))
            QMessageBox::information(0, "This Email already Exists","This Email already Exists");
        if(!(t->getAttendee().getName() == t->getAttendee().getName()))
            QMessageBox::information(0, "This Name already Exists","This Name already Exists");
        m_AttendeeList.append(t);
    }

}

RegistrationList::~RegistrationList()
{
    qDeleteAll(m_AttendeeList);

}

//Determine if is person is already registered
bool RegistrationList::isRegistered(QString n)
{
    foreach(Registration* a, m_AttendeeList)
    {
        if(a->getAttendee().getName() == n)
            return true;
    }
    return false;
}

//Calculate total fee
double RegistrationList::totalFee(QString t)
{
    double total = 0;
    QString type;
    foreach(Registration* r, m_AttendeeList)
    {
        if(type == "Registration")
            total += r->calculateFee();
        QMessageBox::information(0, "Fee calculated", "Fee calculated" );
        if(type == "StudentRegistration")
            total += r->calculateFee();
        QMessageBox::information(0, "Fee calculated", "Fee calculated" );
        if(type == "GuestRegistration")
            total += r->calculateFee();
        QMessageBox::information(0, "Fee calculated", "Fee calculated" );
    }
    return total;
}

//Count total registrations
int RegistrationList::totalregistrations(QString a)
{
    int count = 0;
    QString type;
    foreach(Registration* r, m_AttendeeList)
    {
        if(type == "Registration")
            count++;
        if(type == "StudentRegistration")
            count++;
        if(type == "GuestRegistration")
            count++;
    }
    return count;
}
