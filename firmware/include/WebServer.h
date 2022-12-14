#ifndef SERVER_H
#define SERVER_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPmDNS.h>
#elif ESP8266
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESP8266mDNS.h>
#endif

#include "html.h"
#include "MachineRoom.h"

#define SSID_OF_THE_NETWORK "BubbleButBot"
#define DNS_NETWORK_NAME    "bot"

// HTTP QUERY
#define HTTP_QUERY_DEVICE "update"
#define HTTP_MOTOR_X "x"
#define HTTP_MOTOR_Y "y"

// EVENTS TYPES
#define EVENT_SEND_SCANNED_DEVICE "scanned_device"

void notFound(AsyncWebServerRequest *request);
void setWebServer(MachineRoom &machineRoom);
void sendEvent(const char* type, char* value);
void setWifi();

#endif
