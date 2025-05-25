#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoOTA.h>
#include <WebServer.h>
#include <DFRobotDFPlayerMini.h>
#include <HardwareSerial.h>
#include <WiFiClientSecure.h>
#include <SPI.h>
#include <SD.h>

#include <IRremote.h>

#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
#include <PubSubClient.h>
#include <HTTPClient.h>

#include "constant.h"
#include "define.h"
#include "function_basic.h"
#include "function_webservice.h"
#include "function_MQTT.h"
//#include "Logger.h"


#include "device_HC-SR501.h"
//#include "device_DFPlayerMini.h"
#include "device_iremote.h"
#include "device_SD.h"
#include "device_l293d.h"
#include "device_max4466.h"


void setup(){
  Serial.begin(115200);
  main_basic_Setup();
  main_webservice_Setup();
  main_MQTT_Setup();
  main_l293d_setup();
  main_max4466_Setup();
  //main_iremote_Setup();
  //Logger logger("ESP32Client", client);  // logger(deviceId, mqttClient)
  //logger.info("ESP32");
  
}

void loop(){
  if (SerialBT.available()) {
    char c = SerialBT.read();
    Serial.write(c);
  }
  main_basic_Loop();
  main_webservice_Loop();
  main_MQTT_Loop();
  main_l293d_loop();
  main_max4466_Loop();
  //main_iremote_Loop();

}
