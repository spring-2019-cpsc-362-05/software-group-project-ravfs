#ifndef COMPLETECLAIM_H
#define COMPLETECLAIM_H

#include <QWidget>

namespace Ui {
class CompleteClaim;
}

class CompleteClaim : public QWidget
{
    Q_OBJECT

public:
    explicit CompleteClaim(QWidget *parent = nullptr);
    ~CompleteClaim();

private:
    Ui::CompleteClaim *ui;
};

#endif // COMPLETECLAIM_H
