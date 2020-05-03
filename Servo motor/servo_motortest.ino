// Loading servo library
#include<servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

//To read the input voltage of ESP
//ADC_MODE(ADC_VCC);
//int battery;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

}

void loop() {
       
           for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees:foward rotation
             // in steps of 1 degree
               myservo.write(pos);              // tell servo to go to position in variable 'pos'
               delay(15);                       // waits 15ms for the servo to reach the position
            }
        
           for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees: reverse rotation
                myservo.write(pos);              // tell servo to go to position in variable 'pos'
                delay(15);                       // waits 15ms for the servo to reach the position
           }

//To check for the life of the battery
      //if(battery<3000){
           //   client.println("Battery low! Please charge your battery.")
           // }
            //else{
            //client.println("Battery is fine")
            //}
            //}

}
