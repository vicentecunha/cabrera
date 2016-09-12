/*
 * Cabrera: mainwindow.cpp
 * Author: Vicente Cunha
 * Date: July 2016
 */

// ==================================================
// INCLUDES
// ==================================================

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "vo2000interface.h"
#include "newpatient.h"
#include "openpatient.h"
#include "editpatient.h"
#include "newanamnesis.h"
#include "constants.h"
#include "editanamnesis.h"
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>

// ==================================================
// CONSTRUCTORS AND DESTRUCTOR
// ==================================================

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setFixedSize(this->size());

    updatePatient(false);
    updateRecentPatientsActions();
    updateAnamnesis(false);
    updateRecentAnamnesisActions();

    ui->statusBar->showMessage("Busy...");
    connect(ui->action_About,             SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->action_vo2000Interface,   SIGNAL(triggered()), this, SLOT(vo2000display()));
    connect(ui->action_vo2000Interface_2, SIGNAL(triggered()), this, SLOT(vo2000display()));
    connect(ui->action_newPatient,        SIGNAL(triggered()), this, SLOT(newPatient()));
    connect(ui->action_newPatient_2,      SIGNAL(triggered()), this, SLOT(newPatient()));
    connect(ui->action_newAnamnesis,      SIGNAL(triggered()), this, SLOT(newAnamnesis()));
    connect(ui->action_newAnamnesis_2,    SIGNAL(triggered()), this, SLOT(newAnamnesis()));
    connect(ui->action_openPatient,       SIGNAL(triggered()), this, SLOT(openPatient()));
    connect(ui->action_openPatient_2,     SIGNAL(triggered()), this, SLOT(openPatient()));
    connect(ui->action_openAnamnesis,     SIGNAL(triggered()), this, SLOT(openAnamnesis()));
    connect(ui->action_openAnamnesis_2,   SIGNAL(triggered()), this, SLOT(openAnamnesis()));
    connect(ui->action_editPatient,       SIGNAL(triggered()), this, SLOT(editPatient()));
    connect(ui->action_edtAnamnesis,      SIGNAL(triggered()), this, SLOT(editAnamnesis()));
    connect(ui->action_closePatient,      SIGNAL(triggered()), this, SLOT(closePatient()));
    connect(ui->action_closeAnamnesis,    SIGNAL(triggered()), this, SLOT(closeAnamnesis()));
    ui->statusBar->showMessage("Ready.");
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < recentPatientActionList.length();   i++) delete recentPatientActionList[i];
    for (int i = 0; i < recentAnamnesisActionList.length(); i++) delete recentAnamnesisActionList[i];
    delete ui;
}

// ==================================================
// PUBLIC FUNCTIONS - FILE UTILITIES
// ==================================================

/*
 * Return true if a file exists, false otherwise
 */

bool MainWindow::fileExists(const QString& path)
{
    QFileInfo check_file(path);
    return check_file.exists() && check_file.isFile();
}

/*
 * Return true if user has permission to write to file, false otherwise
 */

bool MainWindow::filePermissionOk(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        return false;
    }
    else
    {
        file.close();
        return true;
    }
}

/*
 * Popup a warning: failed to parse file
 */

void MainWindow::fileCorrupt(const QString &filename)
{
    WarningDialog* warningDialog = new WarningDialog();
    warningDialog->setHeadline("ERROR: could not parse file.");
    warningDialog->setDescription("Cabrera was not able to parse " + filename +"\nFile may be corrupt or is not a Cabrera file.");
    warningDialog->exec();
    delete warningDialog;
}

/*
 * Popup a warning: failed to open file, probably because of wrong permissions
 */

void MainWindow::fileError(const QString &filename)
{
    WarningDialog* warningDialog = new WarningDialog();
    warningDialog->setHeadline("ERROR: could not open file.");
    warningDialog->setDescription("Cabrera was not able to open " + filename);
    warningDialog->exec();
    delete warningDialog;
}

/*
 * Parse a patient file. Return an invalid patient if an error occurs.
 */

