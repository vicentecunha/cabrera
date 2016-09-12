/*
 * Cabrera: about.cpp
 * Author: Vicente Cunha
 * Date: July 2016
 */

#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    QWidget::setFixedSize(this->size());
}

About::~About()
{
    delete ui;
}
