#ifndef REGISTRATIONLISTXML_H
#define REGISTRATIONLISTXML_H

#include <QString>
#include <QDomDocument>
#include <QDate>
#include <QList>
#include "registrationlist.h"

class RegistrationList;
class Person;
class Registration;

class RegistrationListXML
{
public:
    RegistrationListXML();
    QString write(QList<Registration*> list);
private:
    QDomDocument DOMdoc;
    QDomElement rootElement;
    void writePerson(QDomElement element, QString type, Person *p);
};

#endif // REGISTRATIONLISTXML_H