Patient MainWindow::parsePatient(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        fileError(filename);
        Patient invalidPatient;
        return invalidPatient;
    }
    Patient patient;
    patient.isInvalid = false;
    int numberOfParameters = 0;
    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull())
    {
        if (line.startsWith(NAME_STRING))
        {
            patient.setName(line.remove(0, NAME_STRING.length()));
            numberOfParameters++;
        }
        else if (line.startsWith(ID_STRING))
        {
            patient.setIdFromString(line.remove(0, ID_STRING.length()));
            numberOfParameters++;
        }
        else if (line.startsWith(SEX_STRING))
        {
            patient.setSexFromString(line.remove(0, SEX_STRING.length()));
            numberOfParameters++;
        }
        else if (line.startsWith(DOB_STRING))
        {
            patient.setBirthdayFromString(line.remove(0, DOB_STRING.length()));
            numberOfParameters++;
        }
        else if (line.startsWith(NOTES_STRING))
        {
            patient.setNotes(line.remove(0, NOTES_STRING.length()));
            numberOfParameters++;
        }
        line = in.readLine();
    }
    file.close();
    if (numberOfParameters != NUMBER_OF_PATIENT_PARAMETERS)
    {
        fileCorrupt(filename);
        Patient invalidPatient;
        return invalidPatient;
    }
    return patient;
}

/*
 * Parse anamnesis file. Return an invalid anamnesis if an error occurs.
 */

