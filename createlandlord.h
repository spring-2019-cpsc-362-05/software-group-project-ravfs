#ifndef CREATELANDLORD_H
#define CREATELANDLORD_H

#include <QWidget>

namespace Ui {
class createLandlord;
}

class createLandlord : public QWidget
{
    Q_OBJECT

public:
    explicit createLandlord(QWidget *parent = nullptr);
    ~createLandlord();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::createLandlord *ui;
};

#endif // CREATELANDLORD_H
