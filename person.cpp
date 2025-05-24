#include "person.h"

Person::Person()
{

}

Person::Person(QString n, QString a, QString e, QString q, QDateTime d)
    :m_Name(n), m_Affiliation(a), m_Email(e), m_Qualification(q), m_Date(d)
{

}

QString Person::getAffiliation() const
{
    return m_Affiliation;
}

QString Person::getEmail() const
{
    return m_Email;
}

QString Person::getName() const
{
    return m_Name;
}

void Person::setName(QString n)
{
    m_Name = n;
}

void Person::setAffiliation(QString a)
{
    m_Affiliation = a;
}

void Person::setEmail(QString e)
{
    m_Email = e;
}

QDateTime Person::getDate() const
{
    return m_Date;
}

void Person::setDate(QDateTime d)
{
    m_Date = d;
}

QString Person::getQualification() const
{
    return m_Qualification;
}

void Person::setQualification(QString q)
{
    m_Qualification = q;
}

QString Person::toString() const
{
    return QString("Name: %1, Affiliation: %2, Email: %3, Qualification: %4, Date: %5")
        .arg(m_Name, m_Affiliation, m_Email, m_Qualification, m_Date.toString());
        //.arg(m_Affiliation)
        //.arg(m_Email)
        //.arg(m_Qualification)
        //.arg(m_Date.toString());
}
