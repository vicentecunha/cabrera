/********************************************************************************
** Form generated from reading UI file 'newpatient.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPATIENT_H
#define UI_NEWPATIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_NewPatient
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_sex;
    QLabel *label_dob;
    QComboBox *comboBox_sex;
    QFrame *line_1;
    QFrame *line_2;
    QFrame *line_3;
    QDateEdit *dobEdit;
    QLabel *label_name;
    QLineEdit *nameEdit;
    QLabel *label_id;
    QLineEdit *idEdit;
    QLabel *label_notes;
    QLineEdit *notesEdit;
    QFrame *line_4;
    QFrame *line_5;

    void setupUi(QDialog *NewPatient)
    {
        if (NewPatient->objectName().isEmpty())
            NewPatient->setObjectName(QStringLiteral("NewPatient"));
        NewPatient->resize(260, 300);
        buttonBox = new QDialogButtonBox(NewPatient);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(80, 260, 166, 31));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_sex = new QLabel(NewPatient);
        label_sex->setObjectName(QStringLiteral("label_sex"));
        label_sex->setGeometry(QRect(10, 110, 41, 31));
        QFont font;
        font.setPointSize(16);
        label_sex->setFont(font);
        label_dob = new QLabel(NewPatient);
        label_dob->setObjectName(QStringLiteral("label_dob"));
        label_dob->setGeometry(QRect(10, 160, 141, 31));
        label_dob->setFont(font);
        comboBox_sex = new QComboBox(NewPatient);
        comboBox_sex->setObjectName(QStringLiteral("comboBox_sex"));
        comboBox_sex->setGeometry(QRect(148, 110, 101, 31));
        line_1 = new QFrame(NewPatient);
        line_1->setObjectName(QStringLiteral("line_1"));
        line_1->setGeometry(QRect(0, 40, 261, 20));
        line_1->setFrameShape(QFrame::HLine);
        line_1->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(NewPatient);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 90, 261, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(NewPatient);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 140, 261, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        dobEdit = new QDateEdit(NewPatient);
        dobEdit->setObjectName(QStringLiteral("dobEdit"));
        dobEdit->setGeometry(QRect(150, 160, 101, 31));
        dobEdit->setCalendarPopup(true);
        label_name = new QLabel(NewPatient);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(10, 10, 81, 31));
        label_name->setFont(font);
        nameEdit = new QLineEdit(NewPatient);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(80, 10, 171, 31));
        label_id = new QLabel(NewPatient);
        label_id->setObjectName(QStringLiteral("label_id"));
        label_id->setGeometry(QRect(10, 60, 81, 31));
        label_id->setFont(font);
        idEdit = new QLineEdit(NewPatient);
        idEdit->setObjectName(QStringLiteral("idEdit"));
        idEdit->setGeometry(QRect(80, 60, 171, 31));
        label_notes = new QLabel(NewPatient);
        label_notes->setObjectName(QStringLiteral("label_notes"));
        label_notes->setGeometry(QRect(10, 210, 61, 31));
        label_notes->setFont(font);
        notesEdit = new QLineEdit(NewPatient);
        notesEdit->setObjectName(QStringLiteral("notesEdit"));
        notesEdit->setGeometry(QRect(80, 210, 171, 31));
        line_4 = new QFrame(NewPatient);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(0, 190, 261, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(NewPatient);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(0, 240, 261, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        retranslateUi(NewPatient);

        QMetaObject::connectSlotsByName(NewPatient);
    } // setupUi

    void retranslateUi(QDialog *NewPatient)
    {
        NewPatient->setWindowTitle(QApplication::translate("NewPatient", "New Patient", 0));
        label_sex->setText(QApplication::translate("NewPatient", "Sex", 0));
        label_dob->setText(QApplication::translate("NewPatient", "Date of Birth", 0));
        comboBox_sex->clear();
        comboBox_sex->insertItems(0, QStringList()
         << QApplication::translate("NewPatient", "Female", 0)
         << QApplication::translate("NewPatient", "Male", 0)
        );
        dobEdit->setDisplayFormat(QApplication::translate("NewPatient", "dd/MM/yyyy", 0));
        label_name->setText(QApplication::translate("NewPatient", "Name", 0));
        label_id->setText(QApplication::translate("NewPatient", "ID", 0));
        label_notes->setText(QApplication::translate("NewPatient", "Notes", 0));
        notesEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewPatient: public Ui_NewPatient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPATIENT_H
