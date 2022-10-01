
#include <IRremote.h>
#include "PluggableUSBHID.h"
#include "USBKeyboard.h"

USBKeyboard Keyboard;
int IRPIN = 3;
int test = 4;

void setup() {

Serial.begin(9600);
Serial.println("Enabling IRin");
IrReceiver.begin(IRPIN, ENABLE_LED_FEEDBACK);

Serial.println("Enabled IRin");

}

void loop()

{

if (IrReceiver.decode()) {

Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
String thisString = String(IrReceiver.decodedIRData.decodedRawData, HEX);
   char buf[30];
   int length = thisString.length()+1;
   thisString.toCharArray(buf,length);
   Serial.println(buf);
Keyboard.printf(buf);
  Keyboard.printf(" \n\r");

IrReceiver.resume();

}

delay(500);

}
