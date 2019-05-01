#include "createlandlord.h"
#include "ui_createlandlord.h"

createLandlord::createLandlord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createLandlord)
{
    ui->setupUi(this);
}

createLandlord::~createLandlord()
{
    delete ui;
}

void createLandlord::on_radioButton_clicked()
{
    ui->locationAddressTextBox->setDisabled(true);
    ui->locationKeyTextBox->setEnabled(true);
    ui->registerButton->setDisabled(true);
    ui->enterButton->setEnabled(true);
}

void createLandlord::on_radioButton_2_clicked()
{
    ui->locationAddressTextBox->setEnabled(true);
    ui->locationKeyTextBox->setDisabled(true);
    ui->registerButton->setEnabled(true);
    ui->enterButton->setDisabled(true);
}
