#include <SPI.h>
#include <LoRa.h>

#define SX1278_SCK  5
#define SX1278_MISO 19
#define SX1278_MOSI 27
#define SX1278_CS   18
#define SX1278_RST  14
#define SX1278_IRQ  26

void setup() {
  Serial.begin(115200);
  while (!Serial);

  // Start LoRa
  SPI.begin(SX1278_SCK, SX1278_MISO, SX1278_MOSI, SX1278_CS);
  LoRa.setPins(SX1278_CS, SX1278_RST, SX1278_IRQ);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
