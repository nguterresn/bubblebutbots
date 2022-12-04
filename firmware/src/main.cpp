#include <Arduino.h>
#include "WebServer.h"

#ifdef ESP32
#define LED_FLASH 4
#define LED_ON_BOARD 33
#endif

#define SERIAL_ENABLED 1

MachineRoom machineRoom(D1, D2, D3, D4);

void setup() {
  #ifdef ESP32
  pinMode(LED_ON_BOARD, OUTPUT);
  #endif

  #ifdef SERIAL_ENABLED
  Serial.begin(9600);
  Serial.print("Just initialized...");
  machineRoom.installLogger(&Serial);
  #endif

  setWifi();
  setWebServer(machineRoom);
}

void loop() {
  #if ESP8266
  MDNS.update();
  #endif
}
