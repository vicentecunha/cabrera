/*
 * Cabrera: openpatient.cpp
 * Author: Vicente Cunha
 * Date: July 2016
 */

/*
 * INCLUDES
 */

#include "openpatient.h"
#include "ui_openpatient.h"

#include <QDebug>

/*
 * CONSTRUCTORS AND DESTRUCTOS
 */

OpenPatient::OpenPatient(QList<Patient>* patientList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenPatient)
{
    ui->setupUi(this);
    QWidget::setFixedSize(this->size());

    this->patientList = patientList;

    model= new QStandardItemModel(patientList->length(), 5);
    if (patientList->length() > 0)
    {
        for (int row = 0; row < patientList->length(); row++)
        {
            model->setItem(row, 0, new QStandardItem((*patientList)[row].getName()));
            model->setItem(row, 1, new QStandardItem((*patientList)[row].getIdStr()));
            model->setItem(row, 2, new QStandardItem((*patientList)[row].getSexStr()));
            model->setItem(row, 3, new QStandardItem((*patientList)[row].getBirthday().toString(DATE_FORMAT)));
            model->setItem(row, 4, new QStandardItem((*patientList)[row].getNotes()));
        }
    }
    QStringList labels = {"Name", "ID", "Sex", "Date of Birth", "Notes"};
    model->setHorizontalHeaderLabels(labels);
    ui->tableView->setModel(model);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSortingEnabled(false);

    /*
     * Signal-Slot connections.
     */

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(openPatient()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(enableOpen()));
}

OpenPatient::~OpenPatient()
{
    for (int row = 0; row < patientList->length(); row++)
    {
        for (int column = 0; column < 5; column++)
        {
            delete model->item(row, column);
        }
    }
    delete ui;
}

/*
 * PRIVATE FUNCTIONS
 */

/*
 * Open currently selected patient.
 */

void OpenPatient::openPatient()
{
    QItemSelectionModel* select = ui->tableView->selectionModel();
    QModelIndexList list = select->selectedIndexes();
    if (list.isEmpty() || list.length() > 1)
    {
        return;
    }
    patient = (*patientList)[list[0].row()];
    this->accept();
}

/*
 * Enable the "open" button.
 */

void OpenPatient::enableOpen()
{
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Open|QDialogButtonBox::Cancel);
}
