#include "registrationlistxmlstreamreader.h"
#include <QFile>
#include <QString>

RegistrationListXmlStreamReader::RegistrationListXmlStreamReader()
{

}

RegistrationListXmlStreamReader::~RegistrationListXmlStreamReader()
{

}

QList<Registration*> RegistrationListXmlStreamReader::readXML(QString f)
{
    //parse file
    QFile file(f);
    file.open(QIODevice::ReadOnly);
    reader.setDevice(&file);

    while (!reader.atEnd())
    {
        QXmlStreamReader::TokenType tType = reader.readNext();
        switch (tType)
        {
        case QXmlStreamReader::StartElement:
        {
            if (reader.name().toString()=="Registration")
            {
                QXmlStreamAttributes attributexml = reader.attributes();
                RegistrationDetail << attributexml.value("Type").toString();
            }
            else if (reader.name().toString()=="Student" || reader.name().toString()=="Guest")
            {
                QXmlStreamAttributes attributexml = reader.attributes();
                RegistrationDetail << attributexml.value("Name").toString();
                RegistrationDetail << attributexml.value("Email").toString();
                RegistrationDetail << attributexml.value("Affilaition").toString();
                RegistrationDetail << attributexml.value("Date").toString();
            }
        }
        }
    }
    file.close();

    return RegistrationList;
}
