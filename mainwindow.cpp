#include "database_stuff.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "testf.h"

#include <QString>
#include <QSql>
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    //stacked_widget(new QStackedWidget),
    account(nullptr)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_sign_in_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QSqlDatabase testdb = QSqlDatabase::addDatabase("QSQLITE");
    testdb.setDatabaseName("C:/Users/bravi/OneDrive/Desktop/Vinny/CSPC 362/sqlite-tools-win32-x86-3280000/sqlite-tools-win32-x86-3280000/ravfs.db");

    if(testdb.open())
    {
        /*QSqlQueryModel * model = new QSqlQueryModel();

        QSqlQuery * qry = new QSqlQuery(testdb);
        qry->prepare("select * from account");
        qry->exec();
        model->setQuery(*qry);
        ui->tableView->setModel(model);
        ui->label->setText(qry->value(1).toString());*/
    }

    //QSqlQuery qry(testdb);
    //qry.exec("select * from account");
    //ui->label->setText(qry.value(0).toString());

    /*if (DB_stuff::account_exists(username, password)) {
        account = DB_stuff::get_account(username, password);
        ui->stackedWidget->setCurrentIndex(static_cast<int>(account->getAcct_type()));
    } else {
        ui->label_pass_incorrect->setText(QString("Incorrect username or password."));
    }*/
}

void MainWindow::on_pushButton_create_account_clicked()
{
    newAccount.show();
}

void MainWindow::on_pushButton_clicked()
{

}
