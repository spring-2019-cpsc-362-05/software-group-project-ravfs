#ifndef VIEWCLAIMS_H
#define VIEWCLAIMS_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QString>

namespace Ui {
class viewClaims;
}

class viewClaims : public QWidget
{
    Q_OBJECT

public:
    explicit viewClaims(QWidget *parent = nullptr);
    ~viewClaims();

    void setEmail(QString actEmail);
    void setType (QString acctType);
    void setUpTable();

private slots:
    void on_pushButton_pay_clicked();

private:
    Ui::viewClaims *ui;
    QString email;
    QString type;
};

#endif // VIEWCLAIMS_H
