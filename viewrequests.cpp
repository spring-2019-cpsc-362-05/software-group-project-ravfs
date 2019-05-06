#include "viewrequests.h"
#include "ui_viewrequests.h"

viewRequests::viewRequests(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewRequests)
{
    ui->setupUi(this);
}

viewRequests::~viewRequests()
{
    delete ui;
}

void viewRequests::setRequestTable(QString accountEmail, QString accountType)
{
    email = accountEmail;
    type = accountType;
    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");
    ravfsdb.open();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(ravfsdb);

    if(type == "tenant")
    {
        qry->prepare("select a.firstName, a.lastName, a.address, r.* from request r, account a where a.email = r.tEmail AND r.tEmail = '" + email + "'");
        ui->pushButton->setText("Edit Request");

    }
    else if (type == "landlord")
    {
        qry->prepare("select a.firstName, a.lastName, a.phone, a.address, r.* from request r, tenant t, account a where a.email = t.tEmail AND t.tEmail = r.tEmail AND t.lEmail = '" + email + "'");
        ui->pushButton->setText("Edit Request");
    }
    else if (type == "service provider")
    {
        // this query returns requests which either A. the landlord has either approved or denied or B. the tenant has flagged this request as an emergency
        qry->prepare("select a.firstName, a.lastName, a.address, a.phone, r.* from request r, account a where "
                     "a.email = r.tEmail AND (r.landlordStatus != '' OR r.flagEorNoE = 1) AND r.assignedProvider = '" + email + "'");
        ui->pushButton->setText("Create Claim");

    }

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    ravfsdb.close();

}

void viewRequests::on_pushButton_clicked()
{
    editr.setType(type);

    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");
    ravfsdb.open();
    QSqlQueryModel rec;
    rec.setQuery("select * from request where requestID = " + ui->lineEdit->text() + "");

    int requestID = ui->lineEdit->text().toInt();

    ravfsdb.close();

    if(type == "service provider")
    {
        crtClaim.setRequestID(QString::number(requestID));
        crtClaim.setEmail(email);
        crtClaim.show();
    }
    else
    {
        QString assignedProvider = rec.record(0).value("assignedProvider").toString();
        QString kindOfService = rec.record(0).value("kindOfService").toString();
        QString notes = rec.record(0).value("notes").toString();
        bool emerg = rec.record(0).value("flagEorNoE").toBool();
        bool landlordStatus = rec.record(0).value("landlordStatus").toBool();

        editr.setEmergency(emerg);
        editr.setRequestId(requestID);
        editr.setkindOfService(kindOfService);
        editr.setAssignedProvider(assignedProvider);
        editr.setNotes(notes);

        if(rec.record(0).value("landlordStatus").toString() != "")
        {
            editr.setLandlordStatus(landlordStatus);
        }
        editr.setUpPage();
        editr.setUpTable();
        editr.show();
    }

    ui->lineEdit->setText("");


}

void viewRequests::on_pushButton_3_clicked()
{
    setRequestTable(email, type);
}
