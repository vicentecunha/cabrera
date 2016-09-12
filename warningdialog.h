/*
 * Cabrera: warningdialog.h
 * Author: Vicente Cunha
 * Date: July 2016
 */

#ifndef WARNINGDIALOG_H
#define WARNINGDIALOG_H

/*
 * INCLUDES
 */

#include <QDialog>

/*
 * CLASSES
 */

namespace Ui {
class WarningDialog;
}

class WarningDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WarningDialog(QWidget *parent = 0);
    ~WarningDialog();

    void setHeadline(QString);
    void setDescription(QString);

private:
    Ui::WarningDialog *ui;
};

#endif // WARNINGDIALOG_H
