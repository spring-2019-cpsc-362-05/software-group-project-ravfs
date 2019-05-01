#include "completeclaim.h"
#include "ui_completeclaim.h"

CompleteClaim::CompleteClaim(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CompleteClaim)
{
    ui->setupUi(this);
}

CompleteClaim::~CompleteClaim()
{
    delete ui;
}
