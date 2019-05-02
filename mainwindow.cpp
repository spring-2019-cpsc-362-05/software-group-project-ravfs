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
    // I was having a problem where if you put in a email that didnt exist it would return a blank password and
    // the logic would consider it corrent (password = "" and the query would return "" so they were =, this if statement prevents that
    if(password == "")
    {
        password = "urhffhsjkrhgfjlksh";

    }

    QSqlDatabase ravfsdb = QSqlDatabase::addDatabase("QSQLITE");
    ravfsdb.setDatabaseName("C:/Users/bravi/OneDrive/Desktop/Vinny/CSPC 362/sqlite-tools-win32-x86-3280000/sqlite-tools-win32-x86-3280000/ravfs.db");

    if(!ravfsdb.open())
    {

    }

    QSqlQueryModel rec;
    rec.setQuery("select password from account a where a.email = '" + username + "'");
    if( password == rec.record(0).value("password").toString())
    {
        //do stuff
        ui->label->setText("logging in . . .");

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
