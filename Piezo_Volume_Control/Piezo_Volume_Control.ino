#define TRIG_PIN   26 // GIOP26 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN   25 // GIOP25 connected to Ultrasonic Sensor's ECHO pin
#define BUZZER_PIN 18 // GIOP18 connected to Piezo Buzzer's pin

float duration_, distance_cm, MAX_DISTANCE = 50;

// create variables for the frequency, channel assigned, number of bit resolution and duty cycle for the PWM signal
int frequency = 5000, channel = 0, resolution = 8, duty_cycle = 75;

void setup() {
  Serial.begin (9600);         // initialize serial port
  pinMode(TRIG_PIN, OUTPUT);   // set pin 26 to output mode
  pinMode(ECHO_PIN, INPUT);    // set pin 25 to input mode
  pinMode(BUZZER_PIN, OUTPUT); // set pin 18 to output mode

  ledcSetup(channel, frequency, resolution);
  ledcAttachPin(18, channel);
}

void loop() {

  ledcWriteTone(channel, 2000);
  
  
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_ = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_;

  if (distance_cm < MAX_DISTANCE)
    ledcWrite(channel, duty_cycle); // turn on Piezo Buzzer
  else
    ledcWriteTone(channel, LOW);  // turn off Piezo Buzzer

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}
