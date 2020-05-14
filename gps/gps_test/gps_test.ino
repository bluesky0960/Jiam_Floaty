#include <SoftwareSerial.h>

SoftwareSerial gps(35,34); //tx: 12, rx:13

void setup() {
  Serial.begin(115200);
  Serial.println("Strar GPS..");
  gps.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  if(gps.available()){
    Serial.write(gps.read());
  }
  //else{
  //  Serial.println("Fuck");
  //}
  // put your main code here, to run repeatedly:

}
