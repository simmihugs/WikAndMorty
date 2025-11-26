#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  manager = new QNetworkAccessManager(this);
  this->connect(manager, &QNetworkAccessManager::finished, this,
                [=](QNetworkReply *reply) {
                  if (reply->error()) {
                    qDebug() << "Error:" << reply->errorString();
                    return;
                  }
                  QString response = reply->readAll();
                  handleJsonResponse(response);
                });

  ui->setupUi(this);

  QList<QPushButton *> myButtons = {
      ui->pushButton_1, ui->pushButton_2, ui->pushButton_3,
      ui->pushButton_4, ui->pushButton_5, ui->pushButton_6,
      ui->pushButton_7, ui->pushButton_8, ui->pushButton_9};

  int index = 1;
  for (QPushButton *button : myButtons) {
    if (index == 3) {
      this->connect(button, &QPushButton::clicked, this,
                    [this, index] { this->handleGridButtonClick(index); });

    } else {
      this->connect(button, &QPushButton::clicked, this,
                    &MainWindow::sendRequest);
    }
    index++;
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::handleJsonResponse(const QString &jsonStr) {
  QJsonParseError parseError;
  QJsonDocument jsonDoc =
      QJsonDocument::fromJson(jsonStr.toUtf8(), &parseError);

  if (parseError.error != QJsonParseError::NoError) {
    qDebug() << "JSON parse error:" << parseError.errorString();
    qDebug() << "Raw response:" << jsonStr;
    return;
  }

  // Convert JSON document to nicely formatted string
  QString prettyJson = jsonDoc.toJson(QJsonDocument::Indented);
  qDebug().noquote() << "Formatted JSON:\n" << prettyJson;
}

void MainWindow::sendRequest() {
  request.setUrl(QUrl("https://rickandmortyapi.com/api"));
  manager->get(request);
}

void MainWindow::handleGridButtonClick(int index) {
  // The 'index' parameter is now the button's ID (1-9)
  qDebug() << "Button for Character ID" << index << "was clicked.";

  // Example usage: You can now easily construct the API URL
  QString apiUrl =
      // QString("https://rickandmortyapi.com/api/character/%1").arg(index);
      QString("https://rickandmortyapi.com/api");
  qDebug() << "Fetching URL:" << apiUrl;
}
