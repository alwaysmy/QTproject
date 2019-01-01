#ifndef USERSWIDGET_H
#define USERSWIDGET_H

#include <QWidget>

namespace Ui {
class usersWidget;
}

class usersWidget : public QWidget
{
    Q_OBJECT

public:
    explicit usersWidget(QWidget *parent = 0);
    ~usersWidget();

private:
    Ui::usersWidget *ui;
};

#endif // USERSWIDGET_H
