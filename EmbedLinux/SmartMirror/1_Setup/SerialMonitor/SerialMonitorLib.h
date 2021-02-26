#ifndef SerialMonitorLib_h
#define SerialMonitorLib_h

#include "Arduino.h"

/*
 * SerialMonitor - Arduino "Library"
 * Singleton class - Setup rx, tx dependent upon Arduino board
 *                 - Baud rate dependent on TX of source
 */
 
class SerialMonitor
{
public:
  /*
   * Singleton Pattern - Static allocation
   */
  static SerialMonitor& Instance(int rx_pin, int tx_pin, long baud_rate)
  {
    static SerialMonitor instance(rx_pin, tx_pin, baud_rate);
    return instance;
  }

  /*
   * Read()
   * Read the Arduino RX pins and print to the Arduino IDE Serial Monitor
   */
  void Read();

protected:
  /*
   * Constructor
   * Initialize member vars
   * Setup Serial pinModes
   * Delay until Serial is ready to receive
   */
  SerialMonitor(int rx_pin, int tx_pin, long baud_rate);

  
private:
  static SerialMonitor* inst_; // Declare this in .cpp file to compile
  int rx_serial_pin_;
  int tx_serial_pin_;
  long baud_rate_;
};

#endif

