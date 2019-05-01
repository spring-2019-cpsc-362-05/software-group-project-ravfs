#include "createrequest.h"
#include "ui_createrequest.h"

createRequest::createRequest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createRequest)
{
    ui->setupUi(this);
}

createRequest::~createRequest()
{
    delete ui;
}
