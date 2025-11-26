#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
  void handleGridButtonClick(int index);
  void sendRequest();
  void handleJsonResponse(const QString &jsonStr);
};
#endif // MAINWINDOW_H
