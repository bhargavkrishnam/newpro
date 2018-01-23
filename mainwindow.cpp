#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstnum;
bool userIsTypingsecondnumber;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_zero,SIGNAL(released()),this,SLOT(digit_Pressed()));
    connect(ui->pushButton_one,SIGNAL(released()),this,SLOT(digit_Pressed()));
    connect(ui->pushButton_two,SIGNAL(released()),this,SLOT(digit_Pressed()));
    connect(ui->pushButton_three,SIGNAL(released()),this,SLOT(digit_Pressed()));
    connect(ui->pushButton_four,SIGNAL(released()),this,SLOT(digit_Pressed()));
    connect(ui->pushButton_five,SIGNAL(released()),this,SLOT(digit_Pressed()));
    connect(ui->pushButton_six,SIGNAL(released()),this,SLOT(digit_Pressed()));
    connect(ui->pushButton_seven,SIGNAL(released()),this,SLOT(digit_Pressed()));
    connect(ui->pushButton_eight,SIGNAL(released()),this,SLOT(digit_Pressed()));
    connect(ui->pushButton_nine,SIGNAL(released()),this,SLOT(digit_Pressed()));

    connect(ui->pushButton_modulus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_plusminus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    
     connect(ui->pushButton_addition,SIGNAL(released()),this,SLOT(arithmatics_operations_pressed()));
     connect(ui->pushbutton_subtraction,SIGNAL(released()),this,SLOT(arithmatics_operations_pressed()));
     connect(ui->pushbutton_multiplication,SIGNAL(released()),this,SLOT(arithmatics_operations_pressed()));
     connect(ui->pushButton_division,SIGNAL(released()),this,SLOT(arithmatics_operations_pressed()));

        ui->pushButton_addition->setCheckable(true);
        ui->pushbutton_subtraction->setCheckable(true);
        ui->pushbutton_multiplication->setCheckable(true);
        ui->pushButton_division->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_Pressed()
{
    QPushButton *button =(QPushButton*)sender();

    double labelnumber;
    QString newLabel;

    if((ui->pushButton_addition->isChecked() || ui->pushbutton_subtraction->isChecked() ||
            ui->pushbutton_multiplication->isChecked() || ui->pushButton_division->isChecked()) && (!userIsTypingsecondnumber))
    {

        labelnumber= button->text().toDouble();
        userIsTypingsecondnumber = true;
        newLabel = QString::number(labelnumber,'g',15);

    }
    else
    {
        if(ui->label->text().contains('.') && button->text()=="0")
        {
            newLabel = ui->label->text()+button->text();
        }
        else
        {

            labelnumber=(ui->label->text()+button->text()).toDouble();
            newLabel = QString::number(labelnumber,'g',15);
        }

    }

    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_18_released()
{
   ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operation_pressed()
{
    QPushButton *button =(QPushButton*)sender();

    double labelnumber;
    QString newLabel;

    if(button->text()== "+/-")
    {
     labelnumber = ui->label->text().toDouble();
     labelnumber = labelnumber * -1;
     newLabel = QString::number(labelnumber,'g',15);
     ui->label->setText(newLabel);
    }

    if(button->text()=="%")
    {
     labelnumber = ui->label->text().toDouble();
     labelnumber = labelnumber * 0.01;
     newLabel = QString::number(labelnumber,'g',15);
     ui->label->setText(newLabel);
    }

}

void MainWindow::on_pushButton_clr_released()
{
    ui->pushButton_addition->setChecked(false);
    ui->pushbutton_subtraction->setChecked(false);
    ui->pushbutton_multiplication->setChecked(false);
    ui->pushButton_division->setChecked(false);

    userIsTypingsecondnumber = false;
    ui->label->setText("0");

}

void MainWindow::on_pushbutton_equals_released()
{
    double labelnumber,secondnum;
    QString newLabel;

    secondnum = ui->label->text().toDouble();

    if(ui->pushButton_addition->isChecked())
    {
        labelnumber = firstnum + secondnum;
        newLabel = QString::number(labelnumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_addition->setChecked(false);
    }
    else if(ui->pushbutton_subtraction->isChecked())
    {
        labelnumber = firstnum - secondnum;
        newLabel = QString::number(labelnumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushbutton_subtraction->setChecked(false);

    }
    else if(ui->pushbutton_multiplication->isChecked())
    {
        labelnumber = firstnum * secondnum;
        newLabel = QString::number(labelnumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushbutton_multiplication->setChecked(false);
    }
    else if(ui->pushButton_division->isChecked())
    {
        labelnumber = firstnum / secondnum;
        newLabel = QString::number(labelnumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_division->setChecked(false);
    }
    userIsTypingsecondnumber = false;
}

void MainWindow::arithmatics_operations_pressed()
{
     QPushButton * button =(QPushButton*)sender();
     firstnum = ui->label->text().toDouble();
     button->setChecked(true);
     
}
