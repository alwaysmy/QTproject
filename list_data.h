#ifndef LIST_DATA_H
#define LIST_DATA_H

#include"base.h"
using namespace std;
struct glist
{
    node *head = NULL;
    node *tail = NULL;
    int len;
    glist();
    void set_glist(char * aset);
    void show();
    void getLength();
    void addElem(elemtype e);
    bool elemExist(elemtype e);
};
glist intersection(glist la, glist lb);
glist subtraction(glist la, glist lb);
glist agunion(glist la, glist lb);
#endif // LIST_DATA_H
