#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void inputSet();
    ~MainWindow();

private slots:
    void on_buttonInput_clicked();

    void on_actionVersion_triggered();

    void on_actionAuthor_triggered();

    void on_actionUser_s_Guide_triggered();

    void on_agunion_clicked();

    void on_subtraction_clicked();

    void on_intersection_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
