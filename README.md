# Robot-Control-Buddy
"Controller" (Emulates Keyboard) to send Enable/Disable/E-Stop commands FRC Robotics through the FRC Driverstation through keyboard shortcuts

**For ATmega32u4 based Microcontrollers (Arduino Leonardo, Micro, Pro Micro, ect.)**

Monitors inputs and sends FRC Driverstation Keyboard Shortcuts when inputs go low

## Circuit
  * Buttons/Switches attached to pins for E-Stop, Disable, and Enable
    * E-STOP - Pin 9
    * DISABLE - Pin 7
    * ENABLE - Pin 8
  * Other leg of Button/Switch attached to GND
  * If Button/Switch is Normally Closed, reverse digitalRead() Logic
    * Remove Bang(!) from digitalRead() if statements

## CHANGELOG
  * Created 07 Feb 2021