Anamnesis MainWindow::parseAnamnesis(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        fileError(filename);
        Anamnesis invalidAnamnesis;
        return invalidAnamnesis;
    }
    Anamnesis anamnesis;
    anamnesis.isInvalid = false;
    int numberOfParameters = 0;
    bool continuousParse = false;
    QString string = "";
    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull())
    {
        if (continuousParse && !line.startsWith('!'))
        {
            string += line;
        }
        else if (line.startsWith(NAME_STRING))
        {
            anamnesis.setName(line.remove(0, NAME_STRING.length()));
            numberOfParameters++;
        }
        else if (line.startsWith(ID_STRING))
        {
            anamnesis.setIdFromString(line.remove(0, ID_STRING.length()));
            numberOfParameters++;
        }
        else if (line.startsWith(SEX_STRING))
        {
            anamnesis.setSexFromString(line.remove(0, SEX_STRING.length()));
            numberOfParameters++;
        }
        else if (line.startsWith(DOB_STRING))
        {
            anamnesis.setBirthdayFromString(line.remove(0, DOB_STRING.length()));
            numberOfParameters++;
        }
        else if (line.startsWith(NOTES_STRING))
        {
            anamnesis.setNotes(line.remove(0,NOTES_STRING.length()));
            numberOfParameters++;
        }
        else if (line.startsWith(HEIGHT_STRING))
        {
            anamnesis.setHeightFromString(line.remove(0, HEIGHT_STRING.length()));
            numberOfParameters++;
        }
        else if (line.startsWith(WEIGHT_STRING))
        {
            anamnesis.setWeightFromString(line.remove(0, WEIGHT_STRING.length()));
            numberOfParameters++;
        }
        else if (line.startsWith(CHIEF_COMPLAINT_STRING)) continuousParse = true;
        else if (line.startsWith('!' + CHIEF_COMPLAINT_STRING)) anamnesis.setCC(string);
        else if (line.startsWith(HISTORY_PRESENT_ILLNESS_STRING)) continuousParse = true;
        else if (line.startsWith('!' + HISTORY_PRESENT_ILLNESS_STRING)) anamnesis.setHPI(string);
        else if (line.startsWith(PAST_MEDICAL_HISTORY_STRING)) continuousParse = true;
        else if (line.startsWith('!' + PAST_MEDICAL_HISTORY_STRING)) anamnesis.setPMH(string);
        else if (line.startsWith(ROS_CARDIOVASCULAR_STRING)) continuousParse = true;
        else if (line.startsWith('!' + ROS_CARDIOVASCULAR_STRING)) anamnesis.setROScardio(string);
        else if (line.startsWith(ROS_RESPIRATORY_STRING)) continuousParse = true;
        else if (line.startsWith('!' + ROS_RESPIRATORY_STRING)) anamnesis.setROSresp(string);
        else if (line.startsWith(ROS_GASTROINTESTINAL_STRING)) continuousParse = true;
        else if (line.startsWith('!' + ROS_GASTROINTESTINAL_STRING)) anamnesis.setROSgastro(string);
        else if (line.startsWith(ROS_GENITOURINARY_STRING)) continuousParse = true;
        else if (line.startsWith('!' + ROS_GENITOURINARY_STRING)) anamnesis.setROSgenit(string);
        else if (line.startsWith(ROS_NERVOUS_STRING)) continuousParse = true;
        else if (line.startsWith('!' + ROS_NERVOUS_STRING)) anamnesis.setROSnerv(string);
        else if (line.startsWith(ROS_CRANIAL_STRING)) continuousParse = true;
        else if (line.startsWith('!' + ROS_CRANIAL_STRING)) anamnesis.setROScran(string);
        else if (line.startsWith(ROS_ENDOCRINE_STRING)) continuousParse = true;
        else if (line.startsWith('!' + ROS_ENDOCRINE_STRING)) anamnesis.setROSendo(string);
        else if (line.startsWith(ROS_MUSCOSKELETAL_STRING)) continuousParse = true;
        else if (line.startsWith('!' + ROS_MUSCOSKELETAL_STRING)) anamnesis.setROSmusco(string);
        else if (line.startsWith(ROS_SKIN_STRING)) continuousParse = true;
        else if (line.startsWith('!' + ROS_SKIN_STRING)) anamnesis.setROSskin(string);
        else if (line.startsWith(FAMILY_STRING)) continuousParse = true;
        else if (line.startsWith('!' + FAMILY_STRING)) anamnesis.setFamily(string);
        else if (line.startsWith(CHILDHOOD_STRING)) continuousParse = true;
        else if (line.startsWith('!' + CHILDHOOD_STRING)) anamnesis.setChildhood(string);
        else if (line.startsWith(SOCIAL_STRING)) continuousParse = true;
        else if (line.startsWith('!' + SOCIAL_STRING)) anamnesis.setSocial(string);
        else if (line.startsWith(MEDICATIONS_STRING)) continuousParse = true;
        else if (line.startsWith('!' + MEDICATIONS_STRING)) anamnesis.setMedications(string);
        else if (line.startsWith(ALLERGIES_STRING)) continuousParse = true;
        else if (line.startsWith('!' + ALLERGIES_STRING)) anamnesis.setAllergies(string);
        else if (line.startsWith(SEXUAL_STRING)) continuousParse = true;
        else if (line.startsWith('!' + SEXUAL_STRING)) anamnesis.setSexual(string);
        else if (line.startsWith(CONCLUSION_STRING)) continuousParse = true;
        else if (line.startsWith('!' + CONCLUSION_STRING)) anamnesis.setConclusion(string);
        if (line.startsWith('!'))
        {
            continuousParse = false;
            string = "";
            numberOfParameters++;
        }
        line = in.readLine();
    }
    file.close();
    if (numberOfParameters != NUMBER_OF_ANAMNESIS_PARAMETERS)
    {
        fileCorrupt(filename);
        Anamnesis invalidAnamnesis;
        return invalidAnamnesis;
    }
    return anamnesis;
}

// ==================================================
// PRIVATE FUNCTIONS - DESCRIPTION UPDATERS
// ==================================================

/*
 * Update open patient description and enable related menus.
 */

void MainWindow::updatePatient(bool isOpen)
{
    if (isOpen)
    {
        ui->patientLabel->setText("Name: "          + patient.getName()                           + "\r\n" +
                                  "ID: "            + patient.getIdStr()                          + "\r\n" +
                                  "Sex: "           + patient.getSexStr()                         + "\r\n" +
                                  "Date of Birth: " + patient.getBirthday().toString(DATE_FORMAT) + "\r\n" +
                                  "Notes: "         + patient.getNotes());
    }
    else ui->patientLabel->setText("No patient open.");
    ui->action_editPatient->setEnabled(isOpen);
    ui->action_closePatient->setEnabled(isOpen);
    this->patientIsOpen = isOpen;
}

