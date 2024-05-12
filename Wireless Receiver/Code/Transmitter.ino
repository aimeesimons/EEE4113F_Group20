#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "printf.h" // Include if using a custom printf function

// Define pins for CE and CSN
const int CE_PIN = 9;
const int CSN_PIN = 10;

// Define address for communication
const byte addresses[][6] = {"1Node","2Node"};
// Create an instance of the radio object
RF24 radio(CE_PIN, CSN_PIN);

const char dataToSend[][6] = {"50.18", "50.22", "50.26", "50.29", "50.34", "50.37", "50.41", "50.44", "50.48", "50.51"}; 
const int num_messages = sizeof(dataToSend) / sizeof(dataToSend[0]);


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);

  // Start the SPI library
SPI.begin();


radio.begin();
if (!radio.begin()) {
 Serial.println(F("radio hardware is not responding!!"));
 while (1) {} // hold in infinite loop
}
Serial.println("Hardware is responding!");
// Open the reading pipe with the address
radio.openWritingPipe(addresses[0]);  // Change index for different transmitter

// Set the data rate and payload size
radio.setDataRate(RF24_250KBPS);
radio.setPayloadSize(sizeof(dataToSend[0]));
radio.setPALevel(RF24_PA_MIN); 
radio.setChannel(0);
radio.stopListening();
// Print details for debugging (optional)
// printf_begin();
// radio.printDetails();


}

void loop() {
// put your main code here, to run repeatedly:
for (int i=0; i<num_messages; i++){
  radio.write(&dataToSend[i], sizeof(dataToSend[i]));
  Serial.println("Data sent!");
  // Wait a bit before sending again
  delay(1000);
}

}
