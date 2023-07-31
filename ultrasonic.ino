#define TRIGGER_PIN 12 // GPIO 12 (D12)
#define ECHO_PIN 14    // GPIO 14 (D14)

int readDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2; // Convert to centimeters

  return distance;
}

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  int distance = readDistance();

  // Check if the distance has changed (human intervention detected)
  if (distance > 0) {
    // Trigger an event here (e.g., send data to Firebase)
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(1000); // Wait for 1 second before the next reading
}

