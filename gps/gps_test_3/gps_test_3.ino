#include <TinyGPS++.h>
#include <SoftwareSerial.h>

//static const int RXPin = 35, TXPin = 34;
//static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(35,34);

void setup(){
  Serial.begin(115200);
  Serial.println("Start GPS... ");
  ss.begin(9600);
}

void loop(){
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){
    //Serial.print("GPS good");
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
    }
  }
}
