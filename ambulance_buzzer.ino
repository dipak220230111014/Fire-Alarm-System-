// 🚑 Ambulance Style Siren + LED Alert
int flameSensor = D2; // Flame sensor pin
int buzzer = D5;      // Buzzer pin (Passive buzzer recommended)
int led = D6;         // LED pin

void setup() {
  Serial.begin(115200);
  pinMode(flameSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.println("===============");
  Serial.println(" FLAME SENSOR ALERT SYSTEM ");
  Serial.println("===============");
}

// Ambulance Siren Function
void ambulanceSiren() {
  // High tone (Veeeeeee)
  tone(buzzer, 1200);
  digitalWrite(led, HIGH);
  delay(700);

  // Low tone (Oooooooo)
  tone(buzzer, 600);
  digitalWrite(led, LOW);
  delay(700);
}

void loop() {
  int sensorValue = digitalRead(flameSensor);
  Serial.println("Sensor Value: " + String(sensorValue));

  if (sensorValue == 0) { // Flame detected
    Serial.println(">>> EMERGENCY! FLAME DETECTED! <<<");
    ambulanceSiren();
  }
  else {
    noTone(buzzer);
    digitalWrite(led, LOW);
    delay(300);
  }
}
