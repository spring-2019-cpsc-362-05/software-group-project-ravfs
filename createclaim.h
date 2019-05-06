#ifndef CREATECLAIM_H
#define CREATECLAIM_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QString>

namespace Ui {
class createClaim;
}

class createClaim : public QWidget
{
    Q_OBJECT

public:
    explicit createClaim(QWidget *parent = nullptr);
    ~createClaim();

    void setRequestID(QString reqID);
    void setEmail(QString spEmail);

private slots:
    void on_pushButton_clicked();

private:
    Ui::createClaim *ui;
    QString requestID;
    QString sEmail;
};

#endif // CREATECLAIM_H
