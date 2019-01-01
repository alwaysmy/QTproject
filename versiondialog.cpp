#include "versiondialog.h"
#include "ui_versiondialog.h"

VersionDialog::VersionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VersionDialog)
{
    ui->setupUi(this);
    setWindowTitle("VERSION INFORMATION");
}

VersionDialog::~VersionDialog()
{
    delete ui;
}
