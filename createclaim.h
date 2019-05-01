#ifndef CREATECLAIM_H
#define CREATECLAIM_H

#include <QWidget>

namespace Ui {
class createClaim;
}

class createClaim : public QWidget
{
    Q_OBJECT

public:
    explicit createClaim(QWidget *parent = nullptr);
    ~createClaim();

private:
    Ui::createClaim *ui;
};

#endif // CREATECLAIM_H
