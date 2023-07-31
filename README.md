# First-line-of-defence

Building a system with an ESP32, ultrasonic sensor, and Firebase to detect human intervention in a restricted area and update information in Firebase.
Below is the outline of the process.
1. Hardware Setup:

For this project, you'll need the following components:

->ESP32 development board
->Ultrasonic distance sensor (HC-SR04)
->Jumper wires
Now, let's connect the ultrasonic sensor to the ESP32.

Ultrasonic Sensor            ESP32

VCC ------------------> 3.3V

GND ------------------> GND

Trigger --------------> GPIO 12 (D12)

Echo -----------------> GPIO 14 (D14)



2. WiFi Setup:
In this step, we'll connect the ESP32 to a WiFi network using the ESP32 WiFi library. You'll need to have the ESP32 board package installed in your Arduino IDE and select the correct board and COM port before proceeding.
The code for the wifi setup can be found in repository

3. Ultrasonic Sensor Readings:
In this step, we'll set up the ultrasonic sensor to measure distance periodically. When the sensor detects a change in distance (human intervention), we'll trigger an event.
once the ultrasonic sensor readings are verified move on to next step

4. Setting up firebase:
To get Firebase credentials for your project, follow these steps:
1. Go to the Firebase Console: Visit the Firebase Console website at https://console.firebase.google.com/.
2. Sign in or Create an Account: If you already have a Google account, sign in. Otherwise, create a new account.
3. Create a New Project: Click on the "Add project" button to create a new Firebase project. Give your project a name and choose your country/region. You can also enable Google Analytics for your project if desired.
4. Access Project Settings: After the project is created, click on the gear icon (⚙️) next to "Project Overview" on the left sidebar to access the project settings.
5. Go to Project Settings: In the project settings, navigate to the "General" tab.
6. Get Your Credentials: Scroll down to find the "Your apps" section. Click on the "</>" icon to add a new web app to your project.
7. Register Your App: Provide a nickname for your app (e.g., "MyApp") and click "Register app."
8. Get Firebase Config: After registering your app, Firebase will generate your configuration data, including your Firebase Project ID, API Key, and other settings. Copy this configuration data, as you will need it to connect your application to Firebase.
Now you have your Firebase credentials, including your Firebase Project ID and API Key. These credentials are required to initialize Firebase in your ESP32 code and interact with the Firebase Realtime Database.

Note: To enable web api go to authentication tab and finish authentiction step.

5. Build a Firebase database
Build->Realtime database 

6. Firebase Integration and Sending data to Firebase:
In this step, we'll integrate Firebase with the ESP32 to store data related to the human intervention event. We'll use the Firebase ESP32 library, which provides functions to interact with the Firebase Realtime Database.

TO Install the Firebase ESP32 library (if you haven't already):
Open the Arduino IDE.
Go to "Sketch" > "Include Library" > "Manage Libraries..."
Search for "Firebase ESP32" and install the library.
Define your Firebase credentials (replace "YOUR_FIREBASE_PROJECT_ID", "YOUR_FIREBASE_DATABASE_SECRET", and "YOUR_FIREBASE_URL" with your actual Firebase credentials) in final.ino 

7.You can create a basic html page to view the status of restricted area



