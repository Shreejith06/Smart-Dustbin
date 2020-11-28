/*
 * Ultrasonic Simple
 * Prints the distance read by an ultrasonic sensor in
 * centimeters. They are supported to four pins ultrasound
 * sensors (liek HC-SC04) and three pins (like PING)))
 * and Seeed Studio sensors).
 *
 * The circuit:
 * * Module HR-SC04 (four pins) or PING))) (and other with
 *   three pins), attached to digital pins as follows:
 * ---------------------    --------------------
 * | HC-SC04 | Arduino |    | 3 pins | Arduino |
 * ---------------------    --------------------
 * |   Vcc   |   5V    |    |   Vcc  |   5V    |
 * |   Trig  |   12    | OR |   SIG  |   13    |
 * |   Echo  |   13    |    |   Gnd  |   GND   |
 * |   Gnd   |   GND   |    --------------------
 * ---------------------
 * Note: You do not obligatorily need to use the pins defined above
 * 
 * By default, the distance returned by the read()
 * method is in centimeters. To get the distance in inches,
 * pass INC as a parameter.
 * Example: ultrasonic.read(INC)
 * Pass as a parameter the trigger and echo pin, respectively,
 * or only the signal pin (for sensors 3 pins), like:
 * Ultrasonic ultrasonic(13);
 */
#include <Ultrasonic.h>

#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int distance1, distance2 = 100;
int count = 0;
int led = 8;
Ultrasonic ultrasonic1(12, 13);
Ultrasonic ultrasonic2(10, 11);

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  myservo.attach(9);// attaches the servo on pin 9 to the servo object
  myservo.write(0);//close cap when power on
  delay(100);
  myservo.detach();
  }

void loop() {

  distance1 = ultrasonic1.distanceRead();
  
  
  myservo.attach(9);
  if (distance2 > 10 && distance2 != 357) {
  digitalWrite(led, LOW);
  if (distance1 < 20) {
  myservo.write(150);    
  delay(1000);
  }
  }
  else
  digitalWrite(led, HIGH);
  if (ultrasonic1.distanceRead() > 20)
  myservo.write(0);
  delay(1000);
  myservo.detach();

  distance2 = ultrasonic2.distanceRead();
  if (count == 10) {
  Serial.println(distance2);
  count = 0;
  }
  count ++;
  delay(1000);
}
