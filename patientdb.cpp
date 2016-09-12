/*
 * Cabrera: patientdb.cpp
 * Author: Vicente Cunha
 * Date: July 2016
 */

/*
 * INCLUDES
 */

#include "patientdb.h"
#include "warningdialog.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

/*
 * CONSTRUCTORS AND DESTRUCTORS
 */

PatientDb::PatientDb()
{
}

/*
 * PRIVATE FUNCTIONS
 */

void PatientDb::fileError(QString filename)
{
    WarningDialog* warningDialog = new WarningDialog();
    warningDialog->setWindowFlags(Qt::WindowStaysOnTopHint);
    warningDialog->setHeadline("Error: could not open file.");
    warningDialog->setDescription("Cabrera was not able to open " + filename +". Try running Cabrera as administrator.");
    warningDialog->exec();
    delete warningDialog;
}

/*
 * PUBLIC FUNCTIONS
 */

void PatientDb::append(Patient* patient)
{
    QFile file(DB_FILENAME);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        fileError(DB_FILENAME);
        return;
    }
    QTextStream out(&file);
    out << patient->getName()                           + DELIMITER;
    out << QString::number(patient->getId())            + DELIMITER;
    out << patient->getSexStr()                         + DELIMITER;
    out << patient->getBirthday().toString(DATE_FORMAT) + DELIMITER;
    out << patient->getNotes()                          + "\r\n";
    file.close();
}

void PatientDb::overwrite(QList<Patient>* patientList)
{
    QFile file(DB_FILENAME);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        fileError(DB_FILENAME);
        return;
    }
    QTextStream out(&file);
    for (int i = 0; i < patientList->length(); i++)
    {
        out << (*patientList)[i].getName()                           + DELIMITER;
        out << QString::number((*patientList)[i].getId())            + DELIMITER;
        out << (*patientList)[i].getSexStr()                         + DELIMITER;
        out << (*patientList)[i].getBirthday().toString(DATE_FORMAT) + DELIMITER;
        out << (*patientList)[i].getNotes()                          + "\r\n";
    }
    file.close();
}

QList<Patient> PatientDb::read()
{
    QList<Patient> patientList;
    QFile file(DB_FILENAME);
    if (!file.open(QIODevice::ReadWrite))
    {
        fileError(DB_FILENAME);
        return patientList;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull())
    {
        QList<QString> list = line.split(DELIMITER);
        qDebug() << list;
        if (list.length() == NUMBER_OF_PATIENT_PARAMETERS)
        {
            Patient patient(line.split(DELIMITER));
            patientList.append(patient);
        }
        line = in.readLine();
    }
    file.close();
    return patientList;
}

QList<int> PatientDb::readHistory()
{
    QList<int> list;
    QFile file(HIST_FILENAME);
    if (!file.open(QIODevice::ReadWrite))
    {
        fileError(HIST_FILENAME);
        return list;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull())
    {
        bool ok = false;
        int lineValue = line.toLong(&ok);
        if (!ok || lineValue < 0)
        {
            WarningDialog* warningDialog = new WarningDialog();
            warningDialog->setHeadline("Warning: invalid recent patient identifier.");
            warningDialog->setDescription("Could not correctly parse recent patients file. \"Recent patients\" menu will be reset.");
            warningDialog->exec();
            delete warningDialog;
            file.close();
            file.open(QIODevice::WriteOnly|QIODevice::Truncate);
            file.close();
            return list;
        }
        if (!list.contains(lineValue))
        {
            list.append(lineValue);
        }
        line = in.readLine();
    }
    return list;
}

void PatientDb::updateHistory(int row)
{
    QList<int> list = readHistory();
    list.removeAll(row);
    list.prepend(row);
    QFile file(HIST_FILENAME);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        fileError(HIST_FILENAME);
        return;
    }
    QTextStream out(&file);
    for (int i = 0; i < list.length(); i++)
    {
        out << list[i];
        out << "\r\n";
    }
    file.close();
}
