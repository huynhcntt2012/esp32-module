HardwareSerial mySerial(1);  // UART1
DFRobotDFPlayerMini myDFPlayer;

void main_DFPlayerMini_Setup() {
  
  //FPSerial.begin(9600, SERIAL_8N1, 16, 17); // Start serial communication for ESP32 with 9600 baud rate, 8 data bits, no parity, and 1 stop bit
  mySerial.begin(9600, SERIAL_8N1, 16, 17); // RX, TX

  if (!myDFPlayer.begin(mySerial)) {
    while (true);
  }


  myDFPlayer.volume(20);  // Âm lượng 0-30
  myDFPlayer.play(1);     // Phát file 0001.mp3
}

void main_DFPlayerMini_Loop() {
  
}