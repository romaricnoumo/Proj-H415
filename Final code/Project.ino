

#include <ESP8266WiFi.h>
#include<Servo.h>


Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

ADC_MODE(ADC_VCC);
WiFiServer ESPserver(80);   // Create a webserver object that listens for HTTP request on port 80

const char* ssid = "WiFi-2.4-C9FC" ;
const char* password = "4Zay6G26gHpM";
int ledPin = 4; // GPIO2 of ESP8266
String message="";
String message2="";
String batterystate="";
float state=0;
int state2=0;
// Variable to store the HTTP request
String header;


void setup() 
{
 myservo.attach(5);  // attaches the servo on pin 9 to the servo object
Serial.begin(115200);
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, HIGH);

Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);

WiFi.begin(ssid, password);

delay(5000);

while (WiFi.status() != WL_CONNECTED) 
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());

// Start the server
ESPserver.begin();
Serial.println("Server started");

// Print the IP address
Serial.print("Enter this URL to control ESP8266: ");
Serial.print("http://liftproject.ddns.net");

//Connect to internet to get Public IP
WiFiClient client1;
client1.connect("api.ipify.org", 80);
client1.stop();

}


void loop() 
{


WiFiClient client = ESPserver.available();
 
if (client) { // If a new client connects,
Serial.println("New Client."); // print a message out in the serial port
String currentLine = ""; // make a String to hold incoming data
while (client.connected()) { // loop while the client's connected
if (client.available()) { // if there's bytes to read
char c = client.read(); // read a byte, then
Serial.write(c); // print it out the serial monitor
header += c;
if (c == '\n') {
   if (currentLine.length() == 0) {
    BattState();
    UpdateMess();
    Response(client,header);     
    break;
  } else { // if you got a newline, then clear currentLine
    currentLine = "";
     }
  
} else if (c != '\r') { // if you got anything else but a carriage return character,
currentLine += c; // add it to the end of the currentLine
}
} 
   }
// Clear the header variable
header = "";
// Close the connection
client.stop();
Serial.println("Client disconnected.");
Serial.println(""); 
myFunction();

  }  
 
}


void myFunction(){

  message="The Lift has  just been called!";
  
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees:foward rotation
  // in steps of 1 degree
  myservo.write(pos);              // tell servo to go to position in variable 'pos'
  delay(20);                     // waits for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees: reverse rotation
  myservo.write(pos);              // tell servo to go to position in variable 'pos'
  delay(20);                       // waits  for the servo to reach the position
  }
  message="";
}
  
void BattState(){

batterystate=ESP.getVcc();
state2=batterystate.toInt();
//compute the battery voltage in percent
//3OOmv for compensation due to onboard voltage divider on ESP8266
state= ( (float)state2 + 300.0) ;
state2=round(state);
batterystate=String(state2);
}

//Display message when Battery Low

void UpdateMess(){
 if(state2<=1800){

 message2=" Low ! Please recharge.";
 
 }
 else

 message2=" OK.";
}


//Response to send to browser
void Response(WiFiClient client,String header ){

 
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connection: close");
client.println(""); //  IMPORTANT

 if (header.indexOf("GET /CALL") >= 0) {
     message="The Lift has been called!";
     digitalWrite(ledPin, !digitalRead(ledPin));         
 }

               
//Display webpage

client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<head>");
client.println("<link rel=\"icon\" href=\"data:,\">");
client.println("<title>Lift Caller</title>");
client.println("</head>");
client.println("<body>");
client.println("<h1 style=""text-align:center"">Welcome !! </h1>");
client.println("<h2>  Battery State: " +message2+"</h2>");
client.println("<p>Please Click on the link below to call the Lift.</p>");
client.println("Click <a href=\"/CALL\">here</a>");
client.println("<p>"+message+"</p>");
client.println("</body>");
client.println("</html>");
client.println();
}
