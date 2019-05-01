#ifndef CREATEREQUEST_H
#define CREATEREQUEST_H

#include <QWidget>

namespace Ui {
class createRequest;
}

class createRequest : public QWidget
{
    Q_OBJECT

public:
    explicit createRequest(QWidget *parent = nullptr);
    ~createRequest();

private:
    Ui::createRequest *ui;
};

#endif // CREATEREQUEST_H
