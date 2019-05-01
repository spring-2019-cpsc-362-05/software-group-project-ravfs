#include "createclaim.h"
#include "ui_createclaim.h"

createClaim::createClaim(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createClaim)
{
    ui->setupUi(this);
}

createClaim::~createClaim()
{
    delete ui;
}