/*
 * Update the recent patients action list.
 */

void MainWindow::updateRecentPatientsActions()
{
    if (recentPatientActionList.length() > 0)
    {
        ui->menu_recentPatients->clear();
        for (int i = 0; i < recentPatientActionList.length(); i++) delete recentPatientActionList[i];
        recentPatientActionList.clear();
    }
    QFile file(RECENT_PATIENTS_FILENAME);
    if (!file.open(QIODevice::ReadWrite))
    {
        fileError(RECENT_PATIENTS_FILENAME);
        return;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull())
    {
        if (fileExists(line))
        {
            QAction* action = new QAction(line, this);
            connect(action, SIGNAL(triggered()), &patientsSignalMapper, SLOT(map()));
            patientsSignalMapper.setMapping(action, line);
            recentPatientActionList.append(action);
        }
        line = in.readLine();
    }
    connect(&patientsSignalMapper, SIGNAL(mapped(QString)), this, SLOT(openPatientFromFile(QString)));
    if (recentPatientActionList.length() > 0)
    {
        ui->menu_recentPatients->clear();
        ui->menu_recentPatients->addActions(recentPatientActionList);
    }
    file.close();
}

/*
 * Update open anamnesis description and enable related menus.
 */

void MainWindow::updateAnamnesis(bool isOpen)
{
    if (isOpen)
    {
        QString string = "Name: "          + anamnesis.getName()                           + "\r\n" +
                "ID: "            + anamnesis.getIdStr()                          + "\r\n" +
                "Sex: "           + anamnesis.getSexStr()                         + "\r\n" +
                "Date of Birth: " + anamnesis.getBirthday().toString(DATE_FORMAT) + "\r\n" +
                "Notes: "         + anamnesis.getNotes()                          + "\r\n" +
                "Height: " + anamnesis.getHeightStr() + " m" + "\r\n" +
                "Weight: " + anamnesis.getWeightStr() + " kg" + "\r\n\r\n";

        if (anamnesis.getCC().trimmed().length() > 0)          string += "Chief Complaint:\r\n" + anamnesis.getCC() + "\r\n";
        if (anamnesis.getHPI().trimmed().length() > 0)         string += "History of the Present Illness:\r\n" + anamnesis.getHPI() + "\r\n";
        if (anamnesis.getPMH().trimmed().length() > 0)         string += "Past Medical History:\r\n" + anamnesis.getPMH() + "\r\n";
        if (anamnesis.getROScardio().trimmed().length() > 0)   string += "Cardiovascular System: " + anamnesis.getROScardio() + "\r\n";
        if (anamnesis.getROSresp().trimmed().length() > 0)     string += "Respiratory System: " + anamnesis.getROSresp() + "\r\n";
        if (anamnesis.getROSgastro().trimmed().length() > 0)   string += "Gastrointestinal System: " + anamnesis.getROSgastro() + "\r\n";
        if (anamnesis.getROSgenit().trimmed().length() > 0)    string += "Genitourinary System: " + anamnesis.getROSgenit() + "\r\n";
        if (anamnesis.getROSnerv().trimmed().length() > 0)     string += "Nervous System: " + anamnesis.getROSnerv() + "\r\n";
        if (anamnesis.getROScran().trimmed().length() > 0)     string += "Cranial Nerves System: " + anamnesis.getROScran() + "\r\n";
        if (anamnesis.getROSendo().trimmed().length() > 0)     string += "Endocrine System: " + anamnesis.getROSendo() + "\r\n";
        if (anamnesis.getROSmusco().trimmed().length() > 0)    string += "Muscoskeletal System: " + anamnesis.getROSmusco() + "\r\n";
        if (anamnesis.getROSskin().trimmed().length() > 0)     string += "Skin: " + anamnesis.getROSskin() + "\r\n";
        if (anamnesis.getFamily().trimmed().length() > 0)      string += "Family Diseases:\r\n" + anamnesis.getFamily() + "\r\n";
        if (anamnesis.getChildhood().trimmed().length() > 0)   string += "Childhood Diseases:\r\n" + anamnesis.getChildhood() + "\r\n";
        if (anamnesis.getFamily().trimmed().length() > 0)      string += "Family Diseases:\r\n" + anamnesis.getFamily() + "\r\n";
        if (anamnesis.getSocial().trimmed().length() > 0)      string += "Social History:\r\n" + anamnesis.getSocial() + "\r\n";
        if (anamnesis.getMedications().trimmed().length() > 0) string += "Medications:\r\n" + anamnesis.getMedications() + "\r\n";
        if (anamnesis.getAllergies().trimmed().length() > 0)   string += "Allergies:\r\n" + anamnesis.getAllergies() + "\r\n";
        if (anamnesis.getSexual().trimmed().length() > 0)      string += "Sexual History:\r\n" + anamnesis.getSexual() + "\r\n";
        if (anamnesis.getConclusion().trimmed().length() > 0)  string += "Conclusion:\r\n" + anamnesis.getConclusion();
        ui->textBrowser_anamnesis->setText(string);
    }
    else ui->textBrowser_anamnesis->setText("No open anamnesis.");
    ui->action_edtAnamnesis->setEnabled(isOpen);
    ui->action_closeAnamnesis->setEnabled(isOpen);
    this->anamnesisIsOpen = isOpen;
}

