# Proj-H415
The project consist in implemeting an automatic lift controller that can be accessed through a web page. The user should be able access the webpage associated to the lift and to call the lift from where he is. To achieve this,We use a WIFI connected micontroller that can establish TCP/IP connections acts as a server which host the web page. The ESP8266 is also connected to a servo motor. When the motor is activated by the ESP8266,an actuator pushes the call button of the lift and after a certain amount of time predefined by us it moves back to its original position.  Also, the user should be able to view on the webpage the state of the batterry which enables him to know when to charge the battery in order to avoid discharge.

# ESP8266
The microcontroller was used to establish a TCP/IP connection with the user through the user's web browser.The station mode of the ESP8266 is used in this project so as to set it as a webserver to host our web page due to the simplicity of the web page.For more complex web pages,a dedicated web server should be used.This web page can be accessed using the link:http://liftproject2.ddns.net


# Servo Motor
The idea is to be able to control the servo motor. First, a servo object was created to control this. Then a variable position is initialized to store the motor position. Pin 9 of the microcontroller is attached to the servo object to get the the motor position. In the main loop, two for loops are written. The first one for the foward rotation(0° to 180°-clockwise direction) and the other loop(180° to 0°- Anti-clockwise direction).The motor was tested and it rotates as desired. The code is in the folder servo motor. 




 
