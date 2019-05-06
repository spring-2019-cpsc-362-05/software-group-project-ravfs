#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <viewrequests.h>
#include <createrequest.h>
#include <viewclaims.h>
#include <viewtenants.h>
#include <updateaccount.h>


namespace Ui {
class mainMenu;
}

class mainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit mainMenu(QWidget *parent = nullptr);
    void setEmail(QString acctEmail);
    void setType(QString acctType);
    void setUpMainPage();
    ~mainMenu();

private slots:
    void on_pushButton_viewReq_clicked();

    void on_pushButton_createReq_clicked();

    void on_pushButton_viewTenants_clicked();

    void on_pushButton_viewClaims_clicked();

    void on_pushButton_acctSettings_clicked();

private:
    Ui::mainMenu *ui;
    viewRequests viewReq;
    createRequest crtReq;
    viewClaims viewClms;
    viewTenants viewTen;
    updateAccount udtAct;
    QString actEmail;
    QString type;
};

#endif // MAINMENU_H
