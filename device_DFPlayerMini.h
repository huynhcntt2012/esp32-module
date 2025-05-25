HardwareSerial mySerial(1);  // UART1
DFRobotDFPlayerMini myDFPlayer;

void main_DFPlayerMini_Setup(PubSubClient& mqttClient) {
  mySerial.begin(9600, SERIAL_8N1, 16, 17); // RX, TX

  if (!myDFPlayer.begin(mySerial)) {
    while (true);
  }

  int fileCount = myDFPlayer.readFileCounts();  // Lấy số lượng file
  String list = "";
  for (int i = 1; i <= fileCount; i++) {
    char buf[10];
    sprintf(buf, "%03d.mp3", i);
    list += buf;
    if (i < fileCount) list += ",";
  }
  mqttClient.publish(topic_dfplayer, list.c_str());
  String message = String(list);
  mqttClient.publish(topic_pub_log, message.c_str());
  //myDFPlayer.volume(20);  // Âm lượng 0-30
  //myDFPlayer.play(1);     // Phát file 0001.mp3
}

void main_DFPlayerMini_Loop() {
  
}