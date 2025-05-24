#include "registrationlistwriter.h"
#include <QFile>
#include <QTextStream>

RegistrationListWriter::RegistrationListWriter(QString fn): fileName(fn)
{

}

void RegistrationListWriter::write(QString s) const
{
    QFile file(fileName);
    file.open(QIODevice::ReadWrite);
    QTextStream toFile(&file);
    toFile << s;
    file.close();
}
