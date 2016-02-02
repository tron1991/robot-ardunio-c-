#if defined(ARDUINO) && ARDUINO >= 100 #include "Arduino.h"
#include "SoftwareSerial.h" SoftwareSerial port(12,13);
#else // Arduino 0022 - use modified NewSoftSerial #include "WProgram.h"
#include "NewSoftSerial.h"
NewSoftSerial port(12,13);
#endif
#include "EasyVR.h" EasyVR easyvr(port);
//Groups and Commands enum Groups
{
GROUP_0 = 0,
GROUP_1 = 1, };
enum Group0 {
G0_NICK = 0, };
enum Group1 {
G1_STRAIGHT = 0, G1_BACKWARD = 1, G1_RIGHT = 2, G1_LEFT = 3, G1_STOP = 4,
};
EasyVRBridge bridge;
int8_t group, idx; int motorpin1a = 6;
int motorpin1b = 7; int motoren1 = 5;
int motorpin2a = 8; int motorpin2b = 9; int motoren2 = 10;
void setup() {
//motor 1 (Input1) //motor 1 (Input2)
//motor 1 enable(PWM)
//motor2 (Input3) //motor2 (input4) //motor 2 enable(PWM)
5
// bridge mode? if (bridge.check()) {
cli();
bridge.loop(0, 1, 12, 13); }
// run normally Serial.begin(9600); port.begin(9600);
if (!easyvr.detect()) {
Serial.println("EasyVR not detected!");
for (;;); }
easyvr.setPinOutput(EasyVR::IO1, LOW); Serial.println("EasyVR detected!"); easyvr.setTimeout(5); easyvr.setLanguage(0);
group = EasyVR::TRIGGER; //<-- start group (customize)
pinMode(motorpin1a, OUTPUT); pinMode(motorpin1b, OUTPUT); pinMode(motoren1, OUTPUT); pinMode(motorpin2a, OUTPUT); pinMode(motorpin2b, OUTPUT); pinMode(motoren2, OUTPUT);
}
void action();
void loop() {
easyvr.setPinOutput(EasyVR::IO1, HIGH); // LED on
Serial.print("Say a command in Group "); Serial.println(group); easyvr.recognizeCommand(group);
do {
// some processing }
while (!easyvr.hasFinished()); easyvr.setPinOutput(EasyVR::IO1, LOW); // LED off
idx = easyvr.getWord(); if (idx >= 0)
{
6
// built-in trigger (ROBOT)
// group = GROUP_X; <-- jump to another group X return;
}
idx = easyvr.getCommand(); if (idx >= 0)
{
// print debug message uint8_t train = 0;
char name[32]; Serial.print("Command: "); Serial.print(idx);
if (easyvr.dumpCommand(group, idx, name, train)) {
Serial.print(" = ");
Serial.println(name); }
else Serial.println();
easyvr.playSound(0, EasyVR::VOL_FULL); // perform some action
action();
}
else // errors or timeout {
if (easyvr.isTimeout()) Serial.println("Timed out, try again...");
int16_t err = easyvr.getError(); if (err >= 0)
{
Serial.print("Error ");
Serial.println(err, HEX); }
group=GROUP_0; }
}
void action() {
switch (group) {
case GROUP_0:
switch (idx)
{
case G0_NICK:
group = GROUP_1;//
break; }
break;
case GROUP_1:
switch (idx)
7
{
case G1_STRAIGHT:
group = GROUP_0; stateChangeFORWARD(); //stateChangeRIGHT(); delay(1000); stateChangeSTOP();
break;
case G1_BACKWARD:
group = GROUP_0; stateChangeBACKWARD(); delay(1000); stateChangeSTOP(); break;
case G1_RIGHT:
group = GROUP_0; stateChangeRIGHT(); delay(1000); stateChangeSTOP();
break;
case G1_LEFT:
group = GROUP_0; stateChangeLEFT(); delay(1000); stateChangeSTOP();
break;
case G1_STOP:
group = GROUP_0; stateChangeSTOP(); delay(1000); stateChangeSTOP(); break;
}
break; }
}
void stateChangeRIGHT() {
//turning right with the robot digitalWrite(motorpin1a, HIGH); digitalWrite(motorpin1b, LOW); digitalWrite(motorpin2a, HIGH); digitalWrite(motorpin2b, LOW); analogWrite(motoren1, 650); analogWrite(motoren2, 650);
void stateChangeLEFT() {
//motor1 speed
//motor2 speed //will change depending on the angle of rotation
}
//turning left with the robot
8
digitalWrite(motorpin1a, LOW); digitalWrite(motorpin1b, HIGH); digitalWrite(motorpin2a, LOW); digitalWrite(motorpin2b, HIGH); //delay(1000); analogWrite(motoren1, 650); analogWrite(motoren2, 650);
void stateChangeFORWARD() {
//moving forward with the robot digitalWrite(motorpin1a, LOW); digitalWrite(motorpin1b, HIGH); digitalWrite(motorpin2a, HIGH); digitalWrite(motorpin2b, LOW); analogWrite(motoren1, 650); analogWrite(motoren2, 650);
void stateChangeBACKWARD() {
digitalWrite(motorpin1a, HIGH); digitalWrite(motorpin1b, LOW); digitalWrite(motorpin2a, LOW); digitalWrite(motorpin2b, HIGH); analogWrite(motoren1, 650); analogWrite(motoren2, 650);
}
void stateChangeSTOP() {
//stopping the robot
digitalWrite(motorpin1a, LOW); digitalWrite(motorpin1b, LOW); digitalWrite(motorpin2a, HIGH); digitalWrite(motorpin2b, HIGH);
//motor1 speed
//motor2 speed // will change depending on the angle of rotation
}
//motor2 speed //will change depending on the angle of rotation
}
}