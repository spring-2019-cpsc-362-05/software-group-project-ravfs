#include "testf.h"
#include "ui_testf.h"

testf::testf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testf)
{
    ui->setupUi(this);
}

testf::~testf()
{
    delete ui;
}

void testf::on_pushButton_clicked()
{

}
