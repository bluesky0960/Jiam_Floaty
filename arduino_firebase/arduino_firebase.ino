#include <WiFi.h>
#include <FirebaseESP32.h>
#include <TinyGPS++.h>


#define FIREBASE_HOST "floaty-1567658963009.firebaseio.com" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "bOPEFOlLDWKlTBLLybQ3WKrfM3fZTZamvoddaZQu"
#define WIFI_SSID "AndroidHotspot0960"
#define WIFI_PASSWORD "98765432"


//Define FirebaseESP32 data object
FirebaseData firebaseData;
FirebaseJson json;
TinyGPSPlus gps;
HardwareSerial MySerial(1);

String path = "/Sender1";
int count = 0;

void setup()
{

  Serial.begin(115200);
  MySerial.begin(9600, SERIAL_8N1, 12, 15); //12-tx, 15-rx
  
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

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

  if(Firebase.setDouble(firebaseData, path + "/Current/Latitude", gps.location.lat())){
    printf("%.9lf\n", firebaseData.doubleData());
  }
  else{
    Serial.println("Error: " + firebaseData.errorReason());
  }
  if(Firebase.setDouble(firebaseData, path + "/Current/Longitude", gps.location.lng())){
    printf("%.9lf\n", firebaseData.doubleData());
  }
  else{
    Serial.println("Error: " + firebaseData.errorReason());
  }
  //if(Firebase.setString(firebaseData, path + "/Time", gps.time.hour() + ":" + gps.time.minute() + ":" + gps.time.second())){
  //  Serial.println("Value : " + firebaseData.stringData());
  //}
  //else{
  //  Serial.println("Error: " + firebaseData.errorReason());
  //}
}

void loop()
{
  if(gps.location.isUpdated()){

    if(Firebase.pushDouble(firebaseData, path + "/Path/Latitude", gps.location.lat())){
      Serial.println("pushed lat");
    }
    else{
      Serial.println("Error: " + firebaseData.errorReason());
    }
    if(Firebase.pushDouble(firebaseData, path + "/Path/Longitude", gps.location.lng())){
      Serial.println("pushed lng");
    }
    else{
      Serial.println("Error: " + firebaseData.errorReason());
    }
    if(Firebase.setDouble(firebaseData, path + "/Current/Latitude", gps.location.lat())){
    printf("%.9lf\n", firebaseData.doubleData());
    }
    else{
      Serial.println("Error: " + firebaseData.errorReason());
    }
    if(Firebase.setDouble(firebaseData, path + "/Current/Longitude", gps.location.lng())){
      printf("%.9lf\n", firebaseData.doubleData());
    }
    else{
      Serial.println("Error: " + firebaseData.errorReason());
    }
  }
  else{
    if(Firebase.setDouble(firebaseData, path + "/Current/Latitude", 37.612233)){
      printf("%.9lf\n", firebaseData.doubleData());
    }
    else{
      Serial.println("Error: " + firebaseData.errorReason());
    }
    if(Firebase.setDouble(firebaseData, path + "/Current/Longitude", 126.996844)){
      printf("%.9lf\n", firebaseData.doubleData());
    }
    else{
      Serial.println("Error: " + firebaseData.errorReason());
    }
  }
  /*Serial.println("------------------------------------");
  Serial.println("Set gps test...");
  Serial.write(MySerial.read());
  Serial.print("Latitude: ");
  Serial.println(gps.location.lat(),5);
  Firebase.setDouble(firebaseData, path + count, gps.location.lat());
  Serial.println("------------------------------------");*/
}
