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
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private  slots:
    void digit_Pressed();
    void on_pushButton_18_released();
    void unary_operation_pressed();
    void on_pushButton_clr_released();
    void on_pushbutton_equals_released();
    void arithmatics_operations_pressed();
};

#endif // MAINWINDOW_H
