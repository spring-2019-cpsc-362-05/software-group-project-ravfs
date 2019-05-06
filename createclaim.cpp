#include "createclaim.h"
#include "ui_createclaim.h"

createClaim::createClaim(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createClaim)
{
    ui->setupUi(this);
}

void createClaim::setRequestID(QString reqID)
{
    requestID = reqID;
    ui->label->setText("Request ID :" + requestID);
}

void createClaim::setEmail(QString spEmail)
{
    sEmail = spEmail;
}

createClaim::~createClaim()
{
    delete ui;
}

void createClaim::on_pushButton_clicked()
{
    QString claimID = QString::number(QRandomGenerator::global()->bounded(10000));
    QString completedBy = ui->lineEdit_2->text();
    QString invoice = ui->textEdit->toPlainText();
    QString completedTime = QDateTime::currentDateTime().toString();

    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");
    ravfsdb.open();

    QSqlQuery * qry = new QSqlQuery(ravfsdb);
    qry->prepare("update request set status = 1, timeCompleted = '" + completedTime + "' where requestId = " + requestID);
    qry->exec();

    qry->prepare("insert into claim (claimID, requestID, invoice, completedByProviderAgent, timeClaimFiled, claimStatus) values ("
                 + claimID + "," + requestID + ",'" + invoice + "','" + sEmail + "','" + completedTime +  "', 0)");
    qry->exec();
    ravfsdb.close();


}
