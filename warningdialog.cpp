#include "warningdialog.h"
#include "ui_warningdialog.h"

WarningDialog::WarningDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarningDialog)
{
    ui->setupUi(this);
    QWidget::setFixedSize(this->size());
    setWindowFlags(Qt::WindowStaysOnTopHint);
}

WarningDialog::~WarningDialog()
{
    delete ui;
}

void WarningDialog::setHeadline(QString headline)
{
    ui->label_headline->setText(headline);
}

void WarningDialog::setDescription(QString description)
{
    ui->label_description->setText(description);
}
