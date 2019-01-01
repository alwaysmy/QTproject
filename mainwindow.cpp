#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include"list_data.h"
#include"base.h"



#include<iostream>
#include"versiondialog.h"   //版本界面
#include"authordialog.h"    //作者界面
#include"userswidget.h"  //用户手册界面
// #include"newaccountwidget.h"  //新建用户界面
#include"showresult.h"  //显示结果界面

#include<string.h>
#include<QRegExp>
#include<string>
#include<QLabel>
#include<QString>
#include<QStringList>
#include<QMessageBox>
glist la;
glist lb,lc;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_set_one->setFocus();//将鼠标定位到第一个集合栏
}

void MainWindow::inputSet()
{
    QString set_one=ui->lineEdit_set_one->text();//获取set one
    QString set_two=ui->lineEdit_set_two->text();//获取set two

    /********************************************************
     * 输入集合操作***
     **/
    if (set_one.isEmpty()||set_two.isEmpty())
        {
        QMessageBox::information(this,("提示"),(" 请不要留空 "),QMessageBox::Ok);
        ui->lineEdit_set_one->setFocus();  //将鼠标定位到集合一
        }
    else
    {
        //开始处理,需要把输入的一排数据转成一个一个的方便调用后面的数据

//           QStringList ElemLists_one = set_one.split(QRegExp(","));
//           QStringList ElemLists_two = set_two.split(QRegExp(","));//Chinese comma and English comma

//           qDebug()<<set_one<<"list:"<<ElemLists_one<<" "<<ElemLists_two[1]<<ElemLists_one.length();
           QString ElemLists_one = set_one.remove(",");
           QString ElemLists_two = set_two.remove(",");
           //qDebug()<<set_one<<"list:"<<ElemLists_one<<" "<<ElemLists_two[1]<<ElemLists_one.length();
           char* one,*two;
           QByteArray onet = ElemLists_one.toLatin1(); // must
           one=onet.data();
           QByteArray twot = ElemLists_two.toLatin1(); // must
           two=twot.data();
           la.set_glist(one);
           lb.set_glist(two);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonInput_clicked()
{
    inputSet();
}
/***********************************************
 * 打开查看版本
 * *********************************************/
void MainWindow::on_actionVersion_triggered()
{
    VersionDialog version;
    version.exec();
}
/***********************************************
 * 打开查看作者
 * *********************************************/
void MainWindow::on_actionAuthor_triggered()
{
    authorDialog authors;
    authors.exec();
}
/***********************************************
 * 打开用户手册
 * *********************************************/
void MainWindow::on_actionUser_s_Guide_triggered()
{
    usersWidget *userguide=new usersWidget;
    userguide->setAttribute(Qt::WA_DeleteOnClose);
    userguide->show();
}

void MainWindow::on_agunion_clicked()
{
    inputSet();//输入框内的数字
    lc = agunion(la, lb);
    lc.show();
    showResult showDia;
    showDia.getType("并集运算");
    showDia.getValue(lc);
    showDia.exec();
}

void MainWindow::on_subtraction_clicked()
{
    inputSet();
    lc = subtraction(la, lb);
    //lc.show();

    showResult showDia;
    showDia.getType("差集运算");
    showDia.getValue(lc);
    showDia.exec();

}

void MainWindow::on_intersection_clicked()
{
    inputSet();
    lc = intersection(la, lb);
    //lc.show();
    showResult showDia;
    showDia.getType("交集运算");
    showDia.getValue(lc);
    showDia.exec();
}
