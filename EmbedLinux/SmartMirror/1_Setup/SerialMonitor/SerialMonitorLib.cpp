#include "Arduino.h"
#include "SerialMonitorLib.h"

static SerialMonitor* SerialMonitor::inst_ = NULL;

SerialMonitor::SerialMonitor(int rx_pin, 
                             int tx_pin, 
                             long baud_rate) : rx_serial_pin_(rx_pin),
                                               tx_serial_pin_(tx_pin),
                                               baud_rate_(baud_rate)
{
  pinMode(rx_pin, INPUT);
  //pinMode(tx_pin, OUTPUT); // leave me commented please (see comments in .iso)
  
  Serial.begin(baud_rate_);
  while (!Serial)
  {
    ;
  }
}

void SerialMonitor::Read()
{
  static bool UART_connected = false;
  if(Serial.available())
  {
    int incomingByte = Serial.read();

    Serial.println(incomingByte, DEC);
    if(!UART_connected)
      UART_connected = true;
  }
  else
  {
    static long message_count = 0;
    if(!UART_connected)
     {
      if(message_count >= 200000)
      {
        Serial.println("Waiting for first UART Connection...");
        message_count = 0;
      }
      
      message_count++;
    }
  }
}



