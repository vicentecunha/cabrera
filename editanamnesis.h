/*
 * Cabrera: editanamnesis.h
 * Author: Vicente Cunha
 * Date: July 2016
 */

#ifndef EDITANAMNESIS_H
#define EDITANAMNESIS_H

#include "anamnesis.h"
#include <QDialog>

namespace Ui {
class NewAnamnesis;
}

class EditAnamnesis: public QDialog
{
    Q_OBJECT

public:
    explicit EditAnamnesis(QWidget *parent = 0);
    ~EditAnamnesis();
    Anamnesis getAnamnesis() {return anamnesis;}
    void updateAnamnesis(Anamnesis*);

private:
    Ui::NewAnamnesis *ui;
    Anamnesis anamnesis;

private slots:
    void editAnamnesis();
    void loadPatient();
    void updatePatient(Patient*);
};

#endif // EDITANAMNESIS_H
