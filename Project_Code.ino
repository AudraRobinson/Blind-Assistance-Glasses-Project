//downloaded library that allows the ESP32 to use servo and PWM functions like the Arduino
#include <ESP32Tone.h>
//define pin numbers 
#define TRIG_PIN 26
#define ECHO_PIN 25
#define buzzPin 18

// define variables 
float duration, distance_cm, distance_ft, MIN_DISTANCE;

void setup(){ 
  Serial.begin (9600);         // initialize serial port
  pinMode(TRIG_PIN, OUTPUT);   // set pin 26 to output mode
  pinMode(ECHO_PIN, INPUT);    // set pin 25 to input mode
  pinMode(buzzPin, OUTPUT);    // set pin 18 to output mode
}

void loop() {
 //clear the trigPin 
 digitalWrite(TRIG_PIN, LOW); 
 delayMicroseconds(2); 

 //set the trigPin on HIGH state 
 digitalWrite(TRIG_PIN, HIGH);
 delayMicroseconds(10);
 digitalWrite(TRIG_PIN, LOW); 

 //read the echoPin & return the sound wave travel time (microseconds)
 duration = pulseIn(ECHO_PIN, HIGH); 

//conversion from microseconds to inches
long microsecondstoInches = (duration / 74) / 2;

//calculate the distance (inches to feet)
distance_ft = microsecondstoInches * 12;

//set minimum distance (6 ft.) for ultrasonic sensor
MIN_DISTANCE = 182.88 / 30.48;

while (distance_ft <= MIN_DISTANCE) {
 if (distance_ft > 5.01 && distance_ft <= 6.00){
    tone(buzzPin, 1000, 200); // turn on Piezo Buzzer
    delay(1000);
    noTone(buzzPin);
    // print the value to Serial Monitor
    Serial.print("distance: ");
    Serial.print(distance_ft);
    Serial.println(" ft");
    delay(500);
}
else if (distance_ft >= 4.01 && distance_ft < 5.00){
    tone(buzzPin, 1000, 300); // turn on Piezo Buzzer
    delay(1000);
    noTone(buzzPin);
    // print the value to Serial Monitor
    Serial.print("distance: ");
    Serial.print(distance_ft);
    Serial.println(" ft");
    delay(500);
}
else if (distance_ft >= 3.01 && distance_ft < 4.00){
    tone(buzzPin, 1000, 400); // turn on Piezo Buzzer
    delay(1000);
    noTone(buzzPin);
    // print the value to Serial Monitor
    Serial.print("distance: ");
    Serial.print(distance_ft);
    Serial.println(" ft");
    delay(500);
}
else if (distance_ft >= 2.01 && distance_ft < 3.00){
    tone(buzzPin, 1000, 500); // turn on Piezo Buzzer
    delay(1000);
    noTone(buzzPin);
    // print the value to Serial Monitor
    Serial.print("distance: ");
    Serial.print(distance_ft);
    Serial.println(" ft");
    delay(500);
}
else if (distance_ft >= 1.01 && distance_ft < 2.00){
    tone(buzzPin, 1000, 600); // turn on Piezo Buzzer
    delay(1000);
    noTone(buzzPin);
    // print the value to Serial Monitor
    Serial.print("distance: ");
    Serial.print(distance_ft);
    Serial.println(" ft");
    delay(500);
}
else if (distance_ft >= 0 && distance_ft < 1.00){
    tone(buzzPin, 1000, 700); // turn on Piezo Buzzer
    delay(1000);
    noTone(buzzPin);
    // print the value to Serial Monitor
    Serial.print("distance: ");
    Serial.print(distance_ft);
    Serial.println(" ft");
    delay(500);
}
else {
  digitalWrite(buzzPin, LOW);
}

}

}
