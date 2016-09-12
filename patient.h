/*
 * Cabrera: patient.h
 * Author: Vicente Cunha
 * Date: July 2016
 */

#ifndef PATIENT_H
#define PATIENT_H

#include <QDate>
#include <QStringList>

class Patient
{
public:
    typedef enum sex_t
    {
        FEMALE,
        MALE
    } sex_t;

    Patient();
    Patient(const QString& name, const QString& idString, sex_t sex, QDate birthday, const QString notes);

    bool isInvalid = true;

    QString getName()   {return name;}
    long getId()        {return id;}
    sex_t getSex()      {return sex;}
    QDate getBirthday() {return birthday;}
    QString getNotes()  {return notes;}
    QString getSexStr();
    QString getIdStr();

    void setName(QString name)       {this->name = name;}
    void setId(long id)              {this->id = id;}
    void setSex(sex_t sex)           {this->sex = sex;}
    void setBirthday(QDate birthday) {this->birthday = birthday;}
    void setNotes(QString notes)     {this->notes = notes;}
    void setIdFromString      (const QString&);
    void setSexFromString     (const QString&);
    void setBirthdayFromString(const QString&);

private:
    QString name;
    long id;
    sex_t sex;
    QDate birthday;
    QString notes;
};

#endif // PATIENT_H
