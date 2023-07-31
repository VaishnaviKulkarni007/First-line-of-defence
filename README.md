# First-line-of-defence

Building a system with an ESP32, ultrasonic sensor, and Firebase to detect human intervention in a restricted area and update information in Firebase.
Below is the outline of the process.
1. Hardware Setup:

For this project, you'll need the following components:

->ESP32 development board
->Ultrasonic distance sensor (HC-SR04)
->Jumper wires
Now, let's connect the ultrasonic sensor to the ESP32.

Ultrasonic Sensor      ESP32

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

4. Firebase Integration:
5. Sending Data to Firebase:
7. 