/*
 * Update the recent anamnesis action list.
 */

void MainWindow::updateRecentAnamnesisActions()
{
    if (recentAnamnesisActionList.length() > 0)
    {
        ui->menu_recentAnamnesis->clear();
        for (int i = 0; i < recentAnamnesisActionList.length(); i++) delete recentAnamnesisActionList[i];
        recentAnamnesisActionList.clear();
    }
    QFile file(RECENT_ANAMNESIS_FILENAME);
    if (!file.open(QIODevice::ReadWrite))
    {
        fileError(RECENT_ANAMNESIS_FILENAME);
        return;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull())
    {
        if (fileExists(line))
        {
            QAction* action = new QAction(line, this);
            connect(action, SIGNAL(triggered()), &anamnesisSignalMapper, SLOT(map()));
            anamnesisSignalMapper.setMapping(action, line);
            recentAnamnesisActionList.append(action);
        }
        line = in.readLine();
    }
    connect(&anamnesisSignalMapper, SIGNAL(mapped(QString)), this, SLOT(openAnamnesisFromFile(QString)));
    if (recentPatientActionList.length() > 0)
    {
        ui->menu_recentAnamnesis->clear();
        ui->menu_recentAnamnesis->addActions(recentAnamnesisActionList);
    }
    file.close();
}

// ==================================================
// PRIVATE FUNCTIONS - FILE SAVERS
// ==================================================

/*
 * Save patient to file;
 */

void MainWindow::savePatient(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        fileError(filename);
        return;
    }
    QTextStream out(&file);
    out << NAME_STRING  + this->patient.getName()                           << endl;
    out << ID_STRING    + this->patient.getIdStr()                          << endl;
    out << SEX_STRING   + this->patient.getSexStr()                         << endl;
    out << DOB_STRING   + this->patient.getBirthday().toString(DATE_FORMAT) << endl;
    out << NOTES_STRING + this->patient.getNotes()                          << endl;
    file.close();
}

/*
 * Save the recent patients list.
 */

void MainWindow::saveRecentPatients(const QString& filename)
{
    QFile file(RECENT_PATIENTS_FILENAME);
    if (!file.open(QIODevice::ReadWrite))
    {
        fileError(RECENT_PATIENTS_FILENAME);
        return;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    QStringList list;
    while (!line.isNull())
    {
        list.append(line);
        line = in.readLine();
    }
    file.close();
    list.removeAll(filename);
    list.prepend(filename);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        fileError(RECENT_PATIENTS_FILENAME);
        return;
    }
    QTextStream out(&file);
    for (int i = 0; i < list.length() && i < MAX_RECENT_PATIENTS; i++) out << list[i] << endl;
    file.close();
}

/*
 * Save anamnesis to file.
 */

