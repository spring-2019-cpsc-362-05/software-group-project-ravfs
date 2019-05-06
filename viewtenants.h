#ifndef VIEWTENANTS_H
#define VIEWTENANTS_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QString>

namespace Ui {
class viewTenants;
}

class viewTenants : public QWidget
{
    Q_OBJECT

public:
    explicit viewTenants(QWidget *parent = nullptr);
    ~viewTenants();
    void setUpEmail(QString actEmail);
    void setUpTable();

private:
    Ui::viewTenants *ui;
    QString email;
};

#endif // VIEWTENANTS_H
