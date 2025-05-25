void publishStatus(bool isOn) {
  String msg = isOn ? "on" : "off";
  client.publish(topic_pub, msg.c_str(), true); // QoS 0, retain true
  
}
void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  if (message == "on") {
    digitalWrite(LED_PIN, HIGH);
    publishStatus(true);
  } else if (message == "off") {
    digitalWrite(LED_PIN, LOW);
    publishStatus(false);
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Kết nối MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("thành công");
      client.subscribe(topic_sub);
      client.subscribe(topic_dfplayer);
      client.subscribe(topic_motor);
      client.subscribe(topic_max4466);
      
      //main_DFPlayerMini_Setup(client);
      //main_SD_Setup(client);
    } else {
      Serial.print("Thất bại, mã lỗi: ");
      Serial.println(client.state());
      
      
    }
  }
}

void publishPirStatus(bool detected) {
  String msg = detected ? "motion" : "no_motion";
  client.publish(topic_pub_pir, msg.c_str(), true);  // retain
  Serial.println("Cảm biến PIR: " + msg);
}

void main_MQTT_Setup() {
  espClient.setCACert(root_ca);
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void main_MQTT_Loop() {
  if (!client.connected()) reconnect();
  client.loop();
}

