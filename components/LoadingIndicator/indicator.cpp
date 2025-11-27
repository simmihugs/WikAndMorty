#include "indicator.h"
#include "ui_indicator.h"

LoadingIndicator::LoadingIndicator(QWidget *parent)
    : QWidget(parent), ui(new Ui::LoadingIndicator) {
    ui->setupUi(this);
}

LoadingIndicator::~LoadingIndicator() {
    delete ui;
}