void MainWindow::saveAnamnesis(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        MainWindow::fileError(filename);
        return;
    }

    QTextStream out(&file);

    out << NAME_STRING  << anamnesis.getName()                           << endl;
    out << ID_STRING    << anamnesis.getIdStr()                          << endl;
    out << SEX_STRING   << anamnesis.getSexStr()                         << endl;
    out << DOB_STRING   << anamnesis.getBirthday().toString(DATE_FORMAT) << endl;
    out << NOTES_STRING << anamnesis.getNotes()                          << endl;

    out << HEIGHT_STRING << anamnesis.getHeight() << endl;
    out << WEIGHT_STRING << anamnesis.getWeight() << endl;

    out << CHIEF_COMPLAINT_STRING << endl;
    out << anamnesis.getCC() << endl;
    out << '!' << CHIEF_COMPLAINT_STRING << endl;

    out << HISTORY_PRESENT_ILLNESS_STRING << endl;
    out << anamnesis.getHPI() << endl;
    out << '!' << HISTORY_PRESENT_ILLNESS_STRING << endl;

    out << PAST_MEDICAL_HISTORY_STRING << endl;
    out << anamnesis.getPMH() << endl;
    out << '!' << PAST_MEDICAL_HISTORY_STRING << endl;

    out << ROS_CARDIOVASCULAR_STRING  << endl;
    out << anamnesis.getROScardio() << endl;
    out << '!' << ROS_CARDIOVASCULAR_STRING << endl;

    out << ROS_RESPIRATORY_STRING << endl;
    out << anamnesis.getROSresp() << endl;
    out << '!' << ROS_RESPIRATORY_STRING << endl;

    out << ROS_GASTROINTESTINAL_STRING << endl;
    out << anamnesis.getROSgastro() << endl;
    out << '!' << ROS_GASTROINTESTINAL_STRING << endl;

    out << ROS_GENITOURINARY_STRING << endl;
    out << anamnesis.getROSgenit() << endl;
    out << '!' << ROS_GENITOURINARY_STRING << endl;

    out << ROS_NERVOUS_STRING << endl;
    out << anamnesis.getROSnerv() << endl;
    out << '!' << ROS_NERVOUS_STRING << endl;

    out << ROS_CRANIAL_STRING << endl;
    out << anamnesis.getROScran() << endl;
    out << '!' << ROS_CRANIAL_STRING << endl;

    out << ROS_ENDOCRINE_STRING << endl;
    out << anamnesis.getROSendo() << endl;
    out << '!' << ROS_ENDOCRINE_STRING << endl;

    out << ROS_MUSCOSKELETAL_STRING << endl;
    out << anamnesis.getROSmusco() << endl;
    out << '!' << ROS_MUSCOSKELETAL_STRING << endl;

    out << ROS_SKIN_STRING << endl;
    out << anamnesis.getROSskin() << endl;
    out << '!' << ROS_SKIN_STRING << endl;

    out << FAMILY_STRING << endl;
    out << anamnesis.getFamily() << endl;
    out << '!' << FAMILY_STRING << endl;

    out << CHILDHOOD_STRING << endl;
    out << anamnesis.getChildhood() << endl;
    out << '!' << CHILDHOOD_STRING << endl;

    out << SOCIAL_STRING << endl;
    out << anamnesis.getSocial() << endl;
    out << '!' << SOCIAL_STRING << endl;

    out << MEDICATIONS_STRING << endl;
    out << anamnesis.getMedications() << endl;
    out << '!' << MEDICATIONS_STRING << endl;

    out << ALLERGIES_STRING << endl;
    out << anamnesis.getAllergies() << endl;
    out << '!' << ALLERGIES_STRING << endl;

    out << SEXUAL_STRING << endl;
    out << anamnesis.getSexual() << endl;
    out << '!' << SEXUAL_STRING << endl;

    out << CONCLUSION_STRING << endl;
    out << anamnesis.getConclusion() << endl;
    out << '!' << CONCLUSION_STRING << endl;

    file.close();
}

/*
 * Save the recent anamnesis list.
 */

