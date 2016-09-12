/*
 * Cabrera: editpatient.h
 * Author: Vicente Cunha
 * Date: July 2016
 */

#ifndef EDITPATIENT_H
#define EDITPATIENT_H

#include "patient.h"
#include "warningdialog.h"
#include <QComboBox>
#include <QDialog>

namespace Ui {
class NewPatient;
}

class EditPatient : public QDialog
{
    Q_OBJECT

public:
    explicit EditPatient(QWidget *parent = 0);
    ~EditPatient();
    void updatePatient(Patient*);
    Patient getPatient() {return patient;}

private:
    Ui::NewPatient *ui;
    Patient patient;
    Patient::sex_t getSex(QComboBox*);

private slots:
    void editPatient();
};

#endif // EDITPATIENT_H
