#include "userswidget.h"
#include "ui_userswidget.h"

usersWidget::usersWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usersWidget)
{
    ui->setupUi(this);
}

usersWidget::~usersWidget()
{
    delete ui;
}
