#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ui->myButton->setText("Not Clicked");  
  connect(ui->myButton, &QPushButton::clicked,
	  this, &MainWindow::on_myButton_clicked);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_myButton_clicked()
{
  qDebug() << "Button was clicked!";
  ui->myButton->setText("Clicked"); 
}
