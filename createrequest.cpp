#include "createrequest.h"
#include "ui_createrequest.h"

createRequest::createRequest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createRequest)
{
    ui->setupUi(this);
}

createRequest::~createRequest()
{
    delete ui;
}

void createRequest::setEmail(QString acctEmail)
{
    email = acctEmail;
}

void createRequest::setUpSPTable()
{

    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");
    ravfsdb.open();

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(ravfsdb);

    qry->prepare("select s.* from serviceprovider s, tenant t, landlord l, locationtoserviceprovider losp"
                 " where t.tEmail = '" + email + "' AND t.lEmail = l.lEmail AND l.locationKey = losp.locationKey AND losp.spEmail = s.sEmail");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView->setModel(model);

    ravfsdb.close();

}

void createRequest::on_pushButton_clicked()
{
    QString requestID = QString::number(QRandomGenerator::global()->bounded(10000));
    QString kindOFService = ui->lineEdit_kindOFService->text();
    QString assignedProvider = ui->lineEdit_assignedProvider->text();
    QString notes = ui->textEdit_notes->toPlainText();
    QString current = QDateTime::currentDateTime().toString();

    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");
    ravfsdb.open();

    QSqlQuery * qry = new QSqlQuery(ravfsdb);
    if(ui->radioButton->isChecked() == true)
    {
        qry->prepare("insert into request (requestID, tEmail, kindOfService, assignedProvider, notes, flagEorNoE, timeRequested) values "
                     "(" + requestID + ",'" + email + "','" + kindOFService + "','" + assignedProvider + "','" + notes + "', 1,'" + current + "')");
    }
    else
    {
        qry->prepare("insert into request (requestID, tEmail, kindOfService, assignedProvider, notes, flagEorNoE, timeRequested) values "
                     "(" + requestID + ",'" + email + "','" + kindOFService + "','" + assignedProvider + "','" + notes + "', 0,'" + current +"')");
    }
    qry->exec();


    ravfsdb.close();

}

void createRequest::on_pushButton_2_clicked()
{

}
