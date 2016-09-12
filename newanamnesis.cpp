/*
 * Cabrera: newanamnesis.cpp
 * Author: Vicente Cunha
 * Date: July 2016
 */

// ==================================================
// INCLUDES
// ==================================================

#include "newanamnesis.h"
#include "ui_newanamnesis.h"
#include "warningdialog.h"
#include "mainwindow.h"
#include "constants.h"
#include "newpatient.h"
#include <QTextStream>
#include <QFileDialog>

// ==================================================
// CONSTRUCTORS AND DESTRUCTOR
// ==================================================

NewAnamnesis::NewAnamnesis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewAnamnesis)
{
    ui->setupUi(this);
    QWidget::setFixedSize(this->size());

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(loadPatient()));
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(newAnamnesis()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

NewAnamnesis::~NewAnamnesis()
{
    delete ui;
}

// ==================================================
// PUBLIC FUNCTIONS
// ==================================================

/*
 * Update patient info.
 */

void NewAnamnesis::updatePatient(Patient* patient)
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

// ==================================================
// PRIVATE FUNCTIONS
// ==================================================

/*
 * Load patient info from file.
 */

void NewAnamnesis::loadPatient()
{
    QFileDialog* fileDialog = new QFileDialog(this, "Open Patient", "patients", "Patient file (*"+PATIENT_EXT+")");
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
 * Create new anamnesis and send an accept signal.
 */

void NewAnamnesis::newAnamnesis()
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
