/********************************************************************************
** Form generated from reading UI file 'vo2000interface.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VO2000INTERFACE_H
#define UI_VO2000INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_vo2000interface
{
public:
    QLabel *display;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_F;
    QPushButton *pushButton_6;
    QPushButton *pushButton_E;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_D;
    QPushButton *pushButton_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_B;
    QPushButton *pushButton_C;
    QPushButton *pushButton_0;
    QPushButton *pushButton_A;
    QComboBox *comboBox;
    QLabel *serialPort_lbl;
    QFrame *line;
    QDialogButtonBox *buttonBox;
    QFrame *line_2;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *vo2000interface)
    {
        if (vo2000interface->objectName().isEmpty())
            vo2000interface->setObjectName(QStringLiteral("vo2000interface"));
        vo2000interface->resize(600, 490);
        display = new QLabel(vo2000interface);
        display->setObjectName(QStringLiteral("display"));
        display->setGeometry(QRect(10, 10, 271, 101));
        QFont font;
        font.setPointSize(16);
        display->setFont(font);
        pushButton_7 = new QPushButton(vo2000interface);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setEnabled(false);
        pushButton_7->setGeometry(QRect(10, 120, 60, 60));
        pushButton_7->setFont(font);
        pushButton_8 = new QPushButton(vo2000interface);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setEnabled(false);
        pushButton_8->setGeometry(QRect(80, 120, 60, 60));
        pushButton_8->setFont(font);
        pushButton_9 = new QPushButton(vo2000interface);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setEnabled(false);
        pushButton_9->setGeometry(QRect(150, 120, 60, 60));
        pushButton_9->setFont(font);
        pushButton_F = new QPushButton(vo2000interface);
        pushButton_F->setObjectName(QStringLiteral("pushButton_F"));
        pushButton_F->setEnabled(false);
        pushButton_F->setGeometry(QRect(220, 120, 60, 60));
        pushButton_F->setFont(font);
        pushButton_6 = new QPushButton(vo2000interface);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setEnabled(false);
        pushButton_6->setGeometry(QRect(150, 190, 60, 60));
        pushButton_6->setFont(font);
        pushButton_E = new QPushButton(vo2000interface);
        pushButton_E->setObjectName(QStringLiteral("pushButton_E"));
        pushButton_E->setEnabled(false);
        pushButton_E->setGeometry(QRect(220, 190, 60, 60));
        pushButton_E->setFont(font);
        pushButton_5 = new QPushButton(vo2000interface);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setEnabled(false);
        pushButton_5->setGeometry(QRect(80, 190, 60, 60));
        pushButton_5->setFont(font);
        pushButton_4 = new QPushButton(vo2000interface);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setEnabled(false);
        pushButton_4->setGeometry(QRect(10, 190, 60, 60));
        pushButton_4->setFont(font);
        pushButton_3 = new QPushButton(vo2000interface);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setGeometry(QRect(150, 260, 60, 60));
        pushButton_3->setFont(font);
        pushButton_D = new QPushButton(vo2000interface);
        pushButton_D->setObjectName(QStringLiteral("pushButton_D"));
        pushButton_D->setEnabled(false);
        pushButton_D->setGeometry(QRect(220, 260, 60, 60));
        pushButton_D->setFont(font);
        pushButton_2 = new QPushButton(vo2000interface);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(80, 260, 60, 60));
        pushButton_2->setFont(font);
        pushButton_1 = new QPushButton(vo2000interface);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setEnabled(false);
        pushButton_1->setGeometry(QRect(10, 260, 60, 60));
        pushButton_1->setFont(font);
        pushButton_B = new QPushButton(vo2000interface);
        pushButton_B->setObjectName(QStringLiteral("pushButton_B"));
        pushButton_B->setEnabled(false);
        pushButton_B->setGeometry(QRect(150, 330, 60, 60));
        pushButton_B->setFont(font);
        pushButton_C = new QPushButton(vo2000interface);
        pushButton_C->setObjectName(QStringLiteral("pushButton_C"));
        pushButton_C->setEnabled(false);
        pushButton_C->setGeometry(QRect(220, 330, 60, 60));
        pushButton_C->setFont(font);
        pushButton_0 = new QPushButton(vo2000interface);
        pushButton_0->setObjectName(QStringLiteral("pushButton_0"));
        pushButton_0->setEnabled(false);
        pushButton_0->setGeometry(QRect(80, 330, 60, 60));
        pushButton_0->setFont(font);
        pushButton_A = new QPushButton(vo2000interface);
        pushButton_A->setObjectName(QStringLiteral("pushButton_A"));
        pushButton_A->setEnabled(false);
        pushButton_A->setGeometry(QRect(10, 330, 60, 60));
        pushButton_A->setFont(font);
        comboBox = new QComboBox(vo2000interface);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 420, 271, 21));
        serialPort_lbl = new QLabel(vo2000interface);
        serialPort_lbl->setObjectName(QStringLiteral("serialPort_lbl"));
        serialPort_lbl->setGeometry(QRect(10, 400, 71, 16));
        line = new QFrame(vo2000interface);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 390, 291, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        buttonBox = new QDialogButtonBox(vo2000interface);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setEnabled(true);
        buttonBox->setGeometry(QRect(15, 450, 261, 31));
        buttonBox->setStandardButtons(QDialogButtonBox::NoButton);
        line_2 = new QFrame(vo2000interface);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(280, 0, 20, 491));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        textBrowser = new QTextBrowser(vo2000interface);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(300, 10, 291, 461));

        retranslateUi(vo2000interface);

        QMetaObject::connectSlotsByName(vo2000interface);
    } // setupUi

    void retranslateUi(QDialog *vo2000interface)
    {
        vo2000interface->setWindowTitle(QApplication::translate("vo2000interface", "VO2000 Interface", 0));
        display->setText(QApplication::translate("vo2000interface", "Serial port is not open.\n"
"Please select a serial port\n"
"and press \"Open port\".", 0));
        pushButton_7->setText(QApplication::translate("vo2000interface", "7", 0));
        pushButton_8->setText(QApplication::translate("vo2000interface", "8", 0));
        pushButton_9->setText(QApplication::translate("vo2000interface", "9", 0));
        pushButton_F->setText(QApplication::translate("vo2000interface", "F", 0));
        pushButton_6->setText(QApplication::translate("vo2000interface", "6", 0));
        pushButton_E->setText(QApplication::translate("vo2000interface", "E", 0));
        pushButton_5->setText(QApplication::translate("vo2000interface", "5", 0));
        pushButton_4->setText(QApplication::translate("vo2000interface", "4", 0));
        pushButton_3->setText(QApplication::translate("vo2000interface", "3", 0));
        pushButton_D->setText(QApplication::translate("vo2000interface", "D", 0));
        pushButton_2->setText(QApplication::translate("vo2000interface", "2", 0));
        pushButton_1->setText(QApplication::translate("vo2000interface", "1", 0));
        pushButton_B->setText(QApplication::translate("vo2000interface", "B", 0));
        pushButton_C->setText(QApplication::translate("vo2000interface", "C", 0));
        pushButton_0->setText(QApplication::translate("vo2000interface", "0", 0));
        pushButton_A->setText(QApplication::translate("vo2000interface", "A", 0));
        serialPort_lbl->setText(QApplication::translate("vo2000interface", "Serial port:", 0));
        textBrowser->setHtml(QApplication::translate("vo2000interface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">   HR     VO2     VCO2     VE     FO2     FCO2</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">==========================</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class vo2000interface: public Ui_vo2000interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VO2000INTERFACE_H
