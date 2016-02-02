# Voice Controlled Robot 2013

The purpose of this robot was to make a robot that can drive in any direction given a command from the user.

##Video Preview
[![Youtube](https://raw.githubusercontent.com/tron1991/robot-ardunio-c-/master/robot4.png)](https://youtu.be/GLzOHIPCU1w)

## Features

Basically, the robot will have its own chassis made from Plexiglas, standoffs, and motors. The structure will have two levels. The first level is for the assembly of the motors connected to the bearing block which is connected to the Plexiglas for stability. The wheel will then be attached to the motor and will rotate smoothly. On the lower floor
there will also be the castor wheel to cause balance for the robot. It will act as a way to prevent friction from hurting the performance of where the robots goes. The EasyVR is located on the second floor beside the H-bridge and the Arduino. The battery packs will also be located in the rear of the lower level.Now for the second level, the microcontroller, and breadboard will be the main pieces. The 9V battery will power the microcontroller.

The function of the robot is as follows, first it turn on and calibrate the environment in which it is in. Then, the user will say a trigger word to tell the robot to get ready for the 5 list of commands. The trigger word is “Nick” and the commands to say after are “Straight”, “Backward”, “Left”, “Right”, and “Stop”. As you will see in the demo, the robot flashes an LED to confirm the call has been registered. To see a working demo of the voice recognition robot, click here http://www.youtube.com/watch?v=GLzOHIPCU1w .

##Pictures

![Robot](https://raw.githubusercontent.com/tron1991/robot-ardunio-c-/master/robot1.jpg)

![Robot](https://raw.githubusercontent.com/tron1991/robot-ardunio-c-/master/robot2.jpg)

![Robot](https://raw.githubusercontent.com/tron1991/robot-ardunio-c-/master/robot3.jpg)

##Main Voice Commands

```ruby
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
```

##Hardware based

**Voice Controlled Robot** is implemented in **C++** using Arduino IDE environment.

##Dependencies

None.

## Creator

Nicholas Ivanecky ([@ivantr0n](http://twitter.com/ivantr0n)), To visit all my works visit ([www.ivantron.com](http://www.ivantron.com))



