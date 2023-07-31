
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <Ultrasonic.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

#define FIREBASE_HOST "YOUR_FIREBASE_PROJECT_ID.firebaseio.com" 
// under the build tab go to realtime database to get this credential
#define FIREBASE_AUTH "YOUR_FIREBASE_REALTIME_DATABASE_SECRET" 
// project overview->project settings ->service accounts ->Database secrets -> scrol down
#define FIREBASE_URL "YOUR_FIREBASE_URL" 
// "https://your-firebase-project-id.firebaseapp.com" can be found under project overview->project settings->scrol down
//FIREBASE_URL is the specific location (path) within your Firebase Realtime Database where you want to store the data sent from ESP32

const int triggerPin = 27;
const int echoPin = 26;

Ultrasonic ultrasonic(triggerPin, echoPin);

void setup() {
  Serial.begin(115200);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  long duration = ultrasonic.timing();
  int distance = ultrasonic.convert(duration, Ultrasonic::CM);

  bool interventionDetected = false;
  // Add your logic to detect human intervention based on the distance value.
  // For example, if the distance is below a threshold, set interventionDetected to true.

  if (interventionDetected) {
    sendDataToFirebase(distance);
  }

  delay(1000);
}

void sendDataToFirebase(int distance) {
  FirebaseJson json;
  json.add("distance", distance);
  json.add("intervention", true); // Assuming intervention is detected in this case

  String path = String(FIREBASE_URL) + "/" + String(millis());
  Firebase.pushJSON(FIREBASE_HOST, path.c_str(), json);
}

  
      
    
