#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <QDate>
class QDateEdit;

class Person
{
public:
    Person();
    Person(QString n, QString a, QString e, QString q, QDateTime d);
    QString getName() const;
    void setName(QString n);
    void setAffiliation(QString a);
    void setEmail(QString e);
    QDateTime getDate() const;
    void setDate(QDateTime d);
    QString toString() const;
    QString getAffiliation() const;
    QString getEmail() const;
    QString getQualification() const;
    void setQualification(QString q);
private:
    QString m_Name;
    QString m_Affiliation;
    QString m_Qualification;
    QString m_Email;
    QDateTime m_Date;
};

#endif // PERSON_H
