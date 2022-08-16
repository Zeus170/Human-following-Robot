# Human-following-Robot
for RoboVITics


This project is expected to follow a human around, provided that there are no barriers or interfences. 
The robot makes use of one ultrasonic sensor fitted on a servo motor to enable 180 degree vision. 
For movement, two tyres are employed that is driven by an L293D motor driver. By making use of the 4 outputs of the motor driver, we are able to perform clockwise and anti clockwise movement on the tyres. And due to the this feature, the robot is also able to move 2 dimensionally in all directions. 

To turn to the sides, either wheels rotate in opposite sense, thereby producing a coupling torque to the system. 

In the code, first the robot makes use of the HC04 sensor mounted on an SG90 microservo to observe the surroundings, upto and angle of 90 degrees on either directions.
During the process, the minimum distance of the object in the sight of the sensor is noted. Along with the distance, the position of the servo is also noted, so that, by making use of the angle the servo is in, the robot is able to align itself to the object. Once the robot is aligned and the object is in the centre of the vision of the sensor, the robot is made to move forward, upto a specified distance that is limited to 40cm. This cycle is repeated and incase the object comes too close the sensor, the robot moves backwards.
