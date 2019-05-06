#include "updateaccount.h"
#include "ui_updateaccount.h"

updateAccount::updateAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updateAccount)
{
    ui->setupUi(this);
}

void updateAccount::setEmail(QString actEmail)
{
    email = actEmail;
    ui->label_email->setText("Email : " + email);
}

void updateAccount::setType(QString actType)
{
    type = actType;
    ui->label_accountType->setText("Account Type : " + type);
}

void updateAccount::setUpPage()
{
    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");
    ravfsdb.open();
    QSqlQueryModel rec;

    rec.setQuery("select * from account a where a.email = '" + email + "'");
    ui->lineEdit_firstName->setText(rec.record(0).value("firstName").toString());
    ui->lineEdit_lastName->setText(rec.record(0).value("lastName").toString());
    ui->lineEdit_phone->setText(rec.record(0).value("phone").toString());
    ui->lineEdit_address->setText(rec.record(0).value("address").toString());

    if(type == "tenant")
    {
        rec.setQuery("select l.* from landlord l, tenant t where t.tEmail = '" + email + "' AND t.lEmail = l.lEmail");
        ui->label_locationKey->setText("Location Key : " + rec.record(0).value("locationKey").toString());
        ui->lineEdit_register->setDisabled(true);
        ui->pushButton_register->setDisabled(true);
    }
    else if (type == "landlord")
    {
        rec.setQuery("select * from landlord l where l.lEmail = '" + email + "'");
        ui->label_locationKey->setText("Location Key : " + rec.record(0).value("locationKey").toString());
        ui->lineEdit_register->setDisabled(true);
        ui->pushButton_register->setDisabled(true);
    }
    else if(type == "service provider")
    {
        ui->label_locationKey->setText("");
        ui->lineEdit_register->setEnabled(true);
        ui->pushButton_register->setEnabled(true);
    }

    ravfsdb.close();

}

updateAccount::~updateAccount()
{
    delete ui;
}

void updateAccount::on_pushButton_update_clicked()
{
    QString firstName = ui->lineEdit_firstName->text();
    QString lastName = ui->lineEdit_lastName->text();
    QString phone = ui->lineEdit_phone->text();
    QString address = ui->lineEdit_address->text();

    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");
    ravfsdb.open();
    QSqlQuery * qry = new QSqlQuery(ravfsdb);
    qry->prepare("update account set firstName = '" + firstName + "', lastName = '" + lastName + "', phone = '" + phone + "', address = '" + address + "' "
                  "where email = '" + email + "'");
    qry->exec();
    ravfsdb.close();
}

void updateAccount::on_pushButton_register_clicked()
{
    QString locationKey = ui->lineEdit_register->text();
    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");
    ravfsdb.open();
    QSqlQuery * qry = new QSqlQuery(ravfsdb);
    qry->prepare("insert into locationtoserviceprovider (spEmail, locationKey) values ('" + email + "'," + locationKey + ")");
    qry->exec();
    ravfsdb.close();

}
