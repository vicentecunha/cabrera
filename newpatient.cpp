/*
 * Cabrera: newpatient.cpp
 * Author: Vicente Cunha
 * Date: July 2016
 */

// ==================================================
// INCLUDES
// ==================================================

#include "newpatient.h"
#include "ui_newpatient.h"
#include "warningdialog.h"

// ==================================================
// CONSTRUCTORS AND DESTRUCTOR
// ==================================================

NewPatient::NewPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPatient)
{
    ui->setupUi(this);
    QWidget::setFixedSize(this->size());

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(newPatient()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

NewPatient::~NewPatient()
{
    delete ui;
}

Patient::sex_t NewPatient::getSex(QComboBox* comboBox)
{
    if (comboBox->currentIndex() == 0)
         return Patient::FEMALE;
    else return Patient::MALE;
}

// ==================================================
// PRIVATE FUNCTIONS
// ==================================================

/*
 * Create new patient and send accept() signal.
 */

void NewPatient::newPatient()
{
    Patient patient(ui->nameEdit->text(), ui->idEdit->text(), getSex(ui->comboBox_sex), ui->dobEdit->date(), ui->notesEdit->text());
    if (!patient.isInvalid)
    {
        this->patient = patient;
        this->accept();
    }
}
