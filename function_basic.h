//WiFiClient espClient;
//PubSubClient client(espClient);
WiFiClientSecure espClient;
PubSubClient client(espClient);

const int RECV_PIN = 15;
IRrecv irrecv(RECV_PIN);
decode_results results;

void publishStatus(bool isOn);
void main_DFPlayerMini_Setup(PubSubClient& mqttClient);
void main_SD_Setup(PubSubClient& mqttClient);
File audioFile;

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

String getDeviceId() {
  uint64_t chipid = ESP.getEfuseMac();
  char id[13];
  sprintf(id, "%04X%08X", (uint16_t)(chipid>>32), (uint32_t)chipid);
  return String("esp32_") + id;
}

void main_basic_Setup() {
  setup_wifi();
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  // Đèn tắt ban đầu
  
  // Thiết lập OTA
  ArduinoOTA.begin();
  Serial.println("ESP32 sẵn sàng OTA");
}

void main_basic_Loop() {
  ArduinoOTA.handle();

}