void MainWindow::saveRecentAnamnesis(const QString& filename)
{
    QFile file(RECENT_ANAMNESIS_FILENAME);
    if (!file.open(QIODevice::ReadWrite))
    {
        fileError(RECENT_ANAMNESIS_FILENAME);
        return;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    QStringList list;
    while (!line.isNull())
    {
        list.append(line);
        line = in.readLine();
    }
    file.close();
    list.removeAll(filename);
    list.prepend(filename);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        fileError(RECENT_ANAMNESIS_FILENAME);
        return;
    }
    QTextStream out(&file);
    for (int i = 0; i < list.length() && i < MAX_RECENT_PATIENTS; i++) out << list[i] << endl;
    file.close();
}


// ==================================================
// PRIVATE FUNCTIONS - NEW MENU
// ==================================================

/*
 * Create a new patient.
 */

void MainWindow::newPatient()
{
    ui->statusBar->showMessage("Busy...");
    QFileDialog* fileDialog = new QFileDialog(this, "Save As", "Nome do Paciente", "Patient file (*"+PATIENT_EXT+")");
    fileDialog->setAcceptMode(QFileDialog::AcceptSave);
    if (fileDialog->exec())
    {
        QString filename = (fileDialog->selectedFiles())[0];
        if (!filename.endsWith(PATIENT_EXT)) filename += PATIENT_EXT;
        if (!filePermissionOk(filename)) fileError(filename);
        else
        {
            NewPatient* newPatient = new NewPatient(this);
            if (newPatient->exec() == QDialog::Accepted)
            {
                this->patient = newPatient->getPatient();
                this->patientFile = filename;
                savePatient(filename);
                saveRecentPatients(filename);
                updatePatient(true);
                updateRecentPatientsActions();
            }
            delete newPatient;
        }
    }
    delete fileDialog;
    ui->statusBar->showMessage("Ready.");
}

/*
 * Create a new anamnesis.
 */

void MainWindow::newAnamnesis()
{
    ui->statusBar->showMessage("Busy...");
    QFileDialog* fileDialog = new QFileDialog(this, "Save As", "", "Anamnesis file (*"+ANAMNESIS_EXT+")");
    fileDialog->setAcceptMode(QFileDialog::AcceptSave);
    if (patientIsOpen) fileDialog->selectFile(patient.getName() + ' ' + QDate::currentDate().toString(SAVEFILE_DATE_FORMAT) + ANAMNESIS_EXT);
    else               fileDialog->selectFile(QDate::currentDate().toString(SAVEFILE_DATE_FORMAT) + ANAMNESIS_EXT);
    if (fileDialog->exec())
    {
        QString filename = (fileDialog->selectedFiles())[0];
        if (!filename.endsWith(ANAMNESIS_EXT)) filename += ANAMNESIS_EXT;
        if (!filePermissionOk(filename)) fileError(filename);
        else
        {
            NewAnamnesis* newAnamnesis = new NewAnamnesis(this);
            if (patientIsOpen) newAnamnesis->updatePatient(&patient);
            if (newAnamnesis->exec() == QDialog::Accepted)
            {
                this->anamnesis = newAnamnesis->getAnamnesis();
                this->anamnesisFile = filename;
                saveAnamnesis(filename);
                saveRecentAnamnesis(filename);
                updateAnamnesis(true);
                updateRecentAnamnesisActions();
            }
            delete newAnamnesis;
        }
    }
    delete fileDialog;
    ui->statusBar->showMessage("Ready.");
}

// ==================================================
// PRIVATE FUNCTIONS - OPEN MENU
// ==================================================

/*
 * Open patient dialog.
 */

void MainWindow::openPatient()
{
    ui->statusBar->showMessage("Busy...");
    QFileDialog* fileDialog = new QFileDialog(this, "Open Patient", "", "Patient file (*"+PATIENT_EXT+")");
    fileDialog->setFileMode(QFileDialog::ExistingFile);
    if (fileDialog->exec())
    {
        QString filename = (fileDialog->selectedFiles())[0];
        Patient patient = parsePatient(filename);
        if (!patient.isInvalid)
        {
            this->patient = patient;
            this->patientFile = filename;
            saveRecentPatients(filename);
            updatePatient(true);
            updateRecentPatientsActions();
            ui->tabWidget->setCurrentIndex(0);
        }
    }
    delete fileDialog;
    ui->statusBar->showMessage("Ready.");
}

