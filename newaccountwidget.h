#ifndef NEWACCOUNTWIDGET_H
#define NEWACCOUNTWIDGET_H

#include <QWidget>
#include<QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QMessageBox>
#include<QCryptographicHash>

QString MD5(QString str);
namespace Ui {
class NewAccountWidget;
}

class NewAccountWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NewAccountWidget(QWidget *parent = 0);
    void openDatabase();

    ~NewAccountWidget();

private slots:
    void on_reg_buttom_clicked();


private:
    Ui::NewAccountWidget *ui;
};

#endif // NEWACCOUNTWIDGET_H
