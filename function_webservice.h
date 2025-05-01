void handleRoot() {
  String html = "<html><head><title>ESP32 LED</title></head><body>";
  html += "<h2>LED ESP32</h2>";
  html += "<p><a href=\"/on\"><button>Turn On</button></a></p>";
  html += "<p><a href=\"/off\"><button>Turn Off</button></a></p>";
  html += "<div><span>humidity:</span>" + String(humidity) + "</div>";
  html += "<div><span>temperature:</span>" + String(temperature) + "</div>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleOn() {
  digitalWrite(LED_PIN, HIGH);  // HIGH là bật LED (nếu LED dạng active-high)
  server.sendHeader("Location", "/", true);
  server.send(302, "text/plain", "");
}

void handleOff() {
  digitalWrite(LED_PIN, LOW);  // LOW là tắt LED
  server.sendHeader("Location", "/", true);
  server.send(302, "text/plain", "");
}

void main_webservice_Setup() {
  // Thiết lập các route
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
  Serial.println("Web server đã khởi động!");
}

void main_webservice_Loop() {
  server.handleClient();
}