WiFiClient espClient;
PubSubClient client(espClient);

void publishStatus(bool isOn);

WebServer server(80);  

void setup_wifi() {
  delay(10);
  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
  }
  Serial.println("\nWiFi đã kết nối, IP: " + WiFi.localIP().toString());

  
}

void main_basic_Setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  // Đèn tắt ban đầu
  
  // Thiết lập OTA
  ArduinoOTA.begin();
  Serial.println("ESP32 sẵn sàng OTA");
}

void main_basic_Loop() {
  ArduinoOTA.handle();

}