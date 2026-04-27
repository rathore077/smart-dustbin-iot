Smart Dustbin (IoT Based)

Project Overview-
This project is an IoT-based Smart Dustbin that can automatically open its lid, detect garbage level, and move using remote control. It uses Arduino for automation and ESP32 for IoT-based monitoring and control.


Features-
- Automatic lid opening
- Garbage level detection
- Live status on mobile
- Remote movement control
- IoT-based smart monitoring


Working-
1. Lid Opening System-
Ultrasonic sensor detects hand/object → Arduino activates servo motor → Lid opens automatically

2. Garbage Level Detection (IoT)-
Ultrasonic sensor (inside lid) measures garbage level → ESP32 sends data to Blynk app → Shows Full / Empty status

3. Movement System-
Dustbin is placed on a robotic cart → Controlled using mobile app
Controls:
- Forward
- Backward
- Left
- Right


Components Used-
Lid System-
- Arduino Board
- Ultrasonic Sensor
- Servo Motor

IoT Monitoring-
- ESP32
- Ultrasonic Sensor
- Blynk App

Movement System-
- L298N Motor Driver
- DC Motors (2)
- IR Sensor
- Switch
- Robotic Chassis


Mobile App-
Blynk used for:
- Monitoring dustbin status
- Controlling movement


Project Images-
Smart Dustbin Setup-
- Complete view of the smart dustbin system including Arduino, ESP32, sensors, and robotic cart.
"Setup" (images/setup.jpg)

Wiring Connection-
- Close-up view of all hardware connections showing proper wiring between components.
"Wiring" (images/wiring.jpg)

Working Model-
- Demonstration of the dustbin in action (lid opening or movement).
"Working" (images/working.jpg)


Blynk App Screenshots-
- Control Dashboard-
Mobile interface used to control movement (Forward, Backward, Left, Right).
"Dashboard" (images/blynk_dashboard.jpg)

- Dustbin Status (Full/Empty)-
Shows real-time garbage level status sent by ESP32.
"Status" (images/blynk_status.jpg)


Circuit Diagram-
- Below is the circuit diagram representing connections between Arduino, ESP32, sensors, and motor driver.
"Circuit Diagram" (circuit_diagram/circuit.png)


Code-
- Arduino code for lid opening system
- ESP32 code for IoT monitoring and movement control
  (Available in "/code" folder)


Future Scope-
- Smart city integration
- Automatic garbage collection system
- GPS tracking
- AI-based waste detection


Author-
Rahul Singh Rathore


Conclusion-
This project demonstrates how IoT and automation can improve waste management systems by making them smarter, efficient, and user-friendly.
