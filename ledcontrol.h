#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
class LEDControl
{
public:
    LEDControl();
    bool OpenPort();
    void ClosePort();
    ~LEDControl();
    bool write(char val);

private:
    QSerialPort serial;
};

#endif // LEDCONTROL_H
