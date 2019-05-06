#ifndef CREATEREQUEST_H
#define CREATEREQUEST_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <qfileinfo.h>
#include <random>

namespace Ui {
class createRequest;
}

class createRequest : public QWidget
{
    Q_OBJECT

public:
    explicit createRequest(QWidget *parent = nullptr);
    ~createRequest();

    void setEmail(QString acctEmail);
    void setUpSPTable();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::createRequest *ui;
    QString email;
};

#endif // CREATEREQUEST_H
