# Proj-H415
The Project consist in implemeting an automatic lift controller that can be accessed through a web page. The user should be able access the webpage associated to the lift and to call the lift from where he is.To achieve this,We use a WIFI connected Micontroller that can establish TCP/IP connections with a server.The ESP8266 is connected to a servo motor.When the motor is activated by the ESP8266,an actuator pushes the call button of the lift and after a certain amount of time it moves back to its original position.  Also, the user should be able to view on the webpage the state of the batterry which enables him to know when to charge the battery in order to avoid discharge.

# Webpage


# Servo Motor
The idea is to be able to control the servo motor. First, a servo object was created to control this. Then a position is initialized to store the motor position. Pin 9 of the microcontroller is attached to the servo object to get the the motor position. In the main loop, two for loops are written. The first one for the foward rotation(0° to 180°-clockwise direction) and the other loop(180° to 0°- Anti-clockwise direction).

# ESP8266MOD


# To do
1. To link all these individual pieces of code.
2. To make sure the web page is no longer local.
3. To assemble all the hardware and test for responsiveness.
 
