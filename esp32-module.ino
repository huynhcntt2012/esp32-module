#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoOTA.h>
#include <WebServer.h>
#include <DFRobotDFPlayerMini.h>
#include <HardwareSerial.h>

#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
#include <PubSubClient.h>
#include <HTTPClient.h>

#include "constant.h"
#include "define.h"
#include "function_basic.h"
#include "function_webservice.h"
#include "function_MQTT.h"

#include "device_HC-SR501.h"
#include "device_DFPlayerMini.h"




void setup(){
  Serial.begin(115200);
  main_basic_Setup();
  main_webservice_Setup();
  main_MQTT_Setup();
  main_DFPlayerMini_Setup();
  
}

void loop(){
  if (SerialBT.available()) {
    char c = SerialBT.read();
    Serial.write(c);
  }
  main_basic_Loop();
  main_webservice_Loop();
  main_MQTT_Loop();
  main_DFPlayerMini_Loop();

}
