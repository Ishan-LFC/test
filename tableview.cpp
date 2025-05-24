#include "tableview.h"
#include "input.h"
#include "person.h"
#include "registration.h"
#include "registrationlist.h"
#include "registrationlistwriter.h"
#include "registrationlistxml.h"
#include "registrationlistxmlstreamreader.h"
#include <QTableView>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QCloseEvent>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>

Tableview::Tableview(QWidget *parent)
    : QWidget(parent),
    txtDisplay(new QTextEdit),
    btnAdd(new QPushButton("Add Factory Method Registration")),
    btnExit(new QPushButton("Exit")),
    file_b(new QPushButton("Save To Xml file")),
    file_c(new QPushButton("Read From Xml file"))
{
    // SetupGUI
    setupGUI();

    // Connect Signals and Slots
    connect(btnAdd, SIGNAL(clicked()), this, SLOT(addPerson()));
    connect(btnExit, SIGNAL(clicked()), this, SLOT(close()));
    connect(file_b, SIGNAL(clicked()), this, SLOT(saveFile()));
    connect(file_c, SIGNAL(clicked()), this, SLOT(readFromFile()));

    // Set up window
    setWindowTitle("Registration");
    setMinimumSize(800, 300);
}

void Tableview::addPerson()
{      
    Input newPer;
    QTextStream cout(stdout);

    newPer.exec();

    if (newPer.result() == QDialog::Accepted)
    {
        txtDisplay->append(newPer.getPerson().toString());
        QMessageBox::information(0, "Registration Added", "Registration Added");
    }
    else {
        cout << "Dialog closed, No Registration data available" << Qt::endl;
    }
}

void Tableview::readFromFile()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file", ".", "XML files (*.xml)");

    if (filename.size() > 0)
    {
        RegistrationListXmlStreamReader *readXML(new RegistrationListXmlStreamReader);
        QList<Registration*> temp = readXML->readXML(filename);
        foreach(Registration* b, temp)
            registrationLists;
        //registrationLists->addPerson(b);
        delete readXML;
        QMessageBox::information(this, "Read/Append from file", "Registration list read from file");
    }
    else
        QMessageBox::information(this, "Read/Append from file", "Registration list not read from file");
}

void Tableview::saveFile()
{

    QString filename = QFileDialog::getSaveFileName(this, "Save as", ".", "XML files (*.xml)");

    if (filename.size() > 0)
    {
        RegistrationListXML writer;
        QString xml = writer.write(registrationLists);

        RegistrationListWriter fw(filename);
        fw.write(xml);
    }
    QMessageBox::information(this, "Saved to file", "Saved to file");
}

void Tableview::closeEvent(QCloseEvent *event)
{
    int response;
    response = QMessageBox::warning(this, "Exit", "Are you sure you want to Exit ?",
                                    QMessageBox::Yes | QMessageBox::No);
    if (response == QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

//Layout for table view
void Tableview::setupGUI()
{
    // Setup layout
    QVBoxLayout *layout(new QVBoxLayout(this));
    layout->addWidget(txtDisplay);
    layout->addWidget(btnAdd);
    layout->addWidget(file_b);
    layout->addWidget(file_c);
    layout->addWidget(btnExit);

    // Initialize widgets
    txtDisplay->setReadOnly(true);
}
