/*
 * Cabrera: editanamnesis.cpp
 * Author: Vicente Cunha
 * Date: July 2016
 */

// ==================================================
// INCLUDES
// ==================================================

#include "editanamnesis.h"
#include "ui_newanamnesis.h"
#include "newanamnesis.h"
#include "newpatient.h"
#include "mainwindow.h"
#include "constants.h"
#include <QFileDialog>
#include <QDebug>

// ==================================================
// CONSTRUCTORS AND DESTRUCTOR
// ==================================================

EditAnamnesis::EditAnamnesis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewAnamnesis)
{
    ui->setupUi(this);
    QWidget::setFixedSize(this->size());
    QDialog::setWindowTitle("Edit anamnesis");

    connect(ui->pushButton, SIGNAL(clicked()),  this, SLOT(loadPatient()));
    connect(ui->buttonBox,  SIGNAL(accepted()), this, SLOT(editAnamnesis()));
    connect(ui->buttonBox,  SIGNAL(rejected()), this, SLOT(reject()));
}

EditAnamnesis::~EditAnamnesis()
{
    delete ui;
}

// ==================================================
// PRIVATE FUNCTIONS
// ==================================================

/*
 * Update patient info.
 */

void EditAnamnesis::updatePatient(Patient* patient)
{
    if (!patient->isInvalid)
    {
        ui->lineEdit_name->setText(patient->getName());
        ui->lineEdit_ID->setText(patient->getIdStr());
        if      (patient->getSex() == Patient::FEMALE) ui->comboBox_sex->setCurrentIndex(0);
        else if (patient->getSex() == Patient::MALE)   ui->comboBox_sex->setCurrentIndex(1);
        ui->dateEdit->setDate(patient->getBirthday());
        ui->lineEdit_notes->setText(patient->getNotes());
    }
}

/*
 * Load patient info from file.
 */

void EditAnamnesis::loadPatient()
{
    QFileDialog* fileDialog = new QFileDialog(this, "Open Patient", "", "Patient file (*"+PATIENT_EXT+")");
    fileDialog->setFileMode(QFileDialog::ExistingFile);
    if (fileDialog->exec())
    {
        QString filename = fileDialog->selectedFiles()[0];
        Patient patient = MainWindow::parsePatient(filename);
        updatePatient(&patient);
    }
    delete fileDialog;
}

/*
 * Create new anamnesis and send accept signal.
 */

void EditAnamnesis::editAnamnesis()
{
    QStringList stringList;
    stringList.append(ui->plainTextEdit_chiefComplaint->toPlainText());
    stringList.append(ui->plainTextEdit_historyPresentIllness->toPlainText());
    stringList.append(ui->plainTextEdit_pastMedicalHistory->toPlainText());
    stringList.append(ui->plainTextEdit_cardiovascular->toPlainText());
    stringList.append(ui->plainTextEdit_cardiovascular->toPlainText());
    stringList.append(ui->plainTextEdit_respiratory->toPlainText());
    stringList.append(ui->plainTextEdit_gastrointestinal->toPlainText());
    stringList.append(ui->plainTextEdit_nervous->toPlainText());
    stringList.append(ui->plainTextEdit_cranial->toPlainText());
    stringList.append(ui->plainTextEdit_endocrine->toPlainText());
    stringList.append(ui->plainTextEdit_musculoskeletal->toPlainText());
    stringList.append(ui->plainTextEdit_skin->toPlainText());
    stringList.append(ui->plainTextEdit_family->toPlainText());
    stringList.append(ui->plainTextEdit_childhood->toPlainText());
    stringList.append(ui->plainTextEdit_social->toPlainText());
    stringList.append(ui->plainTextEdit_medications->toPlainText());
    stringList.append(ui->plainTextEdit_allergies->toPlainText());
    stringList.append(ui->plainTextEdit_sexual->toPlainText());
    stringList.append(ui->plainTextEdit_conclusion->toPlainText());

    Anamnesis anamnesis(ui->lineEdit_name->text(),
                        ui->lineEdit_ID->text(),
                        NewPatient::getSex(ui->comboBox_sex),
                        ui->dateEdit->date(),
                        ui->lineEdit_notes->text(),
                        ui->doubleSpinBox_height->value(),
                        ui->doubleSpinBox_weight->value(),
                        stringList);

    if (!anamnesis.isInvalid)
    {
        this->anamnesis = anamnesis;
        this->accept();
    }
}

// ==================================================
// PUBLIC FUNCTIONS
// ==================================================

void EditAnamnesis::updateAnamnesis(Anamnesis* anamnesis)
{
    if (!anamnesis->isInvalid)
    {
        ui->lineEdit_name->setText(anamnesis->getName());
        ui->lineEdit_ID->setText(anamnesis->getIdStr());
        if (anamnesis->getSex() == Patient::FEMALE)
            ui->comboBox_sex->setCurrentIndex(0);
        else ui->comboBox_sex->setCurrentIndex(1);
        ui->dateEdit->setDate(anamnesis->getBirthday());
        ui->lineEdit_notes->setText(anamnesis->getNotes());
        ui->doubleSpinBox_height->setValue(anamnesis->getHeight());
        ui->doubleSpinBox_weight->setValue(anamnesis->getWeight());
        ui->plainTextEdit_allergies->setPlainText(anamnesis->getAllergies());
        ui->plainTextEdit_cardiovascular->setPlainText(anamnesis->getROScardio());
        ui->plainTextEdit_chiefComplaint->setPlainText(anamnesis->getCC());
        ui->plainTextEdit_childhood->setPlainText(anamnesis->getChildhood());
        ui->plainTextEdit_conclusion->setPlainText(anamnesis->getConclusion());
        ui->plainTextEdit_cranial->setPlainText(anamnesis->getROScran());
        ui->plainTextEdit_endocrine->setPlainText(anamnesis->getROSendo());
        ui->plainTextEdit_family->setPlainText(anamnesis->getFamily());
        ui->plainTextEdit_gastrointestinal->setPlainText(anamnesis->getROSgastro());
        ui->plainTextEdit_genitourinary->setPlainText(anamnesis->getROSgenit());
        ui->plainTextEdit_historyPresentIllness->setPlainText(anamnesis->getHPI());
        ui->plainTextEdit_medications->setPlainText(anamnesis->getMedications());
        ui->plainTextEdit_musculoskeletal->setPlainText(anamnesis->getROSmusco());
        ui->plainTextEdit_nervous->setPlainText(anamnesis->getROSnerv());
        ui->plainTextEdit_pastMedicalHistory->setPlainText(anamnesis->getPMH());
        ui->plainTextEdit_respiratory->setPlainText(anamnesis->getROSresp());
        ui->plainTextEdit_sexual->setPlainText(anamnesis->getSexual());
        ui->plainTextEdit_skin->setPlainText(anamnesis->getROSskin());
        ui->plainTextEdit_social->setPlainText(anamnesis->getSocial());
    }
}
