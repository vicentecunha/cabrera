/*
 * Cabrera: openpatient.h
 * Author: Vicente Cunha
 * Date: July 2016
 */

#ifndef OPENPATIENT_H
#define OPENPATIENT_H

/*
 * INCLUDES
 */

#include "patient.h"

#include <QDialog>
#include <QStandardItemModel>

/*
 * CLASSES
 */

namespace Ui {
class OpenPatient;
}

class OpenPatient : public QDialog
{
    Q_OBJECT

public:
    explicit OpenPatient(QList<Patient>* patientList, QWidget *parent = 0);
    ~OpenPatient();
    Patient getPatient() {return patient;}

private:
    Ui::OpenPatient *ui;
    QStandardItemModel* model;
    Patient patient;
    QList<Patient>* patientList;

private slots:
    void openPatient();
    void enableOpen();
};

#endif // OPENPATIENT_H
