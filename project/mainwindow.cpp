#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stacked_widget(new QStackedWidget),
    account(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete stacked_widget;
    delete ui;
}

void MainWindow::on_pushButton_sign_in_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "username" && password == "password") {
        // TODO
        ;
    } else {
        ui->label_pass_incorrect->setText(QString("Incorrect username or password."));
    }
}

void MainWindow::on_pushButton_create_account_clicked()
{

}
