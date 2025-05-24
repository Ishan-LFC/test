#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H
#include <QList>
#include "registration.h"

class RegistrationList
{
public:
    RegistrationList();
    void addRegistration(Registration* r);
    void testRegistration(Registration* r);
    ~RegistrationList();
    bool isRegistered(QString n);
    double totalFee(QString t);
    int totalregistrations(QString a);
    QString toString();
    QList<Registration*> getList(QString type) const;
private:
    QList<Registration*> m_AttendeeList;
    QList<Registration*> listGuest;
    QList<Registration*> listStudent;
};

#endif // REGISTRATIONLIST_H
