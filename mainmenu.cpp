#include "mainmenu.h"
#include "ui_mainmenu.h"

mainMenu::mainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainMenu)
{
    ui->setupUi(this);
}


mainMenu::~mainMenu()
{
    delete ui;
}

void mainMenu::setEmail(QString acctEmail)
{
    email = acctEmail;
}

void mainMenu::setType(QString acctType)
{
    type = acctType;
}

void mainMenu::setUpMainPage()
{
    if(type == "tenant")
    {
        ui->pushButton_createReq->setEnabled(true);
        ui->pushButton_viewTenants->setDisabled(true);
    }
    else if(type == "landlord")
    {
        ui->pushButton_createReq->setDisabled(true);
        ui->pushButton_viewTenants->setEnabled(true);
    }
    else
    {
        ui->pushButton_createReq->setDisabled(true);
        ui->pushButton_viewTenants->setDisabled(true);
    }
}

void mainMenu::on_pushButton_viewReq_clicked()
{
    viewReq.setRequestTable(email, type);
    viewReq.show();
}
