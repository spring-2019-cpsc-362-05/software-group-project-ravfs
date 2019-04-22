#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "account.h"
#include "landlord.h"
#include "tenant.h"
#include "serviceprovider.h"

#include <memory>

#include <QMainWindow>
#include <QStackedWidget>

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

private:
    Ui::MainWindow *ui;
    QStackedWidget *stacked_widget;
    std::unique_ptr<Accounts::Account> account;
};

#endif // MAINWINDOW_H
