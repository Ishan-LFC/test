#include "input.h"
#include "person.h"
#include "registration.h"
#include "studentregistration.h"
#include "registrationfactory.h"
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QDateEdit>
#include <QVBoxLayout>

Input::Input()
    : edtName(new QLineEdit),
    edtEmailAddress(new QLineEdit),
    edtAffiliation(new QLineEdit),
    edtType(new QComboBox),
    edtQualification(new QLineEdit),
    edtDate(new QDateEdit),
    buttnSubmit(new QPushButton("Submit")),
    buttnClose(new QPushButton("Close"))
{
    // Setup GUI
    setupGUI();

    // Connect Signals and Slots
    connect(buttnSubmit, &QPushButton::clicked, this, &Input::processInput);
    connect(buttnSubmit, &QPushButton::clicked, this, &Input::accept);
    connect(buttnClose, &QPushButton::clicked, this, &Input::reject);
    connect(buttnClose, &QPushButton::clicked, this, &QWidget::close);

    // Setup window
    setWindowTitle("Add Person");
    setMinimumSize(400, 300);
}

Input::~Input()
{

}

//Process
void Input::processInput()
{

   //FACTORY METHOD
   Registration *reg = factory.fact(edtType->currentText(), person, edtEmailAddress->text());
    if(reg != nullptr)
   {
       reg->getAttendee();
   }

   person.setName(edtName->text());
   person.setEmail(edtEmailAddress->text());
   person.setAffiliation(edtAffiliation->text());
   person.setQualification(edtQualification->text());
   person.setDate(edtDate->dateTime());

}

Person Input::getPerson() const
{
    return person;
}

//Gui setup
void Input::setupGUI()
{
    //Types declared
    edtType->addItem("Standard");
    edtType->addItem("RegisteredStudent");
    edtType->addItem("Guest");

    // Declare widgets
    QVBoxLayout *layout(new QVBoxLayout(this));
    QLabel *lblName(new QLabel("Name"));
    QLabel *lblEmailAddress(new QLabel("Email Address"));
    QLabel *lblAffiliation(new QLabel("Affiliation"));
    QLabel *lblQualification(new QLabel("Qualification"));
    QLabel *lblDate(new QLabel("Date"));
    QLabel *lblType(new QLabel("Type"));
    edtDate = new QDateEdit(QDate::currentDate());

    // Setup layout
    layout->addWidget(lblName);
    layout->addWidget(edtName);
    layout->addWidget(lblEmailAddress);
    layout->addWidget(edtEmailAddress);
    layout->addWidget(lblAffiliation);
    layout->addWidget(edtAffiliation);
    layout->addWidget(lblQualification);
    layout->addWidget(edtQualification);
    layout->addWidget(lblDate);
    layout->addWidget(edtDate);
    layout->addWidget(lblType);
    layout->addWidget(edtType);
    layout->addSpacing(10);
    layout->addWidget(buttnSubmit);
    layout->addWidget(buttnClose);
}
