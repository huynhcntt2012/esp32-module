void main_iremote_Setup() {
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
}

void main_iremote_Loop() {
  if (IrReceiver.decode()) {
    unsigned long irValue = IrReceiver.decodedIRData.decodedRawData;
    Serial.print("IR: 0x");
    Serial.println(irValue, HEX);

    char payload[20];
    sprintf(payload, "0x%lX", irValue);
    client.publish(topic_iremote, payload);

    IrReceiver.resume();
  }
}