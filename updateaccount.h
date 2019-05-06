#ifndef UPDATEACCOUNT_H
#define UPDATEACCOUNT_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class updateAccount;
}

class updateAccount : public QWidget
{
    Q_OBJECT

public:
    explicit updateAccount(QWidget *parent = nullptr);
    ~updateAccount();

    void setEmail(QString actEmail);
    void setType(QString actType);
    void setUpPage();

private slots:
    void on_pushButton_update_clicked();

    void on_pushButton_register_clicked();

private:
    Ui::updateAccount *ui;
    QString email;
    QString type;
};

#endif // UPDATEACCOUNT_H
