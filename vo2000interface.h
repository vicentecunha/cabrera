/*
 * Cabrera: vo2000interface.h
 * Author: Vicente Cunha
 * Date: July 2016
 */

#ifndef VO2000DISPLAY_H
#define VO2000DISPLAY_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QAbstractButton>
#include <QKeyEvent>

namespace Ui {
class vo2000interface;
}

class Vo2000interface : public QDialog
{
    Q_OBJECT

public:
    explicit Vo2000interface(QWidget *parent = 0, Qt::WindowFlags f = Qt::Window);
    ~Vo2000interface();

private:
    Ui::vo2000interface *ui;
    QList<QSerialPortInfo> serialPortList = QSerialPortInfo::availablePorts();
    QSerialPort serialPort;
    QTimer timer;

    const QString DISPLAY_CLOSED_PORT = "Serial port is not open.\nPlease select a serial port\nand press \"Open port\".";
    const QString OPEN_PORT = "Open port";
    const QString CLOSE_PORT = "Close port";
    const QString EXIT = "Exit";
    const int SERIAL_POLL_PERIOD_ms = 100;

    void openSerialPort();
    void closeSerialPort();
    void exit();
    void updateDisplay(const QString &);
    void updateData(const QString &);
    void keyReleaseEvent(QKeyEvent *);
    void sendChar(char c);
    QString errorString(QSerialPort::SerialPortError);

private slots:
    void buttonBoxHandler(QAbstractButton*);
    void updateSerialPort();
    void serialPoll();
    void pb0();
    void pb1();
    void pb2();
    void pb3();
    void pb4();
    void pb5();
    void pb6();
    void pb7();
    void pb8();
    void pb9();
    void pbA();
    void pbB();
    void pbC();
    void pbD();
    void pbE();
    void pbF();
};

#endif // VO2000DISPLAY_H
