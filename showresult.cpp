#include "showresult.h"
#include "ui_showresult.h"
#include<QString>
#include<QTextEdit>
#include<QDebug>
showResult::showResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showResult)
{
    ui->setupUi(this);
}

void showResult::getType(QString type_do)
{
    QString title = type_do;
    this->setWindowTitle(title);
}

void showResult::getValue(glist finalOne)
{
    //QPlainTextEdit text_show;
    QTextEdit *text_show = ui->textEdit;
    QString theSet;
    node *test = NULL;//用于遍历输出链表
    //test = head;
    test = finalOne.head;
    //cout << endl;
    if(finalOne.head == NULL)
    {
        //cout << endl << "空集！" << endl;
        //QMessageBox::information(NULL,("提示"),("空集！"),QMessageBox::Ok);
        text_show->setText("计算为空集");
    }
    else
    {
        while (test != NULL)
        {
            //cout << test->data << "  ";
            qDebug()<<test->data<<"  ";//我寻思先测试一下
            theSet.append(test->data);
            theSet.append(",");
            test = test->next;
        }
        text_show->setText(theSet);
    }
}

showResult::~showResult()
{
    delete ui;
}
