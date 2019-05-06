#include "viewclaims.h"
#include "ui_viewclaims.h"

viewClaims::viewClaims(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewClaims)
{
    ui->setupUi(this);
}

void viewClaims::setEmail(QString actEmail)
{
    email = actEmail;
}

void viewClaims::setType (QString acctType)
{
    type = acctType;
    if(type != "service provider")
    {
        ui->lineEdit->setDisabled(true);
        ui->pushButton_pay->setDisabled(true);
    }
    else
    {
        ui->lineEdit->setEnabled(true);
        ui->pushButton_pay->setEnabled(true);
    }
}

void viewClaims::setUpTable()
{
    QString claimID = ui->lineEdit->text();
    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");
    ravfsdb.open();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(ravfsdb);

    if(type == "tenant")
    {
        qry->prepare("select a.firstName, a.lastName, a.email, a.address, a.phone, r.assignedProvider, c.* from account a, claim c, request r where c.requestID = r.requestID "
                     "AND r.tEmail = a.email AND a.email = '" + email + "'");

    }
    else if(type == "landlord")
    {
        qry->prepare("select a.firstName, a.lastName, a.email, a.address, a.phone, r.assignedProvider, c.* from account a, claim c, tenant t, request r where c.requestID = r.requestID "
                             "AND r.tEmail = t.tEmail AND t.tEmail = a.email AND t.lEmail = '" + email + "'");


    }
    else if(type == "service provider")
    {
        qry->prepare("select a.firstName, a.lastName, a.email, a.address, a.phone, r.assignedProvider, c.* from account a, claim c, request r where c.requestID = r.requestID "
                             "AND r.tEmail = a.email AND r.assignedProvider = '" + email + "'");

    }

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    ravfsdb.close();
}

viewClaims::~viewClaims()
{
    delete ui;
}

void viewClaims::on_pushButton_pay_clicked()
{
    QString claimID = ui->lineEdit->text();
    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");
    ravfsdb.open();
    QSqlQuery * qry = new QSqlQuery(ravfsdb);

    qry->prepare("update claim set claimStatus = 1 where claimID = " + claimID);
    qry->exec();
    setUpTable();
    ravfsdb.close();
    ui->lineEdit->setText("");

}
