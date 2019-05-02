#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "account.h"
#include "landlord.h"
#include "tenant.h"
#include "serviceprovider.h"
#include "createaccount.h"
#include "mainmenu.h"

#include <memory>

#include <QMainWindow>
#include <QStackedWidget>
#include <QtSql>
#include <QtDebug>
#include <qfileinfo.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_sign_in_clicked();

    void on_pushButton_create_account_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<Accounts::Account> account;
    createAccount newAccount;
    viewRequests vRequests;
    mainMenu mnMenu;
};

#endif // MAINWINDOW_H
