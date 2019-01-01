#ifndef BASE_H
#define BASE_H
#include<iostream>
using namespace std;
typedef char elemtype;
struct node
{
    elemtype data;
    node *prior = NULL;
    node *next = NULL;
    //void setnode (node *p=NULL,elemtype d=0,node *n=NULL){prior=p;data=d;next=n;}
    node(node *p = NULL, elemtype d = 0, node *n = NULL) { prior = p; data = d; next = n; }
};
#endif // BASE_H
