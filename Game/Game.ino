//Det under er standard kode for å legge inn Neopixel stripa
#include <Adafruit_NeoPixel.h>

#define PIN 6	 // input pin Neopixel is attached to

#define NUMPIXELS      32 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//RGB led fargene startverdi
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

//På knapp
int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;

//Hastighetsknapp funksjoner
int buttonState2 = 0;
int lastButtonState2 = 0;
int buttonPushCounter2 = 0;

//FArgebytter funksjoner
int buttonState3 = 0;
int lastButtonState3 = 0;
int buttonPushCounter3 = 0;

int delayvariabel = 0;

void setup() {
 
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(9, INPUT);
  pixels.begin(); // // Initialize the NeoPixel library.
  Serial.begin(9600); //Kobler opp monitoren
}

void trykksenser() //Bryteren for av og på knapp
{
  // read the pushbutton input pin
  buttonState = digitalRead(13);
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH, then the button
      // went from off to on
      buttonPushCounter += 1;
      Serial.println();
      Serial.println("Paknapp er trykket");
      Serial.print("Antall trykk: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW, then the button
      // went from on to off
      Serial.println("off");
    }
    // delay a little bit to avoid debouncing
    delay(5); // Wait for 5 millisecond(s)
  }
  // save the current state as the last state, for
  // the next time through the loop
  lastButtonState = buttonState;
}
 
void HastighetsBytter() //Brytterene for hastighet
{
  // read the pushbutton input pin
  buttonState2 = digitalRead(12);
  // compare the buttonState to its previous state
  if (buttonState2 != lastButtonState2) {
    // if the state has changed, increment the counter
    if (buttonState2 == HIGH) {
      // if the current state is HIGH, then the button
      // went from off to on
      buttonPushCounter2 += 1;
      Serial.println();
      Serial.println("Hastighetsbytter er trykket:");
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter2);
    } else {
      // if the current state is LOW, then the button
      // went from on to off
      Serial.println("off");
    }
    // delay a little bit to avoid debouncing
    delay(50); // Wait for 5 millisecond(s)
  }
  // save the current state as the last state, for
  // the next time through the loop
  lastButtonState2 = buttonState2;
}

void fargeBytter() //Bryteren for fargebytting
{
  // read the pushbutton input pin
  buttonState3 = digitalRead(9);
  // compare the buttonState to its previous state
  if (buttonState3 != lastButtonState3) {
    // if the state has changed, increment the counter
    if (buttonState3 == HIGH) {
      // if the current state is HIGH, then the button
      // went from off to on
      buttonPushCounter3 += 1;
      Serial.println();
      Serial.println("Fargebytter er:");
      Serial.println("on");
      Serial.print("Antall trykk: ");
      Serial.println(buttonPushCounter3);
    } else {
      // if the current state is LOW, then the button
      // went from on to off
      Serial.println("off");
    }
    // delay a little bit to avoid debouncing
    delay(50); // Wait for 5 millisecond(s)
  }
  // save the current state as the last state, for
  // the next time through the loop
  lastButtonState3 = buttonState3;
}

/*Her er koden som setter fargen. Denne velger mellom to faktorer
enten om man skal hente randome nummeret fra 100-255, eller 0-100.
Denne er også styr av en odetall/partall funksjon.*/



/*Koden under endrer delayvariabel.DEnne brukes i skrulyson og
sier hvor lang tid det skal ta før neopixel lyset gjennomfører en loop.
Brukte en enkel partall oddetalls funksjon for å skru denne av og på*/
void setSpeed() {
  if (buttonPushCounter2 % 2 == 0) {
    delayvariabel = 100;
  } else {
    delayvariabel = 3;
  }
}


/*Under er påknappen. denne henter informasjon fra buttonPushCounter.
Avhengig om denne er på et oddetall eller partall*/

void skrulysOn()
{
    if (buttonPushCounter % 2){ //Odetall
    for (int i=0; i < NUMPIXELS; i++) {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));
      pixels.setBrightness(155); 
      // This sends the updated pixel color to the hardware.
      pixels.show();

      // Delay for a period of time (in milliseconds).
      delay(delayvariabel);
      
   if(buttonPushCounter % 1) //Partall
  {
    Serial.println("Lys er av");
     
  }
    }
  }
}

void loop() {
  redColor=255;
  blueColor= 255;
  greenColor = 255;
  skrulysOn();
  trykksenser(); 
  HastighetsBytter();
  fargeBytter();
  setSpeed();
  
}
  


  
