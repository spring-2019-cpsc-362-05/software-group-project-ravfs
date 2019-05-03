#include "database_stuff.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    //stacked_widget(new QStackedWidget),
    account(nullptr)
{
    ui->setupUi(this);

    // database connection...
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_sign_in_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (DB_stuff::account_exists(username, password)) {
        account = DB_stuff::get_account(username, password);
        ui->stackedWidget->setCurrentIndex(static_cast<int>(account->getAcct_type()));
    } else {
        ui->label_pass_incorrect->setText(QString("Incorrect username or password."));
    }
}

void MainWindow::on_pushButton_create_account_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{
    claim.show();
}
