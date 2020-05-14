#include <SoftwareSerial.h>

 

SoftwareSerial gpsSerial(35,34);

//  gps - arduino

//  tx - 6 35 send

//  rx - 5 34 receive

//  vcc - 5v

//  gnd - gnd

void setup() {

  Serial.begin(115200);

  Serial.println("Start GPS... ");

  gpsSerial.begin(9600);

}

 

void loop() {

    if(gpsSerial.available())

    {

      Serial.write(gpsSerial.read());

    }


}
