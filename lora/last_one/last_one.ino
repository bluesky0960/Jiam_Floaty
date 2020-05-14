#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <SimpleTimer.h>

#define FIREBASE_HOST "floaty-1567658963009.firebaseio.com" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH ""
#define WIFI_SSID "AndroidHotspot0960"
#define WIFI_PASSWORD ""


#define SCK     5    // GPIO5  -- SX1278's SCK
#define MISO    19   // GPIO19 -- SX1278's MISO
#define MOSI    27   // GPIO27 -- SX1278's MOSI
#define SS      18   // GPIO18 -- SX1278's CS
#define RST     14   // GPIO14 -- SX1278's RESET
#define DI0     26   // GPIO26 -- SX1278's IRQ(Interrupt Request)
#define BAND    915E6


#define LAT     37.612063
#define LNG     126.997629
FirebaseData firebaseData;
FirebaseJson json;
SimpleTimer timer;

void fire(double a, double b){
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

  if(Firebase.setDouble(firebaseData,"/Current/Latitude", a)){
    //printf("%.9lf\n", firebaseData.doubleData());
  }
  else{
    Serial.println("Error: " + firebaseData.errorReason());
  }
  if(Firebase.setDouble(firebaseData,"/Current/Longitude", b)){
    //printf("%.9lf\n", firebaseData.doubleData());
  }
  else{
    Serial.println("Error: " + firebaseData.errorReason());
  }
}


void setup() {
  pinMode(16,OUTPUT);
  digitalWrite(16, LOW);    // set GPIO16 low to reset OLED
  delay(50); 
  digitalWrite(16, HIGH); // while OLED is running, must set GPIO16 in high、
  
  Serial.begin(115200);
  Serial.println();
  Serial.println("LoRa Receiver Callback");
  
  SPI.begin(SCK,MISO,MOSI,SS);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.println("init ok");
  delay(1500);
  fire(LAT,LNG);
  timer.setTimeout(
}

void loop() {

}
