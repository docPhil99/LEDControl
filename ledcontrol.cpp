#include "ledcontrol.h"
/*******************
 * Ardunio code to control LED
 * Note, 255 is off!
 *
 *
 *
const int OPpin=3;

void setup() {
  // set the digital pin as output:
  pinMode(OPpin,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
 int pwm=0;

 if(Serial.available()>0)
 {
   pwm=Serial.read();

  analogWrite(OPpin,pwm);
 }


}


***********************/
LEDControl::LEDControl()
{

}

bool LEDControl::OpenPort()
{
    QString portName="none";
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Name        : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();
        if(info.description()=="Arduino Uno")
        {
            portName=info.portName();
            qDebug()<<"Found the Arduino Uno on "<<portName;
            serial.setPort(info);
        }


    }
    if(portName=="none")
    {
        qDebug()<<"No port found";
       return false;
    }
    serial.open(QIODevice::ReadWrite);
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    qDebug() << "Is open : " << serial.isOpen() << endl;
    qDebug() << "Is writable : " << serial.isWritable() << endl;
    if(!serial.isOpen())
        return false;
    if(!serial.isWritable())
        return false;
    return true;
}

void LEDControl::ClosePort()
{
    serial.close();
}

LEDControl::~LEDControl()
{
    this->ClosePort();
}

bool LEDControl::write(char val)
{
    qDebug()<<serial.isDataTerminalReady();
    qint64 res=serial.write(&val,1);
    if(res==1)
        return true;
    else
        return false;

}

