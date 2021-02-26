# Setup

## Introduction
There are three goals of setup:
1. Create an appropriate Virtual Machine for Embedded Linux development and Yocto image builds.
2. Create the first Yocto image and "upload" it to the RaspberryPi (and prove it).
3. Build a serial debugger to read the bootloader serial output.

## Ubuntu Virtual Machine Overview
Ok, let's begin - reminder I am using a Windows 10 machine - which Yocto does not support.\
Yocto only supports a limited number of Linux distros, so I chose Ubuntu.

General Steps:
1. Download VirtualBox
2. Download Ubuntu iso
3. Create the Ubuntu VM
4. *Optional* Fix the VirtualBox's fixed resolution.

### Download VirtualBox and Ubuntu
https://virtualbox.org - Download, go through installation process

https://ubuntu.com/download/desktop - Download (should be a .iso file)

### Create Ubuntu VM
Open VirtualBox, click new, name Ubuntu, when prompted point to the .iso file

Give the VM lots of RAM, CPU Cores, and >50GB of space (I gave it 80GB to be safe).\
If there's not enough space then Yocto will not be able to finish building (you'll find out 8 hours later).

Go through the rest of the Ubuntu OS installation process until you're on the Ubuntu Desktop

### *Optional* Fix the VM's Resolution
I get annoyed by things like fixed resolution, so I decided to dig into the problem. 

Here's how you fix it:
1. Open terminal in VM
```
sudo apt-get install virtualbox-guest-dkms
sudo apt-get install virtualbox-guest-utils
sudo apt-get install virtualbox-guest-x11
```
2. In the Virtual Machine window find the Devices tab then click the "Insert Guest Addition CD Image..." option.
3. Back in VM terminal:
```
cd /media/<username>/VBox_GAs_6.<X.X>
sudo ./VBoxLinuxAdditions.run
```
4. Restart the VM.

## Yocto First Image


## Arduino Serial Debugger
The serial debugger's purpose is to read the TX pin of the RaspberryPi4 (target) board.

Instead of buying a $10-20 USB UART connector, I decided to quickly throw together a serial debugger using the arduino.

### Hardware
Arduino RX pin is pin 0, GND is pin 14 (others).\
RaspberryPi TX pin is pin 8, GND is pin 6.\
RaspberriPi TX specs are 8 bits, no parity, 1 stop bit at 115200 baud rate.

**Important** The Arduino INPUT pin mode is a max of 5V sinking pin, RPi TX outputs a 3.3V HIGH, but it works! Why? Read the specs.

### Software
You can find my code in one of the Setup folders.\
This code can be easily refactored for other boards as needed.

### **Disclaimers**
*Note* this is not an Arduino tutorial, if you're interested in digging into Arduino there are plenty of other places to go.

Like anything else, it's very important to connect the pins properly because **THEY ARE NOT THE SAME VOLTAGE**\
**DO NOT CONNECT A 5V SOURCE TO A 3.3V INPUT**

Ok that's the last warning you'll get from me.\
In no way am I responsible for you damaging your RaspberryPi4 board.\
Always read your datasheet/pinouts/references or face GPIO (and other) catastrophic failures.
