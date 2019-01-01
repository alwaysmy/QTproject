#ifndef SHOWRESULT_H
#define SHOWRESULT_H

#include <QDialog>
#include"list_data.h"
#include"base.h"
#include<QPlainTextEdit>

namespace Ui {
class showResult;
}

class showResult : public QDialog
{
    Q_OBJECT

public:
    explicit showResult(QWidget *parent = 0);
    void getType(QString type_do);
    void getValue(glist finalOne);
    ~showResult();

private:
    Ui::showResult *ui;
};

#endif // SHOWRESULT_H
