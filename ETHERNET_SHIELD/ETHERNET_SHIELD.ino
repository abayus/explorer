#include <MQ2.h>
#include <SPI.h> 
#include <Ethernet.h> 
 
 byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; 
 
//ip adress arduino
IPAddress ip(10,33,109,112);
//beda variable dan constanta...
int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int pin = A0;
// Your threshold value
int sensorThres = 10; 
int dataA;
int lpg,co,smoke;
MQ2 mq2(pin);

EthernetClient client; 

void setup() { 
  mq2.begin();
  Serial.begin(9600);
  Ethernet.begin(mac, ip); //
  Serial.print("Arduino server IP address: ");
  Serial.println(Ethernet.localIP());

  pinMode(redLed, OUTPUT); 
  pinMode(greenLed, OUTPUT); 
  pinMode(buzzer, OUTPUT);
  pinMode(pin, INPUT);
}

void loop() {
  float* values= mq2.read(true); //set it false if you don't want to print the values in the Serial
  
  lpg = mq2.readLPG();
  co = mq2.readCO();
  smoke = mq2.readSmoke();

  if(client.connect("10.33.109.111", 80)){ //HOST 
    Serial.print("connected");
    Serial.println();
    client.print("GET http://localhost/koneksi/add_data.php?value="); 
    client.print(lpg);
    client.println();

    client.println("HTTP/1.1");
    client.println("Host: 10.33.109.111"); //HOST
    client.println("Connection: close");
    client.println();
  }
  else{
    Serial.println("connection failed!");
  }
  if (lpg > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
}
  client.stop();
  }

