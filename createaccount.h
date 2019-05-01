#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class createAccount;
}

class createAccount : public QWidget
{
    Q_OBJECT

public:
    explicit createAccount(QWidget *parent = nullptr);
    ~createAccount();

private slots:
    void on_pushButton_clicked();

    void on_tenantButton_clicked();

    void on_landlordButton_clicked();

    void on_spButton_clicked();

private:
    Ui::createAccount *ui;
};

#endif // CREATEACCOUNT_H
