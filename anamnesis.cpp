/*
 * Cabrera: anamnesis.cpp
 * Author: Vicente Cunha
 * Date: July 2016
 */

#include "anamnesis.h"
#include "constants.h"

// ==================================================
// CONSTRUCTORS AND DESTRUCTOR
// ==================================================

Anamnesis::Anamnesis()
{
    this->isInvalid = true;
}

Anamnesis::Anamnesis(const QString &name,
                     const QString &idString,
                     Patient::sex_t sex,
                     QDate birthday,
                     const QString &notes,
                     double height,
                     double weight,
                     const QStringList &stringList)
{
    this->isInvalid = false;

    this->name = name;

    bool ok = false;
    this->id = idString.toLong(&ok);
    if (!ok || id < 0) this->isInvalid = true;

    this->sex = sex;
    this->birthday = birthday;
    this->notes = notes;
    this->weight = weight;
    this->height = height;
    this->cc = stringList[0];
    this->hpi = stringList[1];
    this->pmh = stringList[2];
    this->ROScardio = stringList[3];
    this->ROSresp = stringList[4];
    this->ROSgastro = stringList[5];
    this->ROSgenit = stringList[6];
    this->ROSnerv = stringList[7];
    this->ROScran = stringList[8];
    this->ROSendo = stringList[9];
    this->ROSmusco = stringList[10];
    this->ROSskin = stringList[11];
    this->family = stringList[12];
    this->childhood = stringList[13];
    this->social = stringList[14];
    this->medications = stringList[15];
    this->allergies = stringList[16];
    this->sexual = stringList[17];
    this->conclusion = stringList[18];
}

// ==================================================
// CUSTOM GETTERS
// ==================================================

QString Anamnesis::getSexStr()
{
    switch (sex)
    {
    case Patient::FEMALE: return FEMALE_STRING;
    case Patient::MALE:   return MALE_STRING;
    default:              return FEMALE_STRING;
    }
}

QString Anamnesis::getIdStr()
{
    QString string = QString::number(id);
    while (string.length() < ID_LENGTH) string = "0" + string;
    return string;
}

QString Anamnesis::getHeightStr()
{
    return QString::number(height, 'f', 2);
}


QString Anamnesis::getWeightStr()
{
    return QString::number(weight, 'f', 2);
}

// ==================================================
// CUSTOM SETTERS
// ==================================================

void Anamnesis::setIdFromString(const QString &string)
{
    bool ok = false;
    this->id = string.toLong(&ok);
    if (!ok || id < 0) this->isInvalid = true;
}

void Anamnesis::setSexFromString(const QString &string)
{
    if      (string == FEMALE_STRING) this->sex = Patient::FEMALE;
    else if (string == MALE_STRING)   this->sex = Patient::MALE;
    else this->isInvalid = true;
}

void Anamnesis::setBirthdayFromString(const QString &string)
{
    this->birthday = QDate::fromString(string, DATE_FORMAT);
    this->isInvalid = !birthday.isValid();
}

void Anamnesis::setHeightFromString(const QString &string)
{
    bool ok = false;
    this->height = string.toDouble(&ok);
    if (!ok || height < 0) this->isInvalid = true;
}

void Anamnesis::setWeightFromString(const QString &string)
{
    bool ok = false;
    this->weight = string.toDouble(&ok);
    if (!ok || weight < 0) this->isInvalid = true;
}
