//Board Write
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>

String command;             //String to store app command state.

const char* ssid = "myRobot";
ESP8266WebServer server(80);


SoftwareSerial NodeMCU(3, 1); // RX | TX


void setup() {
  Serial.begin(9600);
  NodeMCU.begin(9600);

  // Connecting WiFi
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

 //Show myip is to IP_add the borad on SerialMonitor for Connecting Pass Appications !! 
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  // Starting WEB-server
  server.on ( "/", HTTP_handleRoot );
  server.onNotFound ( HTTP_handleRoot );
  server.begin();
}

void loop() {
  server.handleClient();

//Command requst for http application requst control Robot cars.
  command = server.arg("State");
  if (command == "F") NodeMCU.println(5);
  else if (command == "B") NodeMCU.println(1);
  else if (command == "L") NodeMCU.println(2);
  else if (command == "R") NodeMCU.println(3);
  else if (command == "S") NodeMCU.println(4);
}

//Is means Send State for Http on IP_add is a text/html on web server So the Send Message to data and getdata for control Robot_cars
void HTTP_handleRoot(void) {

  if ( server.hasArg("State") ) {
    Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
