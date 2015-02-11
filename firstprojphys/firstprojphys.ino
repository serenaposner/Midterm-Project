/*
The Betting Game
Serena Posner
DIGF 2B03 Physical Computing
OCAD University
Created on 020715
Based on:
AnalogReadSerial, public domain, http://arduino.cc/en/Tutorial/AnalogReadSerial
Button, DojoDave, http://arduino.cc/en/Tutorial/Button
Tone, Tom Igoe, http://arduino.cc/en/Tutorial/Tone
//this game uses buttons and sensors to create a game that allows 
//the user to drop a coin and bet on the outcome
*/


#include "pitches.h"

const int buttonPin = 2;     // the number of the pushbutton pin
//const int ledPin =  13;      // use LED to test, not needed in final game

int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };
int buttonState = 0; //reading on button
int sensorPin1 = A0; //Left photocell
int sensorPin2 = A1; //right photocell
int sensorValue1 = 0;
int sensorValue2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT);     
}

void loop(){
  sensorValue1 = analogRead(sensorPin1);  
  sensorValue2 = analogRead(sensorPin2);  
  buttonState = digitalRead(buttonPin);


  Serial.println(sensorValue1);
  Serial.println(sensorValue2);
  delay (500);
  if (buttonState == HIGH && sensorValue1 < 100){
    digitalWrite(ledPin, HIGH);
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(8);
  }  
  }
  if (buttonState == LOW && sensorValue2 < 100){
    digitalWrite(ledPin, HIGH);  
    for (int thisNote = 0; thisNote < 8; thisNote++) {

    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
 
    noTone(8);
  }
  }
  else{
    digitalWrite(ledPin, LOW); 
  }
}
