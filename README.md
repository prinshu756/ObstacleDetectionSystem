 Obstacle Detection System using Arduino Uno

Overview
This project implements a simple **Obstacle Detection System** using an **Arduino Uno**, a **servo motor**, an **ultrasonic sensor**, LEDs, and a buzzer. The system scans the surrounding area for obstacles and provides visual and audible alerts when an obstacle is detected. It is ideal for beginner robotics projects, obstacle-avoiding robots, and safety applications.

Features
- Rotating ultrasonic sensor to scan a wide area using a servo motor.
- Distance measurement displayed on a **16x2 LCD**.
- **Buzzer alert** when an obstacle is detected within a defined threshold.
- **LED indicators** for different distance ranges:
  - LED1: Obstacle very close
  - LED2: Obstacle at a moderate distance
- Adjustable distance threshold for obstacle detection.

Components Required
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- 16x2 LCD Display
- 2 LEDs
- Buzzer
- Jumper wires
- Breadboard
- Power source for Arduino

---

Circuit Diagram
![Circuit Diagram](CircuitDiagram.png)  
> The ultrasonic sensor is mounted on a servo motor to rotate and scan obstacles. LEDs and a buzzer indicate the obstacle proximity. The LCD displays real-time distance and servo angle.


How It Works
1. The servo motor rotates the ultrasonic sensor from 0° to 180° and back.
2. The ultrasonic sensor measures the distance to nearby obstacles.
3. If the distance is below a defined threshold (e.g., 319 cm):
    The buzzer sounds.
    LEDs light up to indicate proximity.
4. The LCD screen displays the current distance and the servo angle in real-time.


Arduino Connections
| Component          | Arduino Pin |
|-------------------|-------------|
| Servo Motor        | 11          |
| Ultrasonic Trig    | 9           |
| Ultrasonic Echo    | 10          |
| LCD RS             | 7           |
| LCD EN             | 6           |
| LCD D4             | 5           |
| LCD D5             | 4           |
| LCD D6             | 3           |
| LCD D7             | 2           |
| LED1               | 14 (A0)
 LCD D4             | 5           |
| LCD D5             | 4           |
| LCD D6             | 3           |
| LCD D7             | 2           |
| LED1               | 14 (A0)     |
| LED2               | 15 (A1)     |
| Buzzer             | 12          |

Usage
1. Connect all components according to the circuit diagram.
2. Upload the Arduino code to your Arduino Uno.
3. Power on the system.
4. The servo motor will sweep the sensor, and the LCD will display distance and angle.
5. The buzzer and LEDs will indicate when an obstacle is detected within the threshold distance.
