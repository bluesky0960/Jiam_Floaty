#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>  
#include "SSD1306.h" 
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define SCK     5    // GPIO5  -- SX1278's SCK
#define MISO    19   // GPIO19 -- SX1278's MISO
#define MOSI    27   // GPIO27 -- SX1278's MOSI
#define SS      18   // GPIO18 -- SX1278's CS
#define RST     14   // GPIO14 -- SX1278's RESET
#define DI0     26   // GPIO26 -- SX1278's IRQ(Interrupt Request)
#define BAND    915E6
#define LAT     37.612063
#define LNG     126.997629

SSD1306 display(0x3c, 4, 15);
//TinyGPSPlus gps;
//SoftwareSerial ss(34,12);

void setup() {
  pinMode(16,OUTPUT);
  pinMode(2,OUTPUT);
 
  Serial.begin(115200);
  Serial.println();
  Serial.println("LoRa Sender Test");
  
  SPI.begin(SCK,MISO,MOSI,SS);
  LoRa.setPins(SS,RST,DI0);
  
  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  Serial.println("init ok");

  delay(1000);
}

void loop() {
  LoRa.beginPacket();
  LoRa.println(1);
  LoRa.endPacket();
  
}
