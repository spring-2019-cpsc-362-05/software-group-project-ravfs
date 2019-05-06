#include "createaccount.h"
#include "ui_createaccount.h"
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <random>

createAccount::createAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createAccount)
{
    ui->setupUi(this);
    ui->lineEdit_lEmail->setEnabled(true);
    ui->lineEdit_locationKey->setDisabled(true);
    ui->lineEdit_locationAddress->setDisabled(true);
    ui->lineEdit_websiteLink->setDisabled(true);
    ui->lineEdit_normalHours->setDisabled(true);
    ui->lineEdit_emergencyHours->setDisabled(true);
    ui->lineEdit_hourlyRate->setDisabled(true);
    ui->lineEdit_baseRate->setDisabled(true);
    ui->textEdit_servicesProvided->setDisabled(true);
}

createAccount::~createAccount()
{
    delete ui;
}

void createAccount::on_pushButton_clicked()
{
    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");
    ravfsdb.open();
    QSqlQuery * qry = new QSqlQuery(ravfsdb);

    QString firstName = ui->lineEdit_firstName->text();
    QString lastName = ui->lineEdit_lastName->text();
    QString email = ui->lineEdit_email->text();
    QString password = ui->lineEdit_password->text();
    QString address = ui->lineEdit_address->text();
    QString phoneNumber = ui->lineEdit_phoneNumber->text();
    QString type;
    QString lEmail;
    QString locationKey;
    QString locationAddress;
    QString website;
    QString normalHours;
    QString emergencyHours;
    QString hourlyRate;
    QString baseRate;
    QString servicesProvided;


    if(ui->tenantButton->isChecked())
    {
        type = "tenant";
        lEmail = ui->lineEdit_lEmail->text();

        qry->prepare("insert into account (firstName,lastName, email, password, Address, phone, type) values "
                     "('" + firstName + "','" + lastName + "','" + email + "','" + password + "','" + address + "','" + phoneNumber + "','" + type + "')");
        qry->exec();
        /*ui->textEdit_servicesProvided->setText("insert into account (firstName,lastName, email, password, Address, phone, type) values "
                                               "('" + firstName + "','" + lastName + "','" + email + "','" + password + "','" + address + "','" + phoneNumber + "','" + type + "')");
        */
        qry->prepare("insert into tenant (tEmail, lEmail ) values"
                     "('" + email + "','" + lEmail + "')");

        qry->exec();

    }
    else if (ui->landlordButton->isChecked())
    {
        type = "landlord";
        if(!ui->lineEdit_locationKey->text().isEmpty())
        {
            locationKey = ui->lineEdit_locationKey->text();
        }
        locationAddress = ui->lineEdit_locationAddress->text();
        qry->prepare("insert into account (firstName,lastName, email, password, Address, phone, type) values "
                     "('" + firstName + "','" + lastName + "','" + email + "','" + password + "','" + address + "','" + phoneNumber + "','" + type + "')");
        qry->exec();

        if(locationKey == "")
        {
            locationKey = QString::number(QRandomGenerator::global()->bounded(10000));

            qry->prepare("insert into location (officeLocation, locationKey) values "
                         "('" + locationAddress + "'," + locationKey + ")");

            qry->exec();

        }

        qry->prepare("insert into landlord (lEmail, locationKey ) values "
                     "('" + email + "'," + locationKey + ")");

        qry->exec();
    }
    else if (ui->spButton->isChecked())
    {
        type = "service provider";
        website = ui->lineEdit_websiteLink->text();
        normalHours = ui->lineEdit_normalHours->text();
        emergencyHours = ui->lineEdit_emergencyHours->text();
        hourlyRate = ui->lineEdit_hourlyRate->text();
        baseRate = ui->lineEdit_baseRate->text();
        servicesProvided = QString(ui->textEdit_servicesProvided->toPlainText());

        qry->prepare("insert into account (firstName, lastName, email, password, Address, phone, type) values "
                     "('" + firstName + "','" + lastName + "','" + email + "','" + password + "','" + address + "','" + phoneNumber + "','" + type + "')");
        qry->exec();

        qry->prepare("insert into serviceprovider (sEmail, website, normalHours, emergencyHours, hourlyRate, baseRate, servicesProvided) values "
                     "('" + email + "','" + website + "','" + normalHours + "','" + emergencyHours + "',"  + hourlyRate +
                     "," + baseRate + ",'" + servicesProvided + "')" );

        qry->exec();
    }

    ravfsdb.close();
}

void createAccount::on_tenantButton_clicked()
{
    ui->lineEdit_lEmail->setEnabled(true);
    ui->lineEdit_locationKey->setDisabled(true);
    ui->lineEdit_locationAddress->setDisabled(true);
    ui->lineEdit_websiteLink->setDisabled(true);
    ui->lineEdit_normalHours->setDisabled(true);
    ui->lineEdit_emergencyHours->setDisabled(true);
    ui->lineEdit_hourlyRate->setDisabled(true);
    ui->lineEdit_baseRate->setDisabled(true);
    ui->textEdit_servicesProvided->setDisabled(true);


}

void createAccount::on_landlordButton_clicked()
{
    ui->lineEdit_lEmail->setDisabled(true);
    ui->lineEdit_locationKey->setEnabled(true);
    ui->lineEdit_locationAddress->setEnabled(true);
    ui->lineEdit_websiteLink->setDisabled(true);
    ui->lineEdit_normalHours->setDisabled(true);
    ui->lineEdit_emergencyHours->setDisabled(true);
    ui->lineEdit_hourlyRate->setDisabled(true);
    ui->lineEdit_baseRate->setDisabled(true);
    ui->textEdit_servicesProvided->setDisabled(true);
}

void createAccount::on_spButton_clicked()
{
    ui->lineEdit_lEmail->setDisabled(true);
    ui->lineEdit_locationKey->setDisabled(true);
    ui->lineEdit_locationAddress->setDisabled(true);
    ui->lineEdit_websiteLink->setEnabled(true);
    ui->lineEdit_normalHours->setEnabled(true);
    ui->lineEdit_emergencyHours->setEnabled(true);
    ui->lineEdit_hourlyRate->setEnabled(true);
    ui->lineEdit_baseRate->setEnabled(true);
    ui->textEdit_servicesProvided->setEnabled(true);
}
