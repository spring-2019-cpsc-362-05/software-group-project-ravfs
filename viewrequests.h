#ifndef VIEWREQUESTS_H
#define VIEWREQUESTS_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QString>
#include <editrequest.h>
#include <createclaim.h>

namespace Ui {
class viewRequests;
}

class viewRequests : public QWidget
{
    Q_OBJECT

public:
    explicit viewRequests(QWidget *parent = nullptr);
    ~viewRequests();


    void setRequestTable(QString email, QString type);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::viewRequests *ui;
    QString email;
    QString type;
    editRequest editr;
    createClaim crtClaim;
};

#endif // VIEWREQUESTS_H
