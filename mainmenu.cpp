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
    actEmail = acctEmail;
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
    viewReq.setRequestTable(actEmail, type);
    viewReq.show();
}

void mainMenu::on_pushButton_createReq_clicked()
{
    crtReq.setEmail(actEmail);
    crtReq.setUpSPTable();
    crtReq.show();
}

void mainMenu::on_pushButton_viewTenants_clicked()
{
    viewTen.setUpEmail(actEmail);
    viewTen.setUpTable();
    viewTen.show();
}

void mainMenu::on_pushButton_viewClaims_clicked()
{
    viewClms.setEmail(actEmail);
    viewClms.setType(type);
    viewClms.setUpTable();
    viewClms.show();
}

void mainMenu::on_pushButton_acctSettings_clicked()
{
    udtAct.setEmail(actEmail);
    udtAct.setType(type);
    udtAct.setUpPage();
    udtAct.show();
}
