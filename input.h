#ifndef INPUT_H
#define INPUT_H

#include <QDialog>
#include <QObject>
#include "person.h"
#include "registration.h"
#include "registrationfactory.h"

class QPushButton;
class QLineEdit;
class QTextEdit;
class QComboBox;
class QDateEdit;
class Person;

class Input : public QDialog
{
    Q_OBJECT
public:
    Input();
    ~Input();
    Person getPerson() const;
    //Registration getRegistration() const;
private slots:
    void processInput();
private:
    void setupGUI();
    Person person;
    RegistrationFactory factory;
    QLineEdit *edtName;
    QLineEdit *edtEmailAddress;
    QLineEdit *edtAffiliation;
    QLineEdit *edtQualification;
    QDateEdit *edtDate;
    QPushButton *buttnSubmit;
    QPushButton *buttnClose;
    QComboBox *edtType;
};

#endif // INPUT_H
