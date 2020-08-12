#include <MQ2.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

 // Values read from sensor
int lpg,co,smoke;
int pin = A0;
float udara;  
float ppm;
String webString=""; // String to display
MQ2 mq2(pin);

unsigned long previousMillis = 0;        // will store last temp was read
const long interval = 2000;              // interval at which to read sensor

const char* ssid     = "Redmi 3S";
const char* password = "perumahan";

ESP8266WebServer server(80);
 
void handle_root() {
  server.send(200, "text/plain", "sistem monitoring gas");
  delay(100);
}
void gasSensor() {
    
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis >= interval) {
       previousMillis = currentMillis;  
       
       //val = analogRead(A0); 
MQ2 gasSensor = MQ2(A0);
 //float rzero = gasSensor.getRZero();
//Serial.println (rzero);
float* udara = mq2.read(true);
//ppm = udara;
  }
}
 
void setup(void)

{

  
  // You can open the Arduino IDE Serial Monitor window to see what the code is doing
  Serial.begin(115200);  // Serial connection from ESP-01 via 3.3v console cable
           // initialize temperature sensor
  mq2.begin();
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  Serial.print("\n\r \n\rWorking to connect");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("MQ2 membaca server");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
   
  server.on("/", handle_root);
  
  server.on("/mq2", [](){  // if you add this subdirectory to your webserver call, you get text below :)
    gasSensor();       // read sensor
    webString="Temperature: "+String((int)udara)+" ";   // Arduino has a hard time with float to string
    server.send(200, "text/plain", webString);            // send to someones browser when asked
  });

  server.begin();
  Serial.println("HTTP server started");
}
 
void loop(void)
{
     
  //lpg = values[0];
  lpg = mq2.readLPG();
  //co = values[1];
  co = mq2.readCO();
  //smoke = values[2];
  smoke = mq2.readSmoke();
  Serial.println(udara);
  delay(1000);
  server.handleClient();
} 
