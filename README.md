# Proj-H415
The Project consist in implemeting an automatic lift controller that can be accessed through a web page. The user should be able access the webpage associated to the lift and to call the lift from where he is.To achieve this,We use a WIFI connected Micontroller that can establish TCP/IP connections with a server.The ESP8266 is connected to a servo motor.When the motor is activated by the ESP8266,an actuator pushes the call button of the lift and after a certain amount of time it moves back to its original position.  Also, the user should be able to view on the webpage the state of the batterry which enables him to know when to charge the battery in order to avoid discharge.

# Webpage
For Test purposes the webpage is hosted locally.In the final version of the code it  will be publicly accessible.The html code used to create the webpage can be viewed in the folder web page.

# Servo Motor
The idea is to be able to control the servo motor. First, a servo object was created to control this. Then a position is initialized to store the motor position. Pin 9 of the microcontroller is attached to the servo object to get the the motor position. In the main loop, two for loops are written. The first one for the foward rotation(0° to 180°-clockwise direction) and the other loop(180° to 0°- Anti-clockwise direction).

# ESP8266
To communicate with the webpage, the ESP8266 has to be connected to the same network as the computer hosting the webpage.A first test was made to toggle a led connected to the ESP8266 through the webpage.
A second test was conducted to record the sytem voltage.The codes are in the folder ESP8266.

# To do
1. To link all these individual pieces of code.
2. To make sure the web page is no longer local and display the battery percentage.
3. To assemble all the hardware and test for responsiveness.
 
