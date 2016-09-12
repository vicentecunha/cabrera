/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *icon;
    QLabel *version;
    QLabel *developer;
    QLabel *company;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->resize(250, 120);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(About->sizePolicy().hasHeightForWidth());
        About->setSizePolicy(sizePolicy);
        buttonBox = new QDialogButtonBox(About);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(160, 80, 81, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        icon = new QLabel(About);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setGeometry(QRect(10, 10, 121, 100));
        icon->setPixmap(QPixmap(QString::fromUtf8(":/img/cabrera-icon.png")));
        icon->setScaledContents(true);
        version = new QLabel(About);
        version->setObjectName(QStringLiteral("version"));
        version->setGeometry(QRect(140, 10, 71, 21));
        QFont font;
        font.setPointSize(10);
        version->setFont(font);
        developer = new QLabel(About);
        developer->setObjectName(QStringLiteral("developer"));
        developer->setGeometry(QRect(140, 50, 101, 16));
        developer->setFont(font);
        company = new QLabel(About);
        company->setObjectName(QStringLiteral("company"));
        company->setGeometry(QRect(140, 30, 111, 16));
        company->setFont(font);

        retranslateUi(About);
        QObject::connect(buttonBox, SIGNAL(accepted()), About, SLOT(accept()));

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About", 0));
        icon->setText(QString());
        version->setText(QApplication::translate("About", "Version 0.1", 0));
        developer->setText(QApplication::translate("About", "Vicente Cunha", 0));
        company->setText(QApplication::translate("About", "INBRAMED 2016", 0));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
