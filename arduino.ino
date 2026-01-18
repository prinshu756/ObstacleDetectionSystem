#include <Servo.h>
#include <LiquidCrystal.h>
 
Servo myservo;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 

const int trigPin = 9;
const int echoPin = 10;
const int moteur = 11;
const int buzzer = 12;
const int ledPin1 = 14;
const int ledPin2 = 15;

int pos = 0;
float distanceCm, duration;
const float obstacleThreshold = 319; 

void setup() {
  myservo.attach(moteur);
  lcd.begin(16, 2); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

float readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void displayData(int angle, float distance) {
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm ");
  lcd.setCursor(0, 1);
  lcd.print("Angle : ");
  lcd.print(angle);
  lcd.print(" deg ");
}

void loop() {
  for (pos = 0; pos <= 180; pos += 5) {
    myservo.write(pos);
    distanceCm = readDistance();

    // If obstacle detected
    if (distanceCm < obstacleThreshold) {
      tone(buzzer, 1000); // beep
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
    } else {
      noTone(buzzer); 
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
    }

    displayData(pos, distanceCm);
    delay(100); 
  }

  // Sweep back from 180 to 0
  for (pos = 180; pos >= 0; pos -= 5) {
    myservo.write(pos);
    distanceCm = readDistance();

    if (distanceCm < obstacleThreshold) {
      tone(buzzer, 1000);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
    } else {
      noTone(buzzer);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
    }

    displayData(pos, distanceCm);
    delay(100);
  }
}