/*
 * Open patient from file.
 */

void MainWindow::openPatientFromFile(const QString &filename)
{
    Patient patient = parsePatient(filename);
    if (!patient.isInvalid)
    {
        this->patient = patient;
        this->patientFile = filename;
        saveRecentPatients(filename);
        updatePatient(true);
        updateRecentPatientsActions();
        ui->tabWidget->setCurrentIndex(0);
    }
}

/*
 * Open anamnesis dialog.
 */

void MainWindow::openAnamnesis()
{
    ui->statusBar->showMessage("Busy...");
    QFileDialog* fileDialog = new QFileDialog(this, "Open Anamnesis", "", "Anamnesis file (*"+ANAMNESIS_EXT+")");
    fileDialog->setFileMode(QFileDialog::ExistingFile);
    if (fileDialog->exec())
    {
        QString filename = (fileDialog->selectedFiles())[0];
        Anamnesis anamnesis = parseAnamnesis(filename);
        if (!anamnesis.isInvalid)
        {
            this->anamnesis = anamnesis;
            this->anamnesisFile = filename;
            saveRecentAnamnesis(filename);
            updateAnamnesis(true);
            updateRecentAnamnesisActions();
            ui->tabWidget->setCurrentIndex(1);
        }
    }
    delete fileDialog;
    ui->statusBar->showMessage("Ready.");
}

/*
 * Open anamnesis from file.
 */

void MainWindow::openAnamnesisFromFile(const QString &filename)
{
    Anamnesis anamnesis = parseAnamnesis(filename);
    if (!anamnesis.isInvalid)
    {
        this->anamnesis = anamnesis;
        this->anamnesisFile = filename;
        saveRecentAnamnesis(filename);
        updateAnamnesis(true);
        updateRecentAnamnesisActions();
        ui->tabWidget->setCurrentIndex(1);
    }
}

// ==================================================
// PRIVATE FUNCTIONS - EDIT MENU
// ==================================================

void MainWindow::editPatient()
{
    ui->statusBar->showMessage("Busy...");
    EditPatient* editPatient = new EditPatient(this);
    editPatient->updatePatient(&patient);
    if (editPatient->exec() == QDialog::Accepted)
    {
        this->patient = editPatient->getPatient();
        savePatient(patientFile);
        updatePatient(true);
    }
    delete editPatient;
    ui->statusBar->showMessage("Ready.");
}

void MainWindow::editAnamnesis()
{
    ui->statusBar->showMessage("Busy...");
    EditAnamnesis* editAnamnesis = new EditAnamnesis(this);
    editAnamnesis->updateAnamnesis(&anamnesis);
    if (editAnamnesis->exec() == QDialog::Accepted)
    {
        this->anamnesis = editAnamnesis->getAnamnesis();
        saveAnamnesis(anamnesisFile);
        updateAnamnesis(true);
    }
    delete editAnamnesis;
    ui->statusBar->showMessage("Ready.");
}

// ==================================================
// PRIVATE FUNCTIONS - CLOSE MENU
// ==================================================

/*
 * Close current patient.
 */

void MainWindow::closePatient()
{
    Patient patient;
    this->patient = patient;
    updatePatient(false);
}

/*
 * Close current anamnesis.
 */

void MainWindow::closeAnamnesis()
{
    Anamnesis anamnesis;
    this->anamnesis = anamnesis;
    updateAnamnesis(false);
}

// ==================================================
// PRIVATE FUNCTIONS - OTHER DIALOGS
// ==================================================

/*
 * VO2000 dialog.
 */

void MainWindow::vo2000display()
{
    ui->statusBar->showMessage("Busy...");
    Vo2000interface* vo2000interface = new Vo2000interface(this);
    vo2000interface->exec();
    delete vo2000interface;
    ui->statusBar->showMessage("Ready.");
}

/*
 * About dialog.
 */

void MainWindow::about()
{
    ui->statusBar->showMessage("Busy...");
    About* about = new About(this);
    about->exec();
    delete about;
    ui->statusBar->showMessage("Ready.");
}
