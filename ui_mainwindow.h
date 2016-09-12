/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_About;
    QAction *action_vo2000Interface;
    QAction *action_vo2000Interface_2;
    QAction *action_newPatient;
    QAction *action_newPatient_2;
    QAction *action_openPatient;
    QAction *action_editPatient;
    QAction *action_openPatient_2;
    QAction *action_null;
    QAction *action_newAnamnesis_2;
    QAction *action_newAnamnesis;
    QAction *action_openAnamnesis;
    QAction *action_openAnamnesis_2;
    QAction *action_closePatient;
    QAction *action_closeAnamnesis;
    QAction *action_placeholderRP;
    QAction *action_placeholderRA;
    QAction *action_edtAnamnesis;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *patientTab;
    QLabel *patientLabel;
    QWidget *tab;
    QTextBrowser *textBrowser_anamnesis;
    QLabel *watermark;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuNew;
    QMenu *menuOpen;
    QMenu *menuClose_patient;
    QMenu *menuRecent;
    QMenu *menu_recentPatients;
    QMenu *menu_recentAnamnesis;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuTools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QStringLiteral("action_About"));
        action_vo2000Interface = new QAction(MainWindow);
        action_vo2000Interface->setObjectName(QStringLiteral("action_vo2000Interface"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/vo2000.png"), QSize(), QIcon::Normal, QIcon::On);
        action_vo2000Interface->setIcon(icon);
        action_vo2000Interface_2 = new QAction(MainWindow);
        action_vo2000Interface_2->setObjectName(QStringLiteral("action_vo2000Interface_2"));
        action_vo2000Interface_2->setIcon(icon);
        action_newPatient = new QAction(MainWindow);
        action_newPatient->setObjectName(QStringLiteral("action_newPatient"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/new-patient-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_newPatient->setIcon(icon1);
        action_newPatient_2 = new QAction(MainWindow);
        action_newPatient_2->setObjectName(QStringLiteral("action_newPatient_2"));
        action_newPatient_2->setIcon(icon1);
        action_openPatient = new QAction(MainWindow);
        action_openPatient->setObjectName(QStringLiteral("action_openPatient"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/open-patient-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_openPatient->setIcon(icon2);
        action_editPatient = new QAction(MainWindow);
        action_editPatient->setObjectName(QStringLiteral("action_editPatient"));
        action_openPatient_2 = new QAction(MainWindow);
        action_openPatient_2->setObjectName(QStringLiteral("action_openPatient_2"));
        action_openPatient_2->setIcon(icon2);
        action_null = new QAction(MainWindow);
        action_null->setObjectName(QStringLiteral("action_null"));
        action_newAnamnesis_2 = new QAction(MainWindow);
        action_newAnamnesis_2->setObjectName(QStringLiteral("action_newAnamnesis_2"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/anamnesis-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_newAnamnesis_2->setIcon(icon3);
        action_newAnamnesis = new QAction(MainWindow);
        action_newAnamnesis->setObjectName(QStringLiteral("action_newAnamnesis"));
        action_newAnamnesis->setIcon(icon3);
        action_openAnamnesis = new QAction(MainWindow);
        action_openAnamnesis->setObjectName(QStringLiteral("action_openAnamnesis"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/anamnesis-open-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_openAnamnesis->setIcon(icon4);
        action_openAnamnesis_2 = new QAction(MainWindow);
        action_openAnamnesis_2->setObjectName(QStringLiteral("action_openAnamnesis_2"));
        action_openAnamnesis_2->setIcon(icon4);
        action_closePatient = new QAction(MainWindow);
        action_closePatient->setObjectName(QStringLiteral("action_closePatient"));
        action_closeAnamnesis = new QAction(MainWindow);
        action_closeAnamnesis->setObjectName(QStringLiteral("action_closeAnamnesis"));
        action_placeholderRP = new QAction(MainWindow);
        action_placeholderRP->setObjectName(QStringLiteral("action_placeholderRP"));
        action_placeholderRA = new QAction(MainWindow);
        action_placeholderRA->setObjectName(QStringLiteral("action_placeholderRA"));
        action_edtAnamnesis = new QAction(MainWindow);
        action_edtAnamnesis->setObjectName(QStringLiteral("action_edtAnamnesis"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 411, 501));
        patientTab = new QWidget();
        patientTab->setObjectName(QStringLiteral("patientTab"));
        patientLabel = new QLabel(patientTab);
        patientLabel->setObjectName(QStringLiteral("patientLabel"));
        patientLabel->setGeometry(QRect(10, 8, 391, 471));
        patientLabel->setWordWrap(true);
        tabWidget->addTab(patientTab, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        textBrowser_anamnesis = new QTextBrowser(tab);
        textBrowser_anamnesis->setObjectName(QStringLiteral("textBrowser_anamnesis"));
        textBrowser_anamnesis->setGeometry(QRect(10, 10, 391, 461));
        tabWidget->addTab(tab, QString());
        watermark = new QLabel(centralWidget);
        watermark->setObjectName(QStringLiteral("watermark"));
        watermark->setGeometry(QRect(430, 30, 362, 471));
        watermark->setPixmap(QPixmap(QString::fromUtf8(":/img/inbramed-watermark.png")));
        watermark->setScaledContents(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuNew = new QMenu(menuFile);
        menuNew->setObjectName(QStringLiteral("menuNew"));
        menuOpen = new QMenu(menuFile);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        menuClose_patient = new QMenu(menuFile);
        menuClose_patient->setObjectName(QStringLiteral("menuClose_patient"));
        menuRecent = new QMenu(menuFile);
        menuRecent->setObjectName(QStringLiteral("menuRecent"));
        menu_recentPatients = new QMenu(menuRecent);
        menu_recentPatients->setObjectName(QStringLiteral("menu_recentPatients"));
        menu_recentAnamnesis = new QMenu(menuRecent);
        menu_recentAnamnesis->setObjectName(QStringLiteral("menu_recentAnamnesis"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMovable(true);
        mainToolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(menuNew->menuAction());
        menuFile->addAction(menuOpen->menuAction());
        menuFile->addAction(menuRecent->menuAction());
        menuFile->addAction(menuClose_patient->menuAction());
        menuNew->addAction(action_newPatient);
        menuNew->addAction(action_newAnamnesis);
        menuOpen->addAction(action_openPatient);
        menuOpen->addAction(action_openAnamnesis);
        menuClose_patient->addAction(action_closePatient);
        menuClose_patient->addAction(action_closeAnamnesis);
        menuRecent->addAction(menu_recentPatients->menuAction());
        menuRecent->addAction(menu_recentAnamnesis->menuAction());
        menu_recentPatients->addAction(action_placeholderRP);
        menu_recentAnamnesis->addAction(action_placeholderRA);
        menuEdit->addAction(action_editPatient);
        menuEdit->addAction(action_edtAnamnesis);
        menuHelp->addAction(action_About);
        menuTools->addAction(action_vo2000Interface);
        mainToolBar->addAction(action_newPatient_2);
        mainToolBar->addAction(action_openPatient_2);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_newAnamnesis_2);
        mainToolBar->addAction(action_openAnamnesis_2);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_vo2000Interface_2);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "INBRAMED Cabrera", 0));
        action_About->setText(QApplication::translate("MainWindow", "About...", 0));
        action_vo2000Interface->setText(QApplication::translate("MainWindow", "VO2000 interface...", 0));
        action_vo2000Interface_2->setText(QApplication::translate("MainWindow", "VO2000 interface...", 0));
        action_newPatient->setText(QApplication::translate("MainWindow", "New patient...", 0));
        action_newPatient_2->setText(QApplication::translate("MainWindow", "New patient...", 0));
        action_openPatient->setText(QApplication::translate("MainWindow", "Open patient...", 0));
        action_editPatient->setText(QApplication::translate("MainWindow", "Edit patient...", 0));
        action_openPatient_2->setText(QApplication::translate("MainWindow", "Open patient...", 0));
        action_null->setText(QApplication::translate("MainWindow", "<null>", 0));
        action_newAnamnesis_2->setText(QApplication::translate("MainWindow", "New anamnesis...", 0));
#ifndef QT_NO_TOOLTIP
        action_newAnamnesis_2->setToolTip(QApplication::translate("MainWindow", "New anamnesis", 0));
#endif // QT_NO_TOOLTIP
        action_newAnamnesis->setText(QApplication::translate("MainWindow", "New anamnesis...", 0));
#ifndef QT_NO_TOOLTIP
        action_newAnamnesis->setToolTip(QApplication::translate("MainWindow", "New anamnesis", 0));
#endif // QT_NO_TOOLTIP
        action_openAnamnesis->setText(QApplication::translate("MainWindow", "Open anamnesis...", 0));
#ifndef QT_NO_TOOLTIP
        action_openAnamnesis->setToolTip(QApplication::translate("MainWindow", "Open anamnesis", 0));
#endif // QT_NO_TOOLTIP
        action_openAnamnesis_2->setText(QApplication::translate("MainWindow", "Open anamnesis...", 0));
#ifndef QT_NO_TOOLTIP
        action_openAnamnesis_2->setToolTip(QApplication::translate("MainWindow", "Open anamnesis", 0));
#endif // QT_NO_TOOLTIP
        action_closePatient->setText(QApplication::translate("MainWindow", "Close Patient", 0));
        action_closeAnamnesis->setText(QApplication::translate("MainWindow", "Close Anamnesis", 0));
        action_placeholderRP->setText(QApplication::translate("MainWindow", "<null>", 0));
        action_placeholderRA->setText(QApplication::translate("MainWindow", "<null>", 0));
        action_edtAnamnesis->setText(QApplication::translate("MainWindow", "Edit anamnesis...", 0));
        patientLabel->setText(QApplication::translate("MainWindow", "No patient open.", 0));
        tabWidget->setTabText(tabWidget->indexOf(patientTab), QApplication::translate("MainWindow", "Patient", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Anamnesis", 0));
        watermark->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menuNew->setTitle(QApplication::translate("MainWindow", "New...", 0));
        menuOpen->setTitle(QApplication::translate("MainWindow", "Open...", 0));
        menuClose_patient->setTitle(QApplication::translate("MainWindow", "Close...", 0));
        menuRecent->setTitle(QApplication::translate("MainWindow", "Recent...", 0));
        menu_recentPatients->setTitle(QApplication::translate("MainWindow", "Patients...", 0));
        menu_recentAnamnesis->setTitle(QApplication::translate("MainWindow", "Anamnesis...", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "&Tools", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
