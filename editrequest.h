#ifndef EDITREQUEST_H
#define EDITREQUEST_H

#include <QWidget>
#include <QStackedWidget>
#include <QtSql>
#include <QtDebug>
#include <qfileinfo.h>

namespace Ui {
class editRequest;
}

class editRequest : public QWidget
{
    Q_OBJECT

public:
    explicit editRequest(QWidget *parent = nullptr);
    ~editRequest();

    void setRequestId(int id);

    void setEmail(QString accEmail);

    void setEmergency(bool e);

    void setStatus(bool s);

    void setLandlordStatus(bool l);

    void setAssignedProvider(QString provider);

    void setNotes(QString note);

    void setType(QString accountType);

    void setkindOfService(QString service);

    void setUpPage();

    void setUpTable();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::editRequest *ui;
    int requestID;
    QString email;
    bool emergency;
    bool status;
    bool landlordStatus;
    bool landlordStatusIsSet = false;
    QString kindOfService;
    QString assignedProvider;
    QString notes;
    QDateTime timeRequested();
    QDateTime timeCompleted();
    QString type;
    //viewRequests vewReq;

};

#endif // EDITREQUEST_H
