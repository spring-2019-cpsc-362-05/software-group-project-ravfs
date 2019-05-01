#include "createtenant.h"
#include "ui_createtenant.h"

createTenant::createTenant(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createTenant)
{
    ui->setupUi(this);
}

createTenant::~createTenant()
{
    delete ui;
}
