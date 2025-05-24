#ifndef REGISTRATIONLISTXMLSTREAMREADER_H
#define REGISTRATIONLISTXMLSTREAMREADER_H
#include <QList>
#include <QXmlStreamReader>
#include <QStringList>
class Registration;
class Person;

class RegistrationListXmlStreamReader
{
public:
    RegistrationListXmlStreamReader();
    ~RegistrationListXmlStreamReader();
    QList<Registration*> readXML(QString fXml);
private:
    QXmlStreamReader reader;
    QList<Registration*> RegistrationList;
    QStringList RegistrationDetail;
};
#endif // REGISTRATIONLISTXMLSTREAMREADER_H
