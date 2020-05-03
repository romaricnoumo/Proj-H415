#include <ESP8266WiFi.h>

WiFiServer server(80);    // Create a webserver object that listens for HTTP request on port 80

const char* ssid = "WiFi-2.4-C9FC" ;
const char* password = "4Zay6G26gHpM";
int LED = 4;

void setup() {
  Serial.begin(115200);

  // prepare GPIO2
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");


  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {

 WiFiClient client = server.available();
if (client)
{
handle_request(client);
}
 
}

// handle HTTP request 
void handle_request(WiFiClient client) {
Serial.println("\n[Client connected]");

while (client.connected()){
// read line by line what the client (web browser) is requesting
if (client.available())
{
//String line = client.readStringUntil('\r');
//Serial.println(line);
//Toogle pin
digitalWrite(LED, !digitalRead(LED));
break;
}
}
client.stop();
delay(500);
Serial.println("[Client disonnected]");
}
