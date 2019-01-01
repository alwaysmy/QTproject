#include"base.h"
#include"list_data.h"
#include<iostream>
#include<string.h>
#include"QDebug"
#include<QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
glist::glist()
{
    len = 0;
}
void glist::set_glist(char * aset)
{
    int i;//用于循环输入
          //int len=0;//保存链表长度
    elemtype d;//缓存元素值
               //    node *test=NULL;//用于创建完链表遍历输出链表
    node *p = NULL;//指向当前节点的指针
    node *pre = NULL;//指向前驱结点的指针
    //cout <<endl<< "想输入几个节点？" << endl;
//    cin >> len;
//    cout << "开始输入" << endl;
//    cin >> d;
    d = aset[0];
    p = new node(NULL, d);//为P新分配内存
    head = p;
    pre = p;
    len = strlen(aset);
    for (i = 1; i<len; i++)
    {
        //cin >> d;
        d = aset[i];
        if(elemExist(d))
        {
           //cout<<d<<"重复！"<<endl;
           //len--;
            i++;
        }
        else
        {
        p = new node(pre, d);
        pre->next = p;
        pre = p;
        }
    }
    pre->next = NULL;
    tail = pre;
}
bool glist::elemExist(elemtype e)
{
    node* p = head;//point to first node
                   //std::cout<<"p:"<<p->elem;
    if (p != NULL)
    {

        while (p->data != e)
        {
            if (p->next == NULL)
                return false;//find all elems and not found
            p = p->next;//continue
        }
        return true;//this elem in the set
    }
    else return false;

}
void glist::show()
{
    node *test = NULL;//用于遍历输出链表
    test = head;
    cout << endl;
    if (head == NULL)
    {
        //cout << endl << "空集！" << endl;
        QMessageBox::information(NULL,("提示"),("空集！"),QMessageBox::Ok);
    }
    qDebug()<<"============I am a mengmengda fengexian================";
    while (test != NULL)
    {
        //cout << test->data << "  ";
        qDebug()<<test->data<<"  ";//我寻思先测试一下
        test = test->next;
    }

}
void glist::addElem(elemtype e)
{
    if (head == NULL)
    {
        node *p = new node(head, e, NULL);
        head = p;
        tail = p;
        len++;
    }
    else
    {
        if (!elemExist(e))//add the elem in the end
        {

            node *p = new node(tail, e, NULL);

            tail->next = p;
            tail = p;

            //cout << tail->data << endl;
            len++;
        }
    }

}
void glist::getLength()
{
    cout << "The length is" << len << endl;
}

glist intersection(glist la, glist lb)//bing
{
    glist tst;//作为最终返回的临时链表
    node *test;//用于遍历
    if (la.len<lb.len)
    {
        test = la.head;
        while (test != NULL)
        {

            if (lb.elemExist(test->data))
            {
                tst.addElem(test->data);
            }
            test = test->next;
        }

    }
    else
    {
        test = lb.head;
        while (test != NULL)
        {
            if (la.elemExist(test->data))
            {
                tst.addElem(test->data);
                //tst.show();
            }
            test = test->next;

        }
    }
    return tst;
}

glist subtraction(glist la, glist lb)//cha
{
    glist its = intersection(la, lb);
    glist tst;
    node *test = la.head;
    while (test != NULL)
    {
        if (its.elemExist(test->data) == false)
        {
            tst.addElem(test->data);
        }
        test = test->next;
    }
    return tst;
}
glist agunion(glist la, glist lb)//jiao
{
    glist tst = subtraction(la, lb);
    tst.tail->next = lb.head;
    tst.tail = lb.tail;

    return tst;
}

