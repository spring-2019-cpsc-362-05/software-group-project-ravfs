#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <viewrequests.h>
#include <createrequest.h>

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

private:
    Ui::mainMenu *ui;
    viewRequests viewReq;
    createRequest crtReq;
    QString email;
    QString type;
};

#endif // MAINMENU_H
