#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include <QList>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  QList<QPushButton*> myButtons = {
    ui->pushButton_1,
    ui->pushButton_2,
    ui->pushButton_3,
    ui->pushButton_4,
    ui->pushButton_5,
    ui->pushButton_6,
    ui->pushButton_7,
    ui->pushButton_8,
    ui->pushButton_9
  };

  int index = 1;
  for (QPushButton *button : myButtons) {
      connect(button, &QPushButton::clicked,
	  this,
	      [this, index] {
		this->handleGridButtonClick(index);
	      }
	      );
      index++;
  }

}

void MainWindow::handleGridButtonClick(int index)
{
    // The 'index' parameter is now the button's ID (1-9)
    qDebug() << "Button for Character ID" << index << "was clicked.";
    
    // Example usage: You can now easily construct the API URL
    QString apiUrl = QString("https://rickandmortyapi.com/api/character/%1").arg(index);
    qDebug() << "Fetching URL:" << apiUrl;
}

MainWindow::~MainWindow()
{
  delete ui;
}

