#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "printf.h" // Include if using a custom printf function
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


// Define pins for CE and CSN
#define start 8
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0xBC ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int CE_PIN = 9;
const int CSN_PIN = 10;
const int analogInPin = A0;

// Define address for communication
const byte addresses[][6] = {"1Node","2Node"};
// Create an instance of the radio object
RF24 radio(CE_PIN, CSN_PIN);

float batteryVoltage = 9.0; 
float voltageDividerRatio = 2.727; // Ratio of voltage divider resistors 


// const char dataToSend[] = "Hello!"; 
const char dataToSend[][6] = {"50.18", "50.22", "50.26", "50.29", "50.34", "50.37", "50.41", "50.44", "50.48", "50.51"}; 
const int num_messages = sizeof(dataToSend) / sizeof(dataToSend[0]);
char dataReceived[6] = "Hello";;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(start, INPUT);
   pinMode(analogInPin,INPUT); 

  // Start the SPI library
SPI.begin();


radio.begin();
if (!radio.begin()) {
 Serial.println(F("radio hardware is not responding!!"));
 while (1) {} // hold in infinite loop
}
Serial.println("Hardware is responding!");
if(!display.begin(SSD1306_SWITCHCAPVCC, 0xBC)){
  Serial.println(F("SSD1306 allocation failed"));
  for (;;); 
}

display.clearDisplay();
display.setTextSize(2);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0,0);
display.println(F("Hello!"));
display.display(); 

// Open the reading pipe with the address
radio.openReadingPipe(0, addresses[0]);  // Change index for different transmitter

// Set the data rate and payload size
radio.setDataRate(RF24_250KBPS);
radio.setPayloadSize(sizeof(dataReceived));
radio.setPALevel(RF24_PA_MIN); 
radio.setChannel(0);
radio.startListening();
// Print details for debugging (optional)
printf_begin();
radio.printDetails();


}

void loop() {
  // put your main code here, to run repeatedly:
    // Check if there is data available
  bool currentState = digitalRead(start);
  if (currentState==false){
    while(digitalRead(start)==false){
      // do nothing while the button is pressed
    }
while(!radio.available()); 
while (radio.available()) {
  // Read the data
    radio.read(&dataReceived, sizeof(dataReceived));
    int battery = getBatteryLevel(); 
    drawBatteryLevel(battery);
    display.setTextSize(3);
    display.setCursor(0,20);
    display.print(dataReceived);//display weight
    display.print("g");
    display.display(); 
    Serial.print(dataReceived);
    Serial.print("g");
    Serial.print("\n");

    delay(1000);
  }
  }
  
}

int getBatteryLevel(){

  int sensorLevel = analogRead(analogInPin);
  float voltage = sensorLevel * (5.0 / 1023.0)*voltageDividerRatio; 
  int batteryLevel = map(voltage, 0, batteryVoltage, 0, 100);
  return batteryLevel; 
}


void drawBatteryLevel(int batLevel){
  // Clear the display buffer
  display.clearDisplay();
  
  // Define the dimensions of the battery rectangle
  int batteryWidth = 30; // Width of the battery rectangle
  int batteryHeight = 15; // Height of the battery rectangle
  int batteryX = 0; // X-coordinate of the top-left corner of the battery rectangle
  int batteryY = 0; // Y-coordinate of the top-left corner of the battery rectangle
  
  // Calculate the width of the battery bar based on the level
  int barWidth = map(batLevel, 0, 100, 0, batteryWidth);

  display.setCursor(0,0);
    // Draw the battery outline
  display.drawRect(batteryX, batteryY, batteryWidth, batteryHeight, WHITE);
  
  // Draw the filled battery bar
  display.fillRect(batteryX, batteryY, barWidth, batteryHeight, WHITE);
  
  // Display the percentage text
  display.setTextSize(1); // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(30,0);
  display.print(batLevel);
  display.print("%");
}


