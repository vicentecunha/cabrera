/*
 * Cabrera: newanamnesis.h
 * Author: Vicente Cunha
 * Date: July 2016
 */

#ifndef NEWANAMNESIS_H
#define NEWANAMNESIS_H

#include "anamnesis.h"
#include "patient.h"
#include <QDialog>

namespace Ui {
class NewAnamnesis;
}

class NewAnamnesis : public QDialog
{
    Q_OBJECT

public:
    explicit NewAnamnesis(QWidget *parent = 0);
    ~NewAnamnesis();
    void updatePatient(Patient*);
    Anamnesis getAnamnesis() {return anamnesis;}

private:
    Ui::NewAnamnesis *ui;
    Anamnesis anamnesis;

private slots:
    void loadPatient();
    void newAnamnesis();
};

#endif // NEWANAMNESIS_H
