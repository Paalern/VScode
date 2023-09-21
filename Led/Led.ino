#include <Adafruit_NeoPixel.h>

#define PIN 6	 // input pin Neopixel is attached to

#define NUMPIXELS      32 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // timing delay in milliseconds

int redColor = 0;
int greenColor = 0;
int blueColor = 0;
int sensorPin = A0;   // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int sensorPin1 = A1;   // select the input pin for the potentiometer
int sensorValue1 = 0; 
int sensorPin2 = A2;   // select the input pin for the potentiometer
int sensorValue2 = 0; 
int sensorPin3 = A3;   // select the input pin for the potentiometer
int sensorValue3 = 0; 


void setup() {
  // Initialize the NeoPixel library.
  pixels.begin();
  Serial.begin(9600);
}

void loop() {
  setColor();
  sensorValue = analogRead(sensorPin);
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  Serial.println(sensorValue);

  for (int i=0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));

    // This sends the updated pixel color to the hardware.
    pixels.show();

    // Delay for a period of time (in milliseconds).
    delay(sensorValue);
  }
}

// setColor()
// picks random values to set for RGB
void setColor(){
  redColor = random (0,sensorValue1);
  greenColor = random(0,sensorValue2);
  blueColor = random(0, sensorValue3);  
}