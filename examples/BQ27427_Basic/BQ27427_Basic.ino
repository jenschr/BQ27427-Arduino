/******************************************************************************
BQ274xx_Basic
BQ274xx Library Basic Example
Jim Lindblom @ SparkFun Electronics
May 9, 2016
https://github.com/sparkfun/SparkFun_BQ274xx_Arduino_Library

Demonstrates how to set up the BQ274xx and read state-of-charge (soc),
battery voltage, average current, remaining capacity, average power, and
state-of-health (soh).

After uploading, open up the serial monitor to 115200 baud to view your 
battery's stats.

Hardware Resources:
- Arduino Development Board
- SparkFun Battery Babysitter

Development environment specifics:
Arduino 1.6.7
SparkFun Battery Babysitter v1.0
Arduino Uno (any 'duino should do)
******************************************************************************/
//#include <ArduinoLog.h>
#include <Wire.h>
#include "BQ27427.h"

// Set BATTERY_CAPACITY to the design capacity of your battery.
const unsigned int BATTERY_CAPACITY = 2700; // e.g. 850mAh battery

BQ27427 lipo(BATTERY_CAPACITY);



//void printTimestampMillis(Print* logOutput) {
//  char c[64];
//  unsigned long mm = xTaskGetTickCount();//millis();
//  int ms = mm % 1000;
//  int s = mm / 1000;
//  int m = s / 60;
//  int h = m / 60;
//  int d = h / 24;
//  sprintf(c, "%02d:%02d:%02d:%02d.%03d ", d, h % 24, m % 60, s % 60, ms);
//  logOutput->print(c);
//}
//
//void setupLogging() {
//  #ifndef DISABLE_LOGGING
//    Log.begin(LOG_LEVEL, &Serial);
//    Log.setPrefix(printTimestampMillis);
//    Log.trace("setupLogging()" CR);
//  #endif  //  #ifndef DISABLE_LOGGING
//}


void setupBQ274xx(void)
{
  // Use lipo.begin() to initialize the BQ274xx-G1A and confirm that it's
  // connected and communicating.
  if (!lipo.begin()) // begin() will return true if communication is successful
  {
  // If communication fails, print an error message and loop forever.
    Serial.println("Error: Unable to communicate with BQ27427.");
    Serial.println("  Check wiring and try again.");
    Serial.println("  (Battery must be plugged into Battery Babysitter!)");
    while (1) ;
  }
  Serial.println("Connected to BQ27427!");
}

void printBatteryStats()
{
  // Read battery stats from the BQ27427
  unsigned int soc = lipo.soc();  // Read state-of-charge (%)
  unsigned int volts = lipo.voltage(); // Read battery voltage (mV)
  int current = lipo.current(AVG); // Read average current (mA)
  unsigned int fullCapacity = lipo.capacity(FULL); // Read full capacity (mAh)
  unsigned int capacity = lipo.capacity(REMAIN); // Read remaining capacity (mAh)
  int power = lipo.power(); // Read average power draw (mW)
  int health = lipo.soh(); // Read state-of-health (%)

  // Now print out those values:
  String toPrint = String(soc) + "% | ";
  toPrint += String(volts) + " mV | ";
  toPrint += String(current) + " mA | ";
  toPrint += String(capacity) + " / ";
  toPrint += String(fullCapacity) + " mAh | ";
  toPrint += String(power) + " mW | ";
  toPrint += String(health) + "%";
  
  Serial.println(toPrint);
}

void setup()
{
  Serial.begin(115200);
//  setupLogging();
  setupBQ274xx();
}

void loop() 
{
  printBatteryStats();
  delay(1000);
}