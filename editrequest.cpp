#include "editrequest.h"
#include "ui_editrequest.h"

editRequest::editRequest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editRequest)
{
    ui->setupUi(this);

}

editRequest::~editRequest()
{
    delete ui;
}

void editRequest::setRequestId(int id)
{

    requestID = id;
}

void editRequest::setEmail(QString accEmail)
{
    email = accEmail;
}

void editRequest::setEmergency(bool e)
{
    emergency = e;
}

void editRequest::setStatus(bool s)
{
    status = s;
}

void editRequest::setLandlordStatus(bool l)
{
    landlordStatus = l;
    landlordStatusIsSet = true;
}

void editRequest::setAssignedProvider(QString provider)
{
    assignedProvider = provider;
}

void editRequest::setNotes(QString note)
{
    notes = note;
}

void editRequest::setType(QString accountType)
{
    type = accountType;
}

void editRequest::setkindOfService(QString service)
{
    kindOfService = service;
}

void editRequest::setUpPage()
{
    ui->label_7->setText("Request ID : " + QString::number(requestID));

    if(emergency == true)
    {
        ui->emergencyRadioButton->setChecked(true);
    }
    else
    {
        ui->noERadioButton->setChecked(true);
    }

    if(landlordStatus == true)
    {
        ui->payRadioButton->setChecked(true);
    }
    else if(landlordStatus == false && landlordStatusIsSet == true)
    {
        ui->noPayRadioButton->setChecked(true);
    }

    ui->lineEdit_kindOOfService->setText(kindOfService);
    ui->lineEdit_assignedProvider->setText(assignedProvider);
    ui->textEdit_notes->setText(notes);

    if(type == "tenant")
    {
        ui->payRadioButton->setDisabled(true);
        ui->noPayRadioButton->setDisabled(true);
        ui->emergencyRadioButton->setEnabled(true);
        ui->noERadioButton->setEnabled(true);
        ui->lineEdit_kindOOfService->setEnabled(true);
        ui->lineEdit_assignedProvider->setEnabled(true);
        ui->textEdit_notes->setEnabled(true);
    }
    else if(type == "landlord")
    {
        ui->payRadioButton->setEnabled(true);
        ui->noPayRadioButton->setEnabled(true);
        ui->emergencyRadioButton->setDisabled(true);
        ui->noERadioButton->setDisabled(true);
        ui->lineEdit_kindOOfService->setDisabled(true);
        ui->lineEdit_assignedProvider->setDisabled(true);
        ui->textEdit_notes->setDisabled(true);

    }
}

void editRequest::setUpTable()
{
    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");
    ravfsdb.open();

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(ravfsdb);

    qry->prepare("select s.* from serviceprovider s, request r, tenant t, landlord l, locationtoserviceprovider ls "
                 "where r.requestID = " + QString::number(requestID) + " AND r.tEmail = t.tEmail AND t.lEmail = l.lEmail AND "
                                                                       "l.locationKey = ls.locationKey AND ls.spEmail = s.sEmail");
    qry->exec();
    model->setQuery(*qry);
    ui->tableViewt->setModel(model);

    ravfsdb.close();
}



void editRequest::on_pushButton_clicked()
{
    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");
    ravfsdb.open();

    QSqlQuery * qry = new QSqlQuery(ravfsdb);

    if(type == "tenant")
    {
        if(ui->emergencyRadioButton->isChecked() == true)
        {
            qry->prepare("update request set flagEorNoE = 1, kindOfservice = '" + ui->lineEdit_kindOOfService->text() + "', assignedProvider = '"
                         + ui->lineEdit_assignedProvider->text() + "', notes = '" + ui->textEdit_notes->toPlainText()
                         + "' where requestId = " + QString::number(requestID));


        }
        else
        {
            qry->prepare("update request set flagEorNoE = 0, kindOfservice = '" + ui->lineEdit_kindOOfService->text() + "', assignedProvider = '"
                         + ui->lineEdit_assignedProvider->text() + "', notes = '" + ui->textEdit_notes->toPlainText()
                         + "' where requestId = " + QString::number(requestID));

        }
    }
    else if (type == "landlord")
    {
        if(ui->payRadioButton->isChecked() == true)
        {
            qry->prepare("update request set landlordStatus = 1 where requestId = " + QString::number(requestID));

        }
        else if (ui->noPayRadioButton->isChecked() == true)
        {
            qry->prepare("update request set landlordStatus = 0 where requestId = " + QString::number(requestID));

        }
    }
    qry->exec();

    ravfsdb.close();
}

void editRequest::on_pushButton_2_clicked()
{

}
