#include <HX711_ADC.h>
#include <SPI.h>
#include <RF24.h>
#if defined(ESP8266)|| defined(ESP32) || defined(AVR)
#include <EEPROM.h>
#endif

// Pins:
// Constants won't change. They're used here to set pin numbers:
const int HX711_dout = 4; // MCU > HX711 dout pin
const int HX711_sck = 5; // MCU > HX711 sck pin

// HX711 constructor:
HX711_ADC LoadCell(HX711_dout, HX711_sck);

RF24 radio(9, 10); 
const byte addresses[][6] = {"00001", "00002"}; 

const int calVal_eepromAdress = 0;
unsigned long t = 0;
volatile bool processRunning = false; // Variable to track if the process is running

void setup() {
  // Initialize the pushbutton pin as an input:

  // radio.begin();
  // radio.openWritingPipe(addresses[1]);
  // radio.openReadingPipe(4, addresses[0]); 
  // radio.setPALevel(RF24_PA_MIN); 

  Serial.begin(57600); delay(10);
  Serial.println();
  Serial.println("Starting...");

  LoadCell.begin();
  // LoadCell.setReverseOutput(); // Uncomment to turn a negative output value to positive
  float calibrationValue; // Calibration value (see example file "Calibration.ino")
 // calibrationValue = 696.0; // Uncomment this if you want to set the calibration value in the sketch
#if defined(ESP8266)|| defined(ESP32)
  // EEPROM.begin(512); // Uncomment this if you use ESP8266/ESP32 and want to fetch the calibration value from EEPROM
#endif
  EEPROM.get(calVal_eepromAdress, calibrationValue); // Uncomment this if you want to fetch the calibration value from EEPROM

  unsigned long stabilizingtime = 2000; // Precision right after power-up can be improved by adding a few seconds of stabilizing time
  boolean _tare = true; // Set this to false if you don't want tare to be performed in the next step
  LoadCell.start(stabilizingtime, _tare);
  if (LoadCell.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU > HX711 wiring and pin designations");
    while (1);
  }
  else {
    LoadCell.setCalFactor(calibrationValue); // Set calibration value (float)
    Serial.println("Startup is complete");
  }

  Serial.println("Send 's' from the serial monitor to start the process.");
}

void loop() {
  // Check for incoming characters without blocking
  if (Serial.available()) {
    char inByte = Serial.read();
    if (inByte == 's') {
      processRunning = true;
      Serial.println("Process started.");
      Serial.println(LoadCell.getCalFactor());
      LoadCell.powerUp();
    } else if (inByte == 'p') {
      processRunning = false;
      Serial.println("Process stopped.");
      LoadCell.powerDown();
    } else if (inByte == 't') {
      LoadCell.tareNoDelay();
      if (LoadCell.getTareStatus() == true) {
    Serial.println("Tare complete");
    }
    }
    }

  if (processRunning) {
  static boolean newDataReady = 0;
  const int serialPrintInterval = 1; //increase value to slow down serial print activity

  // check for new data/start next conversion:
  if (LoadCell.update()) newDataReady = true;

  // get smoothed value from the dataset:
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      float i = LoadCell.getData();
      float j = LoadCell.getData_MA();
      float k = LoadCell.getData_Median();
      float h = LoadCell.getData_Exp();
      // if (i < 0.1 ) {
      //   i = 0.00;
      //   Serial.println(i);
      //   newDataReady = 0;
      //   t = millis();
      // }
      // else {
        Serial.println(String(i) + "," + String(j) + "," + String(k) + "," + String(h));

      // Serial.println("______________________________________________________________________________________________________");  
      // Serial.println("Average excluding extremes");
      // Serial.println(i);
      // Serial.println("Moving average");
      // Serial.println(j);
      // Serial.println("Median filter");
      // Serial.println(k);
      // Serial.println("Exponential Filter");
      // Serial.println(h);
      // Serial.println("______________________________________________________________________________________________________");  
      //Serial.println(LoadCell.movingAverageData());
      newDataReady = 0;
      t = millis();
      //}
    }
  }
}
}


