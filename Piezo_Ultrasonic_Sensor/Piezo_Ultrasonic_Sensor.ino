#include <ESP32Tone.h>
#define TRIG_PIN   26 // GIOP26 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN   25 // GIOP25 connected to Ultrasonic Sensor's ECHO pin
#define BUZZER_PIN 18 // GIOP18 connected to Piezo Buzzer's pin

float duration_, distance_cm, distance_ft, MAX_DISTANCE;

void setup() {
  Serial.begin (9600);         // initialize serial port
  pinMode(TRIG_PIN, OUTPUT);   // set pin 26 to output mode
  pinMode(ECHO_PIN, INPUT);    // set pin 25 to input mode
  pinMode(BUZZER_PIN, OUTPUT); // set pin 18 to output mode
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_ = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_;
  distance_ft = distance_cm / 30.48;
  MAX_DISTANCE = 50 / 30.48;

  if (distance_ft < MAX_DISTANCE){
    tone(BUZZER_PIN, 1000, 900); // turn on Piezo Buzzer
    delay(1000);
    noTone(BUZZER_PIN);
  }
  else
    digitalWrite(BUZZER_PIN, LOW);  // turn off Piezo Buzzer

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_ft);
  Serial.println(" ft");

  delay(500);
}
