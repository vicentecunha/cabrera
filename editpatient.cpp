/*
 * Cabrera: editpatient.cpp
 * Author: Vicente Cunha
 * Date: July 2016
 */

// ==================================================
// INCLUDES
// ==================================================

#include "editpatient.h"
#include "ui_newpatient.h"
#include "newpatient.h"
#include <QDebug>

// ==================================================
// CONSTRUCTORS AND DESTRUCTOR
// ==================================================

EditPatient::EditPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPatient)
{
    ui->setupUi(this);
    QWidget::setFixedSize(this->size());
    QDialog::setWindowTitle("Edit patient");

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(editPatient()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

EditPatient::~EditPatient()
{
    delete ui;
}

void EditPatient::updatePatient(Patient* patient)
{
    if (!patient->isInvalid)
    {
        ui->nameEdit->setText(patient->getName());
        ui->idEdit->setText(patient->getIdStr());
        if (patient->getSex() == Patient::FEMALE)
            ui->comboBox_sex->setCurrentIndex(0);
        else ui->comboBox_sex->setCurrentIndex(1);
        ui->dobEdit->setDate(patient->getBirthday());
        ui->notesEdit->setText(patient->getNotes());
    }
}

// ==================================================
// PRIVATE FUNCTIONS
// ==================================================

void EditPatient::editPatient()
{
    Patient patient(ui->nameEdit->text(), ui->idEdit->text(), NewPatient::getSex(ui->comboBox_sex), ui->dobEdit->date(), ui->notesEdit->text());
    if (!patient.isInvalid)
    {
        this->patient = patient;
        this->accept();
    }
}
