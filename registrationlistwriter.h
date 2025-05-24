#ifndef REGISTRATIONLISTWRITER_H
#define REGISTRATIONLISTWRITER_H
#include <QString>

class RegistrationListWriter{
public:
    RegistrationListWriter(QString fn);
    void write(QString s) const;
private:
    QString fileName;
};

#endif // REGISTRATIONLISTWRITER_H
