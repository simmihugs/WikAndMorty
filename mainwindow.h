#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "components/LoadingIndicator/indicator.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QList>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPushButton>
#include <QString>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  QNetworkAccessManager *manager;
  QNetworkRequest request;
  LoadingIndicator *loadingIndicator;

private slots:
  void handleGridButtonClick(int index);
  void sendRequest();
  void handleJsonResponse(const QString &jsonStr);
};
#endif // MAINWINDOW_H
