/*------------------------------------------------------------------------
  Example sketch for Adafruit Thermal Printer library for Arduino.
  Demonstrates a few text styles & layouts, bitmap printing, etc.

  IMPORTANT: DECLARATIONS DIFFER FROM PRIOR VERSIONS OF THIS LIBRARY.
  This is to support newer & more board types, especially ones that don't
  support SoftwareSerial (e.g. Arduino Due).  You can pass any Stream
  (e.g. Serial1) to the printer constructor.  See notes below.

  You may need to edit the PRINTER_FIRMWARE value in Adafruit_Thermal.h
  to match your printer (hold feed button on powerup for test page).
  ------------------------------------------------------------------------*/

#include "Adafruit_Thermal.h"
//#include "adalogo.h"
//#include "adaqrcode.h"

// Here's the new syntax when using SoftwareSerial (e.g. Arduino Uno) ----
// If using hardware serial instead, comment out or remove these lines:

#include "SoftwareSerial.h"
#define TX_PIN A0 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN A1 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor
// Then see setup() function regarding serial & printer begin() calls.

// Here's the syntax for hardware serial (e.g. Arduino Due) --------------
// Un-comment the following line if using hardware serial:

//Adafruit_Thermal printer(&Serial1);      // Or Serial2, Serial3, etc.

// -----------------------------------------------------------------------

void setup() {

  // This line is for compatibility with the Adafruit IotP project pack,
  // which uses pin 7 as a spare grounding point.  You only need this if
  // wired up the same way (w/3-pin header into pins 5/6/7):
  
  // NOTE: SOME PRINTERS NEED 9600 BAUD instead of 19200, check test page.
  mySerial.begin(9600);  // Initialize SoftwareSerial
  //Serial1.begin(19200); // Use this instead if using hardware serial
}

void print(string amount, string location, string iban, string time, string date, string transaction){
  printer.begin();        // Init printer (same regardless of serial type)

  // The following calls are in setup(), but don't *need* to be.  Use them
  // anywhere!  They're just here so they run one time and are not printed
  // over and over (which would happen if they were in loop() instead).
  // Some functions will feed a line when called, this is normal.

  printer.setSize('L');
  printer.underlineOn();
  printer.justify('C');
  printer.println(F("MONARCH DOUGLAS"));
  printer.underlineOff();

  printer.doubleHeightOn();
  printer.doubleWidthOn();
  printer.justify('C');
  printer.println(F("BANK"));
  printer.doubleHeightOff();

  //Sets a horizontal line
  printer.justify('C');
  printer.println(F("----------------"));
  printer.doubleWidthOff();

  printer.boldOn();
  printer.justify('L');
  printer.println(F("Locatie"));
  printer.boldOff();

  printer.justify('L');
  printer.print(F("     "));
  //fil with string variable
  printer.println(F(location));

  printer.doubleWidthOn();
  printer.justify('C');
  printer.println(F("----------------"));
  printer.doubleWidthOff();

  printer.boldOn();
  printer.justify('L');
  printer.println(F("Datum               Tijd"));
  printer.boldOff();

  printer.justify('L');
  printer.print(F("     "));
  //fil with string variable
  printer.print(F(date));
  printer.print(F("        "));
  //fil with string variable
  printer.println(F(time));

  printer.doubleWidthOn();
  printer.justify('C');
  printer.println(F("----------------"));
  printer.doubleWidthOff();

  printer.boldOn();
  printer.justify('L');
  printer.println(F("Transactienummer"));
  printer.boldOff();

  printer.justify('L');
  printer.print(F("     "));
  //fil with string variable
  printer.println(F(transaction));

  printer.doubleWidthOn();
  printer.justify('C');
  printer.println(F("----------------"));
  printer.doubleWidthOff();

  printer.boldOn();
  printer.justify('L');
  printer.println(F("Rekeningnummer"));
  printer.boldOff();

  printer.justify('L');
  printer.print(F("     *************"));
  //fil with string variable
  printer.println(F(iban));

  printer.doubleWidthOn();
  printer.justify('C');
  printer.println(F("----------------"));
  printer.doubleWidthOff();

  printer.boldOn();
  printer.justify('L');
  printer.println(F("Opgenomen bedrag"));
  printer.boldOff();

  printer.justify('L');
  printer.print(F("     $"));
  //fil with string variable
  printer.println(F(amount));

  printer.doubleWidthOn();
  printer.justify('C');
  printer.println(F("----------------"));
  printer.println(F("----------------"));
  printer.doubleWidthOff();

  //empty space
  printer.feed(2);

  printer.sleep();      // Tell printer to sleep
  delay(3000L);         // Sleep for 3 seconds
  printer.wake();       // MUST wake() before printing again, even if reset
  printer.setDefault(); // Restore printer to defaults
}
