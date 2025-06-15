#include <Arduino.h>
#include <Wire.h>
#include <ir/ir_sensor.h>

#define ADDRESS (0x80 >> 1)

#define SHIFT_ADDR 0x35

#define DISTANCE_ADDR 0x5E

#define RIGHT_EDGE_ADDR 0xF8 // C

#define LEFT_EDGE_ADDR 0xF9 // A

#define PEAK_EDGE_ADDR 0xFA // B

uint8_t distance_raw[2] = {0};
uint8_t shift = 0;
uint8_t distance_cm = 0;
char buf[100];

// Variables
float wheelDiameter = 0.065;
float wheelSeparation = 0.15;
float pulsesPerRevolution = 20.0;
float wheelRadius = wheelDiameter / 2.0;

// Pins IR
int IR_FRONT_PIN = 34;
int IR_RIGHT_PIN = 39;
int IR_LEFT_PIN = 36;

// Pins motors
int LEFT_MOTOR_IN1 = 7;
int LEFT_MOTOR_IN2 = 8;
int LEFT_MOTOR_PWM = 9;
int STBY = 10;
int RIGHT_MOTOR_IN1 = 11;
int RIGHT_MOTOR_IN2 = 12;
int RIGHT_MOTOR_PWM = 13;

// Pins encoders
int LEFT_ENCODER_A = 2;
int LEFT_ENCODER_B = 3;
int RIGHT_ENCODER_A = 4;
int RIGHT_ENCODER_B = 5;

IRSensor irFront(IR_FRONT_PIN);

// // Objects
// Motor leftMotor(LEFT_MOTOR_IN1, LEFT_MOTOR_IN2, LEFT_MOTOR_PWM, STBY);
// Motor rightMotor(RIGHT_MOTOR_IN1, RIGHT_MOTOR_IN2, RIGHT_MOTOR_PWM, STBY);

// Encoder leftEncoder(LEFT_ENCODER_A, LEFT_ENCODER_B, pulsesPerRevolution, wheelRadius, 0);
// Encoder rightEncoder(RIGHT_ENCODER_A, RIGHT_ENCODER_B, pulsesPerRevolution, wheelRadius, 0);

// IMU imu;

// DiffDrive diffDrive(&leftMotor, &rightMotor, wheelSeparation, wheelDiameter, 0.5);

// Odom odom(&leftEncoder, &rightEncoder, &imu, wheelSeparation);

void setup()
{
  Wire.begin();
  Serial.begin(115200);
  delay(2000);
  Serial.println("IR Sensor Test");

  Wire.beginTransmission(ADDRESS);
  Wire.write(byte(SHIFT_ADDR));
  Wire.endTransmission();

  Wire.requestFrom(ADDRESS, 1);
  if (1 <= Wire.available())
  {
    shift = Wire.read();
  }

  Serial.print("Read shift bit: ");
  Serial.println(shift, HEX);
}

void loop()
{
  // Read basic measurement
  Wire.beginTransmission(ADDRESS);
  Wire.write(byte(DISTANCE_ADDR));
  Wire.endTransmission();

  Wire.requestFrom(ADDRESS, 2);

  if (2 <= Wire.available())
  {
    distance_raw[0] = Wire.read();
    distance_raw[1] = Wire.read();

    // Print distance in cm
    distance_cm = (distance_raw[0] * 16 + distance_raw[1]) / 16 / (int)pow(2, shift);
    sprintf(buf, "Distance %u cm", distance_cm);
    Serial.println(buf);
  }
  else
  {
    Serial.println("Read error");
  }
  delay(1000);
}
