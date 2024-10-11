#include <DHT.h>

const int AO_Pin = A0; // Connect the AO of MQ-4 sensor with analog channel 0 pin (A0) of Arduino
const int DO_Pin = 8; // Connect the DO of MQ-4 sensor with digital pin 8 (D8) of Arduino

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

int threshold; // Create a variable to store the digital output of the MQ-4 sensor
int AO_Out; // Create a variable to store the analog output of the MQ-4 sensor

// Set up
void setup() {
  Serial.begin(115200);  // Initialize serial monitor using a baud rate of 115200
  pinMode(DO_Pin, INPUT); // Set the D8 pin as a digital input pin
  dht.begin();
}

// Main loop
void loop() {
  AO_Out = analogRead(AO_Pin); // Read the analog output measurement sample from the MQ4 sensor's AO pin
  threshold = digitalRead(DO_Pin); // Read the digital output of MQ-4 sensor's DO pin
  
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.print("Threshold: "); // Print out the text "Threshold: "
  Serial.print(threshold); // Print the threshold reached - with will either print be LOW or HIGH (above or underneath)
  Serial.print(", "); // print a comma and space

  Serial.print("Methane Concentration: "); // Print out the text "Methane Concentration: "
  Serial.println(AO_Out); // Print out the methane value - the analog output - between 0 and 1023

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000); // Set a 2 second delay
}