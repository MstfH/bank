#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"

// Arduino transmit  BLUE WIRE  labeled RX on printer
// Arduino receive   GREEN WIRE   labeled TX on printer
#define TX_PIN A0
#define RX_PIN A1

// for incoming serial data
int incomingByte = 0;
String printData;

SoftwareSerial mySerial(RX_PIN, TX_PIN);
// Pass addr to printer constructor
Adafruit_Thermal printer(&mySerial);

void setup() {
  // NOTE: SOME PRINTERS NEED 19200 BAUD instead of 9600
  mySerial.begin(9600);
  // Use this instead if using hardware serial
  //Serial1.begin(19200);
}

void loop(){
  if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = mySerial.read();
                if(incomingByte == 'B'){
                  printData = String(mySerial.read());
                  printData.trim();
                }
        }
}

void print(string amount, string location, string iban, string time, string date, string transaction){
  printer.begin();

  //prints a big title
  printer.setSize('L');
  printer.underlineOn();
  printer.justify('C');
  printer.println(F("MONARCH DOUGLAS"));
  printer.underlineOff();

  //prints a huge size text
  printer.doubleHeightOn();
  printer.doubleWidthOn();
  printer.justify('C');
  printer.println(F("BANK"));
  printer.doubleHeightOff();

  //Sets a horizontal line
  printer.justify('C');
  printer.println(F("----------------"));
  printer.doubleWidthOff();

  //prints a bold text left
  printer.boldOn();
  printer.justify('L');
  printer.println(F("Locatie"));
  printer.boldOff();

  //prints a variable after some space
  printer.justify('L');
  printer.print(F("     "));
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
  printer.print(F(date));
  printer.print(F("        "));
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
  printer.println(F(amount));

  //prints double line for the end of the receipt
  printer.doubleWidthOn();
  printer.justify('C');
  printer.println(F("----------------"));
  printer.println(F("----------------"));
  printer.doubleWidthOff();

  //empty space
  printer.feed(2);

  // Tell printer to sleep
  printer.sleep();      
  delay(3000L);
  // MUST wake() before printing again, even if reset
  printer.wake();       
  // Restore printer to defaults
  printer.setDefault(); 
}
