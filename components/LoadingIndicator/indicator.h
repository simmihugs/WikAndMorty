#ifndef INDICATOR_H
#define INDICATOR_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoadingIndicator;
}
QT_END_NAMESPACE

class LoadingIndicator : public QWidget {
    Q_OBJECT

public:
    explicit LoadingIndicator(QWidget *parent = nullptr);
    ~LoadingIndicator();

private:
    Ui::LoadingIndicator *ui;
};

#endif // INDICATOR_H
