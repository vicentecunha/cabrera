/********************************************************************************
** Form generated from reading UI file 'newanamnesis.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWANAMNESIS_H
#define UI_NEWANAMNESIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewAnamnesis
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_patient;
    QLabel *label_name;
    QLabel *label_sex;
    QLabel *label_dob;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_ID;
    QLabel *label_id;
    QComboBox *comboBox_sex;
    QDateEdit *dateEdit;
    QLabel *label_name_height;
    QLabel *label_name_weight;
    QDoubleSpinBox *doubleSpinBox_height;
    QDoubleSpinBox *doubleSpinBox_weight;
    QLabel *label_name_heightUnit;
    QLabel *label_name_weightUnit;
    QPushButton *pushButton;
    QLineEdit *lineEdit_notes;
    QLabel *label_notes;
    QWidget *tab_cc;
    QLabel *label_chiefComplaint;
    QPlainTextEdit *plainTextEdit_chiefComplaint;
    QPlainTextEdit *plainTextEdit_historyPresentIllness;
    QLabel *label_historyPresentIllness;
    QPlainTextEdit *plainTextEdit_pastMedicalHistory;
    QLabel *label_pastMedicalHistory;
    QWidget *tab_ros;
    QLabel *label_cardiovascular;
    QPlainTextEdit *plainTextEdit_cardiovascular;
    QPlainTextEdit *plainTextEdit_respiratory;
    QLabel *label_respiratory;
    QPlainTextEdit *plainTextEdit_gastrointestinal;
    QLabel *label_gastrointestinal;
    QPlainTextEdit *plainTextEdit_genitourinary;
    QLabel *label_genitourinary;
    QPlainTextEdit *plainTextEdit_nervous;
    QLabel *label_nervous;
    QPlainTextEdit *plainTextEdit_cranial;
    QLabel *label_cranial;
    QPlainTextEdit *plainTextEdit_endocrine;
    QLabel *label_endocrine;
    QPlainTextEdit *plainTextEdit_musculoskeletal;
    QLabel *label_musculoskeletal;
    QPlainTextEdit *plainTextEdit_skin;
    QLabel *label_skin;
    QWidget *tab_other1;
    QLabel *label_family;
    QPlainTextEdit *plainTextEdit_family;
    QPlainTextEdit *plainTextEdit_childhood;
    QLabel *label_childhood;
    QLabel *label_social;
    QPlainTextEdit *plainTextEdit_social;
    QWidget *tab_other2;
    QLabel *label_medications;
    QPlainTextEdit *plainTextEdit_medications;
    QLabel *label_sexual;
    QPlainTextEdit *plainTextEdit_sexual;
    QLabel *label_allergies;
    QPlainTextEdit *plainTextEdit_allergies;
    QWidget *conclusion;
    QPlainTextEdit *plainTextEdit_conclusion;
    QLabel *label_conclusion;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewAnamnesis)
    {
        if (NewAnamnesis->objectName().isEmpty())
            NewAnamnesis->setObjectName(QStringLiteral("NewAnamnesis"));
        NewAnamnesis->resize(530, 630);
        tabWidget = new QTabWidget(NewAnamnesis);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 531, 581));
        tab_patient = new QWidget();
        tab_patient->setObjectName(QStringLiteral("tab_patient"));
        label_name = new QLabel(tab_patient);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(0, 10, 81, 31));
        label_name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_sex = new QLabel(tab_patient);
        label_sex->setObjectName(QStringLiteral("label_sex"));
        label_sex->setGeometry(QRect(0, 90, 81, 31));
        label_sex->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_dob = new QLabel(tab_patient);
        label_dob->setObjectName(QStringLiteral("label_dob"));
        label_dob->setGeometry(QRect(0, 130, 81, 31));
        label_dob->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_name = new QLineEdit(tab_patient);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(90, 10, 251, 31));
        lineEdit_ID = new QLineEdit(tab_patient);
        lineEdit_ID->setObjectName(QStringLiteral("lineEdit_ID"));
        lineEdit_ID->setGeometry(QRect(90, 50, 251, 31));
        label_id = new QLabel(tab_patient);
        label_id->setObjectName(QStringLiteral("label_id"));
        label_id->setGeometry(QRect(0, 50, 81, 31));
        label_id->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_sex = new QComboBox(tab_patient);
        comboBox_sex->setObjectName(QStringLiteral("comboBox_sex"));
        comboBox_sex->setGeometry(QRect(90, 90, 101, 31));
        dateEdit = new QDateEdit(tab_patient);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(90, 130, 101, 31));
        label_name_height = new QLabel(tab_patient);
        label_name_height->setObjectName(QStringLiteral("label_name_height"));
        label_name_height->setGeometry(QRect(0, 210, 81, 31));
        label_name_height->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_name_weight = new QLabel(tab_patient);
        label_name_weight->setObjectName(QStringLiteral("label_name_weight"));
        label_name_weight->setGeometry(QRect(0, 250, 81, 31));
        label_name_weight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_height = new QDoubleSpinBox(tab_patient);
        doubleSpinBox_height->setObjectName(QStringLiteral("doubleSpinBox_height"));
        doubleSpinBox_height->setGeometry(QRect(90, 210, 66, 31));
        doubleSpinBox_height->setSingleStep(0.1);
        doubleSpinBox_weight = new QDoubleSpinBox(tab_patient);
        doubleSpinBox_weight->setObjectName(QStringLiteral("doubleSpinBox_weight"));
        doubleSpinBox_weight->setGeometry(QRect(90, 250, 66, 31));
        doubleSpinBox_weight->setSingleStep(1);
        label_name_heightUnit = new QLabel(tab_patient);
        label_name_heightUnit->setObjectName(QStringLiteral("label_name_heightUnit"));
        label_name_heightUnit->setGeometry(QRect(160, 210, 21, 31));
        label_name_heightUnit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_name_weightUnit = new QLabel(tab_patient);
        label_name_weightUnit->setObjectName(QStringLiteral("label_name_weightUnit"));
        label_name_weightUnit->setGeometry(QRect(160, 250, 21, 31));
        label_name_weightUnit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton = new QPushButton(tab_patient);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 230, 101, 41));
        lineEdit_notes = new QLineEdit(tab_patient);
        lineEdit_notes->setObjectName(QStringLiteral("lineEdit_notes"));
        lineEdit_notes->setGeometry(QRect(90, 170, 251, 31));
        label_notes = new QLabel(tab_patient);
        label_notes->setObjectName(QStringLiteral("label_notes"));
        label_notes->setGeometry(QRect(0, 170, 81, 31));
        label_notes->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tabWidget->addTab(tab_patient, QString());
        tab_cc = new QWidget();
        tab_cc->setObjectName(QStringLiteral("tab_cc"));
        label_chiefComplaint = new QLabel(tab_cc);
        label_chiefComplaint->setObjectName(QStringLiteral("label_chiefComplaint"));
        label_chiefComplaint->setGeometry(QRect(10, 10, 131, 16));
        plainTextEdit_chiefComplaint = new QPlainTextEdit(tab_cc);
        plainTextEdit_chiefComplaint->setObjectName(QStringLiteral("plainTextEdit_chiefComplaint"));
        plainTextEdit_chiefComplaint->setGeometry(QRect(10, 30, 511, 151));
        plainTextEdit_historyPresentIllness = new QPlainTextEdit(tab_cc);
        plainTextEdit_historyPresentIllness->setObjectName(QStringLiteral("plainTextEdit_historyPresentIllness"));
        plainTextEdit_historyPresentIllness->setGeometry(QRect(10, 210, 511, 151));
        label_historyPresentIllness = new QLabel(tab_cc);
        label_historyPresentIllness->setObjectName(QStringLiteral("label_historyPresentIllness"));
        label_historyPresentIllness->setGeometry(QRect(10, 190, 211, 16));
        plainTextEdit_pastMedicalHistory = new QPlainTextEdit(tab_cc);
        plainTextEdit_pastMedicalHistory->setObjectName(QStringLiteral("plainTextEdit_pastMedicalHistory"));
        plainTextEdit_pastMedicalHistory->setGeometry(QRect(10, 390, 511, 151));
        label_pastMedicalHistory = new QLabel(tab_cc);
        label_pastMedicalHistory->setObjectName(QStringLiteral("label_pastMedicalHistory"));
        label_pastMedicalHistory->setGeometry(QRect(10, 370, 171, 16));
        tabWidget->addTab(tab_cc, QString());
        tab_ros = new QWidget();
        tab_ros->setObjectName(QStringLiteral("tab_ros"));
        label_cardiovascular = new QLabel(tab_ros);
        label_cardiovascular->setObjectName(QStringLiteral("label_cardiovascular"));
        label_cardiovascular->setGeometry(QRect(10, 10, 141, 16));
        plainTextEdit_cardiovascular = new QPlainTextEdit(tab_ros);
        plainTextEdit_cardiovascular->setObjectName(QStringLiteral("plainTextEdit_cardiovascular"));
        plainTextEdit_cardiovascular->setGeometry(QRect(10, 30, 511, 31));
        plainTextEdit_respiratory = new QPlainTextEdit(tab_ros);
        plainTextEdit_respiratory->setObjectName(QStringLiteral("plainTextEdit_respiratory"));
        plainTextEdit_respiratory->setGeometry(QRect(10, 90, 511, 31));
        label_respiratory = new QLabel(tab_ros);
        label_respiratory->setObjectName(QStringLiteral("label_respiratory"));
        label_respiratory->setGeometry(QRect(10, 70, 141, 16));
        plainTextEdit_gastrointestinal = new QPlainTextEdit(tab_ros);
        plainTextEdit_gastrointestinal->setObjectName(QStringLiteral("plainTextEdit_gastrointestinal"));
        plainTextEdit_gastrointestinal->setGeometry(QRect(10, 150, 511, 31));
        label_gastrointestinal = new QLabel(tab_ros);
        label_gastrointestinal->setObjectName(QStringLiteral("label_gastrointestinal"));
        label_gastrointestinal->setGeometry(QRect(10, 130, 151, 16));
        plainTextEdit_genitourinary = new QPlainTextEdit(tab_ros);
        plainTextEdit_genitourinary->setObjectName(QStringLiteral("plainTextEdit_genitourinary"));
        plainTextEdit_genitourinary->setGeometry(QRect(10, 210, 511, 31));
        label_genitourinary = new QLabel(tab_ros);
        label_genitourinary->setObjectName(QStringLiteral("label_genitourinary"));
        label_genitourinary->setGeometry(QRect(10, 190, 141, 16));
        plainTextEdit_nervous = new QPlainTextEdit(tab_ros);
        plainTextEdit_nervous->setObjectName(QStringLiteral("plainTextEdit_nervous"));
        plainTextEdit_nervous->setGeometry(QRect(10, 270, 511, 31));
        label_nervous = new QLabel(tab_ros);
        label_nervous->setObjectName(QStringLiteral("label_nervous"));
        label_nervous->setGeometry(QRect(10, 250, 141, 16));
        plainTextEdit_cranial = new QPlainTextEdit(tab_ros);
        plainTextEdit_cranial->setObjectName(QStringLiteral("plainTextEdit_cranial"));
        plainTextEdit_cranial->setGeometry(QRect(10, 330, 511, 31));
        label_cranial = new QLabel(tab_ros);
        label_cranial->setObjectName(QStringLiteral("label_cranial"));
        label_cranial->setGeometry(QRect(10, 310, 171, 16));
        plainTextEdit_endocrine = new QPlainTextEdit(tab_ros);
        plainTextEdit_endocrine->setObjectName(QStringLiteral("plainTextEdit_endocrine"));
        plainTextEdit_endocrine->setGeometry(QRect(10, 390, 511, 31));
        label_endocrine = new QLabel(tab_ros);
        label_endocrine->setObjectName(QStringLiteral("label_endocrine"));
        label_endocrine->setGeometry(QRect(10, 370, 171, 16));
        plainTextEdit_musculoskeletal = new QPlainTextEdit(tab_ros);
        plainTextEdit_musculoskeletal->setObjectName(QStringLiteral("plainTextEdit_musculoskeletal"));
        plainTextEdit_musculoskeletal->setGeometry(QRect(10, 450, 511, 31));
        label_musculoskeletal = new QLabel(tab_ros);
        label_musculoskeletal->setObjectName(QStringLiteral("label_musculoskeletal"));
        label_musculoskeletal->setGeometry(QRect(10, 430, 171, 16));
        plainTextEdit_skin = new QPlainTextEdit(tab_ros);
        plainTextEdit_skin->setObjectName(QStringLiteral("plainTextEdit_skin"));
        plainTextEdit_skin->setGeometry(QRect(10, 510, 511, 31));
        label_skin = new QLabel(tab_ros);
        label_skin->setObjectName(QStringLiteral("label_skin"));
        label_skin->setGeometry(QRect(10, 490, 171, 16));
        tabWidget->addTab(tab_ros, QString());
        tab_other1 = new QWidget();
        tab_other1->setObjectName(QStringLiteral("tab_other1"));
        label_family = new QLabel(tab_other1);
        label_family->setObjectName(QStringLiteral("label_family"));
        label_family->setGeometry(QRect(10, 10, 101, 16));
        plainTextEdit_family = new QPlainTextEdit(tab_other1);
        plainTextEdit_family->setObjectName(QStringLiteral("plainTextEdit_family"));
        plainTextEdit_family->setGeometry(QRect(10, 30, 511, 151));
        plainTextEdit_childhood = new QPlainTextEdit(tab_other1);
        plainTextEdit_childhood->setObjectName(QStringLiteral("plainTextEdit_childhood"));
        plainTextEdit_childhood->setGeometry(QRect(10, 210, 511, 151));
        label_childhood = new QLabel(tab_other1);
        label_childhood->setObjectName(QStringLiteral("label_childhood"));
        label_childhood->setGeometry(QRect(10, 190, 131, 16));
        label_social = new QLabel(tab_other1);
        label_social->setObjectName(QStringLiteral("label_social"));
        label_social->setGeometry(QRect(10, 370, 91, 16));
        plainTextEdit_social = new QPlainTextEdit(tab_other1);
        plainTextEdit_social->setObjectName(QStringLiteral("plainTextEdit_social"));
        plainTextEdit_social->setGeometry(QRect(10, 390, 511, 151));
        tabWidget->addTab(tab_other1, QString());
        tab_other2 = new QWidget();
        tab_other2->setObjectName(QStringLiteral("tab_other2"));
        label_medications = new QLabel(tab_other2);
        label_medications->setObjectName(QStringLiteral("label_medications"));
        label_medications->setGeometry(QRect(10, 10, 91, 16));
        plainTextEdit_medications = new QPlainTextEdit(tab_other2);
        plainTextEdit_medications->setObjectName(QStringLiteral("plainTextEdit_medications"));
        plainTextEdit_medications->setGeometry(QRect(10, 30, 511, 151));
        label_sexual = new QLabel(tab_other2);
        label_sexual->setObjectName(QStringLiteral("label_sexual"));
        label_sexual->setGeometry(QRect(10, 370, 101, 16));
        plainTextEdit_sexual = new QPlainTextEdit(tab_other2);
        plainTextEdit_sexual->setObjectName(QStringLiteral("plainTextEdit_sexual"));
        plainTextEdit_sexual->setGeometry(QRect(10, 390, 511, 151));
        label_allergies = new QLabel(tab_other2);
        label_allergies->setObjectName(QStringLiteral("label_allergies"));
        label_allergies->setGeometry(QRect(10, 190, 91, 16));
        plainTextEdit_allergies = new QPlainTextEdit(tab_other2);
        plainTextEdit_allergies->setObjectName(QStringLiteral("plainTextEdit_allergies"));
        plainTextEdit_allergies->setGeometry(QRect(10, 210, 511, 151));
        tabWidget->addTab(tab_other2, QString());
        conclusion = new QWidget();
        conclusion->setObjectName(QStringLiteral("conclusion"));
        plainTextEdit_conclusion = new QPlainTextEdit(conclusion);
        plainTextEdit_conclusion->setObjectName(QStringLiteral("plainTextEdit_conclusion"));
        plainTextEdit_conclusion->setGeometry(QRect(10, 30, 511, 511));
        label_conclusion = new QLabel(conclusion);
        label_conclusion->setObjectName(QStringLiteral("label_conclusion"));
        label_conclusion->setGeometry(QRect(10, 10, 81, 16));
        tabWidget->addTab(conclusion, QString());
        buttonBox = new QDialogButtonBox(NewAnamnesis);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(350, 590, 166, 31));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(NewAnamnesis);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(NewAnamnesis);
    } // setupUi

    void retranslateUi(QDialog *NewAnamnesis)
    {
        NewAnamnesis->setWindowTitle(QApplication::translate("NewAnamnesis", "Anamnesis", 0));
        label_name->setText(QApplication::translate("NewAnamnesis", "Name", 0));
        label_sex->setText(QApplication::translate("NewAnamnesis", "Sex", 0));
        label_dob->setText(QApplication::translate("NewAnamnesis", "Date of Birth", 0));
        label_id->setText(QApplication::translate("NewAnamnesis", "ID", 0));
        comboBox_sex->clear();
        comboBox_sex->insertItems(0, QStringList()
         << QApplication::translate("NewAnamnesis", "Female", 0)
         << QApplication::translate("NewAnamnesis", "Male", 0)
        );
        dateEdit->setDisplayFormat(QApplication::translate("NewAnamnesis", "dd/MM/yyyy", 0));
        label_name_height->setText(QApplication::translate("NewAnamnesis", "Height", 0));
        label_name_weight->setText(QApplication::translate("NewAnamnesis", "Weight", 0));
        label_name_heightUnit->setText(QApplication::translate("NewAnamnesis", "m", 0));
        label_name_weightUnit->setText(QApplication::translate("NewAnamnesis", "kg", 0));
        pushButton->setText(QApplication::translate("NewAnamnesis", "Load Patient...", 0));
        label_notes->setText(QApplication::translate("NewAnamnesis", "Notes", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_patient), QApplication::translate("NewAnamnesis", "Identification", 0));
        label_chiefComplaint->setText(QApplication::translate("NewAnamnesis", "Chief Complaint (CC)", 0));
        plainTextEdit_chiefComplaint->setPlainText(QString());
        plainTextEdit_historyPresentIllness->setPlainText(QString());
        label_historyPresentIllness->setText(QApplication::translate("NewAnamnesis", "History of the Present Illness (HPI)", 0));
        plainTextEdit_pastMedicalHistory->setPlainText(QString());
        label_pastMedicalHistory->setText(QApplication::translate("NewAnamnesis", "Past Medical History (PMH)", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_cc), QApplication::translate("NewAnamnesis", "CC/HPI/PMH", 0));
        label_cardiovascular->setText(QApplication::translate("NewAnamnesis", "Cardiovascular System", 0));
        label_respiratory->setText(QApplication::translate("NewAnamnesis", "Respiratory System", 0));
        label_gastrointestinal->setText(QApplication::translate("NewAnamnesis", "Gastrointestinal System", 0));
        label_genitourinary->setText(QApplication::translate("NewAnamnesis", "Genitourinary System", 0));
        label_nervous->setText(QApplication::translate("NewAnamnesis", "Nervous System", 0));
        label_cranial->setText(QApplication::translate("NewAnamnesis", "Cranial Nerves Symptoms", 0));
        label_endocrine->setText(QApplication::translate("NewAnamnesis", "Endocrine System", 0));
        label_musculoskeletal->setText(QApplication::translate("NewAnamnesis", "Musculoskeletal System", 0));
        label_skin->setText(QApplication::translate("NewAnamnesis", "Skin", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_ros), QApplication::translate("NewAnamnesis", "ROS", 0));
        label_family->setText(QApplication::translate("NewAnamnesis", "Family Diseases", 0));
        label_childhood->setText(QApplication::translate("NewAnamnesis", "Childhood Diseases", 0));
        label_social->setText(QApplication::translate("NewAnamnesis", "Social History", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_other1), QApplication::translate("NewAnamnesis", "Other Info 1", 0));
        label_medications->setText(QApplication::translate("NewAnamnesis", "Medications", 0));
        label_sexual->setText(QApplication::translate("NewAnamnesis", "Sexual History", 0));
        label_allergies->setText(QApplication::translate("NewAnamnesis", "Allergies", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_other2), QApplication::translate("NewAnamnesis", "Other Info 2", 0));
        label_conclusion->setText(QApplication::translate("NewAnamnesis", "Conclusion", 0));
        tabWidget->setTabText(tabWidget->indexOf(conclusion), QApplication::translate("NewAnamnesis", "Conclusion", 0));
    } // retranslateUi

};

namespace Ui {
    class NewAnamnesis: public Ui_NewAnamnesis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWANAMNESIS_H
