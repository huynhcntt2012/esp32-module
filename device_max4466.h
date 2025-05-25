
void main_max4466_Setup() {
  analogReadResolution(12); // Độ phân giải ADC là 12-bit (0~4095)
}

void main_max4466_Loop() {
  int micValue  = analogRead(MIC_PIN);  // Đọc tín hiệu từ microphone
  String message = String(micValue);
  client.publish(topic_max4466, message.c_str());
}