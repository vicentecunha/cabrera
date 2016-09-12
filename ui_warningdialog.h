/********************************************************************************
** Form generated from reading UI file 'warningdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNINGDIALOG_H
#define UI_WARNINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WarningDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_headline;
    QLabel *label_description;

    void setupUi(QDialog *WarningDialog)
    {
        if (WarningDialog->objectName().isEmpty())
            WarningDialog->setObjectName(QStringLiteral("WarningDialog"));
        WarningDialog->resize(400, 130);
        buttonBox = new QDialogButtonBox(WarningDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(310, 90, 81, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        label = new QLabel(WarningDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 128, 128));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/sign-warning-icon.png")));
        label->setScaledContents(true);
        label_headline = new QLabel(WarningDialog);
        label_headline->setObjectName(QStringLiteral("label_headline"));
        label_headline->setGeometry(QRect(130, 0, 261, 21));
        QFont font;
        font.setFamily(QStringLiteral("Latin Modern Sans"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_headline->setFont(font);
        label_headline->setWordWrap(true);
        label_description = new QLabel(WarningDialog);
        label_description->setObjectName(QStringLiteral("label_description"));
        label_description->setGeometry(QRect(130, 20, 261, 71));
        label_description->setWordWrap(true);

        retranslateUi(WarningDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), WarningDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WarningDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(WarningDialog);
    } // setupUi

    void retranslateUi(QDialog *WarningDialog)
    {
        WarningDialog->setWindowTitle(QApplication::translate("WarningDialog", "Warning Dialog", 0));
        label->setText(QString());
        label_headline->setText(QApplication::translate("WarningDialog", "Warning: short description", 0));
        label_description->setText(QApplication::translate("WarningDialog", "Warning explanation and tips.", 0));
    } // retranslateUi

};

namespace Ui {
    class WarningDialog: public Ui_WarningDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNINGDIALOG_H
