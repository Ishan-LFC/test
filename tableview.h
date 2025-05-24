#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>
#include "registrationlist.h"
#include "registrationlistxml.h"
class QPushButton;
class QTextEdit;
class CustomerList;
class QPushButton;
class QTableView;
class Registration;

class Tableview : public QWidget
{
    Q_OBJECT
public:
    explicit Tableview(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event);
public slots:
              //void addPerson();
private slots:
    void addPerson();
    void saveFile();
    void readFromFile();
private:
    void setupGUI();
    QList<Registration*> registrationLists;
    QTextEdit *txtDisplay;
    QPushButton *btnAdd;
    QPushButton *btnExit;
    QPushButton *file_b;
    QPushButton *file_c;
};

#endif // TABLEVIEW_H
