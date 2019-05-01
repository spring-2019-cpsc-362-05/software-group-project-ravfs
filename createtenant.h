#ifndef CREATETENANT_H
#define CREATETENANT_H

#include <QWidget>

namespace Ui {
class createTenant;
}

class createTenant : public QWidget
{
    Q_OBJECT

public:
    explicit createTenant(QWidget *parent = nullptr);
    ~createTenant();

private:
    Ui::createTenant *ui;
};

#endif // CREATETENANT_H
