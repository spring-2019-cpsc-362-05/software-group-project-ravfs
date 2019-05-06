
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QSql>
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
    QString type;
    // I was having a problem where if you put in a email that didnt exist it would return a blank password and
    // the logic would consider it corrent (password = "" and the query would return "" so they were =, this if statement prevents that
    if(password == "")
    {
        password = "urhffhsjkrhgfjlksh";

    }

    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName(QDir::currentPath() + "/ravfs.db");

    ravfsdb.open();

    QSqlQueryModel rec;
    rec.setQuery("select password from account a where a.email = '" + username + "'");
    if( password == rec.record(0).value("password").toString())
    {
        //do stuff
        rec.setQuery("select type from account a where a.email = '" + username + "'");
        type = rec.record(0).value("type").toString();
        mnMenu.setEmail(username);
        mnMenu.setType(type);
        mnMenu.setUpMainPage();
        mnMenu.show();


    }
    else
    {
        //incorrect email password combo
         ui->label->setText("incorrect email password combination");

    }

    ravfsdb.close();
}

void MainWindow::on_pushButton_create_account_clicked()
{
    newAccount.show();
}

void MainWindow::on_pushButton_clicked()
{

}
