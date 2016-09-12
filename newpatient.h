/*
 * Cabrera: newpatient.h
 * Author: Vicente Cunha
 * Date: July 2016
 */

#ifndef NEWPATIENT_H
#define NEWPATIENT_H

#include "patient.h"
#include <QComboBox>
#include <QDialog>

namespace Ui {
class NewPatient;
}

class NewPatient : public QDialog
{
    Q_OBJECT

public:
    explicit NewPatient(QWidget *parent = 0);
    ~NewPatient();
    Patient getPatient() {return patient;}
    static Patient::sex_t getSex(QComboBox*);

private:
    Ui::NewPatient *ui;
    Patient patient;

private slots:
    void newPatient();
};

#endif // NEWPATIENT_H
