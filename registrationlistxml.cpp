#include "registrationlistxml.h"
#include "tableview.h"
#include "input.h"
#include "registrationlist.h"
#include "person.h"
#include "registration.h"
#include <QString>

RegistrationListXML::RegistrationListXML()
{

}

QString RegistrationListXML::write(QList<Registration*> list)
{

    const QMetaObject* meta;

    rootElement = DOMdoc.createElement("Registration");
    DOMdoc.appendChild(rootElement);

    QDomDocument doc;
    QDomElement rootElement;
    rootElement = doc.createElement("Registration"); //Display with doc.toString
    doc.appendChild(rootElement);

    //foreach(Registration* reg, list)
    //{
    QString className = "";
    QDomElement regElement = doc.createElement("Registration");

    rootElement.appendChild(regElement);
    regElement.setAttribute("Type", className);

    QDomElement attElement = doc.createElement("Attendee");
    regElement.appendChild(attElement);
    Person person; //reg->getAttendee();

    //QDomDocument doc;
    QDomElement nameElement = doc.createElement("Name");
    QString name1 = person.getName();

    QDomText nameText = doc.createTextNode(name1);
    nameElement.appendChild(nameText);
    doc.appendChild(nameElement);

    //writePerson(nameElement, "contact", p.getName());

    QDomElement affiliationElement = doc.createElement("Affiliation");
    attElement.appendChild(affiliationElement);

    QDomText affiliationText = doc.createTextNode(person.getAffiliation());
    affiliationElement.appendChild(affiliationText);

    QDomElement emailElement = doc.createElement("Email");
    attElement.appendChild(emailElement);

    QDomText emailText = doc.createTextNode(person.getEmail());
    emailElement.appendChild(emailText);

    QDomElement dateElement = doc.createElement("Date");
    attElement.appendChild(dateElement);

    QDomText dateText = doc.createTextNode(person.getDate().toString());
    dateElement.appendChild(dateText);

    //}
    //return DOMdoc.toString();
    return doc.toString();
}

void RegistrationListXML::writePerson(QDomElement element, QString type, Person *p)
{
    QDomElement personElement = DOMdoc.createElement(type);
    personElement.setAttribute("Email", p->getEmail());
    personElement.setAttribute("Name", p->getName());
    personElement.setAttribute("Affiliation", p->getAffiliation());
    element.appendChild(personElement);

}
