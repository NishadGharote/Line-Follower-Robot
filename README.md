# Line-Follower-Robot

This project is a simple line-following robot controlled by an ESP32 microcontroller. The robot uses two sensors to detect a line and adjusts its motors to follow the line accordingly.

## Hardware Requirements

- ESP32 Development Board
- Motor Driver (e.g., L298N)
- Two DC Motors
- Two Line Sensors (e.g., IR Sensors)
- Power Supply for the motors
- Breadboard and jumper wires

## Pin Configuration

| Component       | Pin Number |
|-----------------|------------|
| Left Motor 1    | GPIO 17    |
| Left Motor 2    | GPIO 5     |
| Right Motor 1   | GPIO 4     |
| Right Motor 2   | GPIO 16    |
| Left Sensor     | GPIO 19    |
| Right Sensor    | GPIO 18    |

## Circuit Diagram

Ensure that the motor driver and sensors are connected as per the pin configuration above. Power the motors using an appropriate power supply.

## Code

The code for controlling the line-following robot is provided below. The robot moves forward, turns left, or turns right based on the sensor inputs.

```cpp
#define ML1 17
#define ML2 5
#define MR1 4
#define MR2 16
#define L_Sens 19
#define R_Sens 18

void setup() {  
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT); 
  pinMode(L_Sens, INPUT);
  pinMode(R_Sens, INPUT);
  Serial.begin(115200);
}

void loop() {
  uint8_t L_Data = (digitalRead(L_Sens));
  uint8_t R_Data = (digitalRead(R_Sens));
  Serial.print("This is sensor value: ");
  Serial.print(L_Data);
  Serial.print("");
  Serial.print(R_Data);

  if (L_Data == 0 && R_Data == 0) {
    digitalWrite(ML1, HIGH);
    digitalWrite(ML2, LOW);
    digitalWrite(MR1, HIGH);
    digitalWrite(MR2, LOW);
    Serial.println("forward");
  } 
  else if (L_Data == 1 && R_Data == 0) {
    digitalWrite(ML1, LOW);
    digitalWrite(ML2, LOW);
    digitalWrite(MR1, HIGH);
    digitalWrite(MR2, LOW);
    Serial.println("LEFT");
  } 
  else if (L_Data == 0 && R_Data == 1) {
    digitalWrite(ML1, HIGH);
    digitalWrite(ML2, LOW);
    digitalWrite(MR1, LOW);
    digitalWrite(MR2, LOW);
    Serial.println("RIGHT");
  }
}
