/*
 * Cabrera: mainwindow.h
 * Author: Vicente Cunha
 * Date: July 2016
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "patient.h"
#include "anamnesis.h"
#include <QMainWindow>
#include <QSignalMapper>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static bool fileExists      (const QString&);
    static bool filePermissionOk(const QString&);
    static void fileCorrupt     (const QString&);
    static void fileError       (const QString&);

    bool patientIsOpen = false;
    bool anamnesisIsOpen = false;

    static Patient parsePatient    (const QString&);
    static Anamnesis parseAnamnesis(const QString&);

private:
    Ui::MainWindow *ui;
    Patient patient;
    Anamnesis anamnesis;
    QString patientFile;
    QString anamnesisFile;
    QSignalMapper patientsSignalMapper;
    QSignalMapper anamnesisSignalMapper;
    QList<QAction*> recentPatientActionList;
    QList<QAction*> recentAnamnesisActionList;

    void savePatient  (const QString&);
    void saveAnamnesis(const QString&);
    void updatePatient  (bool isOpen);
    void updateAnamnesis(bool isOpen);
    void updateRecentPatientsActions();
    void updateRecentAnamnesisActions();
    void saveRecentPatients (const QString&);
    void saveRecentAnamnesis(const QString&);

private slots:
    void newPatient();
    void newAnamnesis();
    void openPatient();
    void openAnamnesis();
    void openPatientFromFile  (const QString&);
    void openAnamnesisFromFile(const QString&);
    void closePatient();
    void closeAnamnesis();
    void editPatient();
    void editAnamnesis();
    void vo2000display();
    void about();
};

#endif // MAINWINDOW_H
