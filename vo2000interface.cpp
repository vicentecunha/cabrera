/*
 * Cabrera: vo2000interface.cpp
 * Author: Vicente Cunha
 * Date: July 2016
 */

// ==================================================
// INCLUDE
// ==================================================

#include "vo2000interface.h"
#include "ui_vo2000interface.h"
#include "warningdialog.h"
#include <QDebug>

// ==================================================
// CONSTRUCTORS AND DESTRUCTOR
// ==================================================

Vo2000interface::Vo2000interface(QWidget *parent, Qt::WindowFlags f) :
    QDialog(parent, f),
    ui(new Ui::vo2000interface)
{
    ui->setupUi(this);
    QWidget::setFixedSize(this->size());

    ui->buttonBox->addButton(OPEN_PORT, QDialogButtonBox::ActionRole);
    ui->buttonBox->addButton(CLOSE_PORT, QDialogButtonBox::ActionRole);
    ui->buttonBox->addButton(EXIT, QDialogButtonBox::DestructiveRole);

    if (!serialPortList.isEmpty())
    {
        serialPort.setPort(serialPortList[0]);
        for (int i = 0; i < serialPortList.length(); i++)
        {
            ui->comboBox->addItem(serialPortList[i].portName());
        }
    }

    connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(buttonBoxHandler(QAbstractButton*)));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSerialPort()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(serialPoll()));
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(pb0()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(pb1()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(pb2()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(pb3()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(pb4()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(pb5()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(pb6()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(pb7()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(pb8()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(pb9()));
    connect(ui->pushButton_A, SIGNAL(clicked()), this, SLOT(pbA()));
    connect(ui->pushButton_B, SIGNAL(clicked()), this, SLOT(pbB()));
    connect(ui->pushButton_C, SIGNAL(clicked()), this, SLOT(pbC()));
    connect(ui->pushButton_D, SIGNAL(clicked()), this, SLOT(pbD()));
    connect(ui->pushButton_E, SIGNAL(clicked()), this, SLOT(pbE()));
    connect(ui->pushButton_F, SIGNAL(clicked()), this, SLOT(pbF()));

    setFocusPolicy(Qt::StrongFocus);
}

Vo2000interface::~Vo2000interface()
{
    delete ui;
}

// ==================================================
// REIMPLEMENTED FUNCTIONS
// ==================================================

void Vo2000interface::keyReleaseEvent(QKeyEvent* event)
{
    if      (event->text() == "0")                           pb0();
    else if (event->text() == "1")                           pb1();
    else if (event->text() == "2")                           pb2();
    else if (event->text() == "3")                           pb3();
    else if (event->text() == "4")                           pb4();
    else if (event->text() == "5")                           pb5();
    else if (event->text() == "6")                           pb6();
    else if (event->text() == "7")                           pb7();
    else if (event->text() == "8")                           pb8();
    else if (event->text() == "9")                           pb9();
    else if (event->text() == "A"  || event->text() == "a" ) pbA();
    else if (event->text() == "B"  || event->text() == "b" ) pbB();
    else if (event->text() == "C"  || event->text() == "c" ) pbC();
    else if (event->text() == "D"  || event->text() == "d" ) pbD();
    else if (event->text() == "E"  || event->text() == "e"
          || event->text() == "\r" || event->text() == "\n") pbE();
    else if (event->text() == "F"  || event->text() == "f" ) pbF();
    else
    {
        QByteArray txt(event->text().toUpper().toUtf8());
        if (txt[0] == (char)0x07)
        {
            const char escape = 0x80;
            serialPort.write(&escape, 1);
        }
        serialPort.write(txt);
    }
}

// ==================================================
// PRIVATE FUNCTIONS
// ==================================================

void Vo2000interface::buttonBoxHandler(QAbstractButton *abstractButton)
{
    if      (abstractButton->text() == OPEN_PORT)  openSerialPort();
    else if (abstractButton->text() == CLOSE_PORT) closeSerialPort();
    else if (abstractButton->text() == EXIT)       exit();
}

QString Vo2000interface::errorString(QSerialPort::SerialPortError error)
{
    switch (error)
    {
    case QSerialPort::NoError:                   return "No error occurred.";
    case QSerialPort::DeviceNotFoundError:       return "An error occurred while attempting to open an non-existing device.";
    case QSerialPort::PermissionError:           return "An error occurred while attempting to open an already opened device by another process or a user not having enough permission and credentials to open.";
    case QSerialPort::OpenError:                 return "An error occurred while attempting to open an already opened device in this object.";
    case QSerialPort::NotOpenError:              return "This error occurs when an operation is executed that can only be successfully performed if the device is open.";
    case QSerialPort::WriteError:                return "An I/O error occurred while writing the data.";
    case QSerialPort::ReadError:                 return "An I/O error occurred while reading the data.";
    case QSerialPort::ResourceError:             return "An I/O error occurred when a resource becomes unavailable, e.g. when the device is unexpectedly removed from the system.";
    case QSerialPort::UnsupportedOperationError: return "The requested device operation is not supported or prohibited by the running operating system.";
    case QSerialPort::TimeoutError:              return "A timeout error occurred.";
    default:
    case QSerialPort::UnknownError:              return "An unidentified error occurred.";
    }
}

void Vo2000interface::openSerialPort()
{
    if (ui->comboBox->currentIndex() == -1) return; // no port selected
    serialPort.setPort(serialPortList[ui->comboBox->currentIndex()]);
    if (!serialPort.open(QIODevice::ReadWrite))
    {
        WarningDialog* warningDialog = new WarningDialog(0);
        warningDialog->setHeadline("Error: could not open serial port.");
        warningDialog->setDescription(errorString(serialPort.error()));
        warningDialog->exec();
        delete warningDialog;
        return;
    }

    ui->pushButton_0->setEnabled(true);
    ui->pushButton_1->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_A->setEnabled(true);
    ui->pushButton_B->setEnabled(true);
    ui->pushButton_C->setEnabled(true);
    ui->pushButton_D->setEnabled(true);
    ui->pushButton_E->setEnabled(true);
    ui->pushButton_F->setEnabled(true);
    ui->display->setText("");

    timer.start(SERIAL_POLL_PERIOD_ms);
}

void Vo2000interface::closeSerialPort()
{
    serialPort.close();

    ui->pushButton_0->setEnabled(false);
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_A->setEnabled(false);
    ui->pushButton_B->setEnabled(false);
    ui->pushButton_C->setEnabled(false);
    ui->pushButton_D->setEnabled(false);
    ui->pushButton_E->setEnabled(false);
    ui->pushButton_F->setEnabled(false);
    ui->display->setText(DISPLAY_CLOSED_PORT);

    timer.stop();
}

void Vo2000interface::exit()
{
    closeSerialPort();
    accept();
}

void Vo2000interface::updateSerialPort()
{
    serialPort.setPort(serialPortList[ui->comboBox->currentIndex()]);
}

void Vo2000interface::updateDisplay(const QString& string)
{
    QString line1 = string.left(20)   + "\r\n";
    QString line2 = string.mid(40,20) + "\r\n";
    QString line3 = string.mid(20,20) + "\r\n";
    QString line4 = string.right(20);
    ui->display->setText(line1+line2+line3+line4);
}

void Vo2000interface::updateData(const QString& string)
{
    QStringList strList = string.split(';');
    QString output = "";
    for (int i = 0; i < strList.length(); i++)
    {
        output += "    " + strList[i];
    }
    ui->textBrowser->append(output);
}

void Vo2000interface::serialPoll()
{
    static QByteArray inputBuffer = "";
    inputBuffer += serialPort.readAll();

    // DISPLAY PARSING:

    int displayStart = inputBuffer.indexOf('{');
    int displayEnd   = inputBuffer.indexOf('}');
    if (displayStart != -1 && displayEnd != -1) // all display is contained
    {
        this->updateDisplay(inputBuffer.mid(displayStart + 1, 80));
        inputBuffer.remove(displayStart, 82);
    }

    // DATA PARSING:

    const char startString[] = {char(0xFF), ';'};
    int dataStart = inputBuffer.indexOf(startString);
    int dataEnd   = inputBuffer.indexOf(";\r");
    if (dataStart != -1 && dataEnd != -1)
    {
        this->updateData(inputBuffer.mid(dataStart + 2, 34));
        inputBuffer.remove(dataStart, 38);
    }
}

void Vo2000interface::pb0()
{
    const char data = '0';
    serialPort.write(&data, 1);
}

void Vo2000interface::pb1()
{
    const char data = '1';
    serialPort.write(&data, 1);
}

void Vo2000interface::pb2()
{
    const char data = '2';
    serialPort.write(&data, 1);
}

void Vo2000interface::pb3()
{
    const char data = '3';
    serialPort.write(&data, 1);
}

void Vo2000interface::pb4()
{
    const char data = '4';
    serialPort.write(&data, 1);
}

void Vo2000interface::pb5()
{
    const char data = '5';
    serialPort.write(&data, 1);
}

void Vo2000interface::pb6()
{
    const char data = '6';
    serialPort.write(&data, 1);
}

void Vo2000interface::pb7()
{
    const char data = '7';
    serialPort.write(&data, 1);
}

void Vo2000interface::pb8()
{
    const char data = '8';
    serialPort.write(&data, 1);
}

void Vo2000interface::pb9()
{
    const char data = '9';
    serialPort.write(&data, 1);
}

void Vo2000interface::pbA()
{
    const char data = 'A';
    serialPort.write(&data, 1);
}

void Vo2000interface::pbB()
{
    const char data = 'B';
    serialPort.write(&data, 1);
}

void Vo2000interface::pbC()
{
    const char data = 'C';
    serialPort.write(&data, 1);
}

void Vo2000interface::pbD()
{
    const char data = 'D';
    serialPort.write(&data, 1);
}

void Vo2000interface::pbE()
{
    const char data = 'E';
    serialPort.write(&data, 1);
}

void Vo2000interface::pbF()
{
    const char data = 'F';
    serialPort.write(&data, 1);
}
