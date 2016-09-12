/*
 * Cabrera: patientdb.h
 * Author: Vicente Cunha
 * Date: July 2016
 */

#ifndef PATIENTDB_H
#define PATIENTDB_H

/*
 * INCLUDES
 */

#include "patient.h"

/*
 * CLASSES
 */

class PatientDb
{
public:
    PatientDb();

    void append(Patient*);
    void overwrite(QList<Patient>*);
    QList<Patient> read();
    QList<int> readHistory();
    void updateHistory(int);

private:
    const QString DB_FILENAME = "patients.cabrera";
    const QString HIST_FILENAME = "patientsHistory.cabrera";
    const QString DELIMITER ="!@#";

    void fileError(QString filename);
};

#endif // PATIENTDB_H
