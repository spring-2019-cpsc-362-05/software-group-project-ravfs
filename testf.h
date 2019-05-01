#ifndef TESTF_H
#define TESTF_H

#include <QWidget>


namespace Ui {
class testf;
}

class testf : public QWidget
{
    Q_OBJECT

public:
    explicit testf(QWidget *parent = nullptr);
    ~testf();

private slots:
    void on_pushButton_clicked();

private:
    Ui::testf *ui;
};

#endif // TESTF_H
