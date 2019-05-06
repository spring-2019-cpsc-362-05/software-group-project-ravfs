#include "viewtenants.h"
#include "ui_viewtenants.h"

viewTenants::viewTenants(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewTenants)
{
    ui->setupUi(this);
}

void viewTenants::setUpEmail(QString actEmail)
{
    email = actEmail;
}

void viewTenants::setUpTable()
{
    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");
    ravfsdb.open();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery(ravfsdb);


    qry->prepare("select a.firstName, a.lastName, a.phone, a.address, a.email from account a, tenant t where t.tEmail = a.email AND t.lEmail = '" + email + "'");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    ravfsdb.close();
}

viewTenants::~viewTenants()
{
    delete ui;
}
