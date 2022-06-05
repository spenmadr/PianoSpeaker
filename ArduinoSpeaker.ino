// uses ultrasonic sensor and speaker to replicate a piano
// general notes:
//  echo pin: sends signal when reflected wave is recieved
//  trig pin: sends signal representing distance when sensor is triggered

//#include"ANote.h"

#include <PCM.h>

// stores frequency values for different notes
#include"notes.h"

// creates references to pin numbers and defines constants
#define trigPin 11
#define echoPin 12
#define speaker 13
#define spd 0.0343 //speed of sound in cm/s
#define offset 0 // offsets the position 0 for the sensor in cm (min range of sensor is 2cm)
#define interval 6 // length of each key

int notes[] = {noteA, noteB, noteC, noteD, noteE, noteF, noteG}; // array of note frequencies

// initializes digital pin modes
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

// continuously scans for sensor input and plays or doesn't play notes accordingly
void loop() {
  long duration, distance; // initializes duration and distance variable
  digitalWrite(trigPin, LOW); // sets trigPin to LOW
  delayMicroseconds(2); // must be some delay
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // sets duration as time for sound to travel back and forth
  distance = (spd * duration) / 2; // sets distance as the one-way distance for the sound, spd is in cm/s, duration in s
  noTone(speaker); // turns off speaker if not already off
  if (distance >= offset && distance <= interval * sizeof(notes) + offset) { // checks that the detection is within range
    tone(speaker, notes[(distance - offset) / interval] ); // plays frequency whose value is based on the distance from the sensor
  }
  Serial.print(distance);
  delay(500);
}
