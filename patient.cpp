/*
 * Cabrera: patient.cpp
 * Author: Vicente Cunha
 * Date: July 2016
 */

// ==================================================
// INCLUDES
// ==================================================

#include "patient.h"
#include "constants.h"
#include "warningdialog.h"

// ==================================================
// CONSTRUCTORS AND DESTRUCTORS
// ==================================================

Patient::Patient()
{
    this->isInvalid = true;
}

Patient::Patient(const QString& name, const QString& idString, sex_t sex, QDate birthday, const QString notes)
{
    this->isInvalid = false;

    if (name.isEmpty())
    {
        WarningDialog* warningDialog = new WarningDialog(0);
        warningDialog->setHeadline("Warning: invalid patient name.");
        warningDialog->setDescription("Patient name cannot be an empty string.");
        warningDialog->exec();
        delete warningDialog;
        this->isInvalid = true;
    }
    else this->name = name;

    bool ok = false;
    long id = idString.toLong(&ok);
    if (!ok || id < 0)
    {
        WarningDialog* warningDialog = new WarningDialog(0);
        warningDialog->setHeadline("Warning: invalid patient id.");
        warningDialog->setDescription("Patient id must be an unsigned integer.");
        warningDialog->exec();
        delete warningDialog;
        this->isInvalid = true;
    }
    else this->id = id;

    this->sex = sex;
    this->birthday = birthday;
    this->notes = notes;
}

// ==================================================
// CUSTOM GETTERS
// ==================================================

QString Patient::getSexStr()
{
    switch (sex)
    {
    case FEMALE: return FEMALE_STRING;
    case MALE:   return MALE_STRING;
    default:     return FEMALE_STRING;
    }
}

QString Patient::getIdStr()
{
    QString string = QString::number(id);
    while (string.length() < ID_LENGTH) string = "0" + string;
    return string;
}

// ==================================================
// CUSTOM SETTERS
// ==================================================

void Patient::setIdFromString(const QString& string)
{
    bool ok = false;
    this->id = string.toLong(&ok);
    if (!ok || id < 0) this->isInvalid = true;
}

void Patient::setSexFromString(const QString& string)
{
    if      (string == FEMALE_STRING) this->sex = FEMALE;
    else if (string == MALE_STRING)   this->sex = MALE;
    else this->isInvalid = true;
}

void Patient::setBirthdayFromString(const QString& string)
{
    this->birthday = QDate::fromString(string, DATE_FORMAT);
    this->isInvalid = !birthday.isValid();
}
