#include "SerialMonitorLib.h"

/* github.com/brmmflynn/brmflynn.github.io
 * 
 * 
 * SerialMonitor main
 * 
 * RPi4 UART Serial Monitor
 * Intended use for serial reading of RPi4 UART
 * **DO NOT TRANSMIT TO RPi UART GPIO**
 * 115200 baud, 8 bits, no parity, 1 stop bit (Ardunio config SERIAL_8N1 (default))
 */

/*
 * Note - Wait for upload to finish before opening the 
 *        Arduino Serial Monitor - ctrl-shift-m
 */

SerialMonitor* s_mon;

void setup() {
  // Arduino UNO pins
  int rx_pin = 0;
  int tx_pin = 1;  // DO NOT NOT NOT NOT NOT 
                   // NEVER NEVER NEVER EVER
                   // CONNECT THIS TO THE RPI GPIO RX
                   // (Without a 3.3V Regulator)

  // RPi4 TX Baud Rate
  long baud_rate = 115200;
  s_mon = &(s_mon->Instance(rx_pin, tx_pin, baud_rate));
}

void loop() {
  s_mon->Read();
}
