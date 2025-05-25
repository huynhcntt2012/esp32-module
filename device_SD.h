void writeWavHeader(File file, int sampleRate, int numSamples) {
  int byteRate = sampleRate;
  int dataSize = numSamples;

  file.seek(0);
  file.write("RIFF");
  file.write((byte *)&(dataSize + 36), 4); // ChunkSize
  file.write("WAVE");

  // fmt subchunk
  file.write("fmt ");
  file.write((byte *)"\x10\x00\x00\x00", 4); // Subchunk1Size (16 for PCM)
  file.write((byte *)"\x01\x00", 2);         // AudioFormat (1 for PCM)
  file.write((byte *)"\x01\x00", 2);         // NumChannels (1 = mono)
  file.write((byte *)&sampleRate, 4);        // SampleRate
  file.write((byte *)&byteRate, 4);          // ByteRate = SampleRate * NumChannels * BitsPerSample/8
  file.write((byte *)"\x01\x00", 2);         // BlockAlign = NumChannels * BitsPerSample/8
  file.write((byte *)"\x08\x00", 2);         // BitsPerSample = 8

  // data subchunk
  file.write("data");
  file.write((byte *)&dataSize, 4);          // Subchunk2Size
}


void main_SD_Setup(PubSubClient& mqttClient) {
  Serial.begin(115200);
  if (!SD.begin(CS_PIN)) {
    mqttClient.publish(topic_pub_log, "Lỗi khởi động thẻ SD!");
    return;
  }
  audioFile = SD.open("/record.wav", FILE_WRITE);
  if (!audioFile) {
    mqttClient.publish(wavfile, "Lỗi không ghi record!");
    return;
  }
  int totalSamples = SAMPLE_RATE * RECORD_SECONDS;

  // Ghi header WAV tạm (sẽ cập nhật lại sau)
  for (int i = 0; i < 44; i++) audioFile.write((byte)0);

  // Ghi dữ liệu mẫu 8-bit (giữa 0–255)
  for (int i = 0; i < totalSamples; i++) {
    int val = analogRead(MIC_PIN);     // 0–4095
    uint8_t sample = map(val, 0, 4095, 0, 255);
    audioFile.write(sample);
    delayMicroseconds(1000000 / SAMPLE_RATE); // Điều chỉnh theo sample rate
  }

  // Cập nhật header WAV thật
  writeWavHeader(audioFile, SAMPLE_RATE, totalSamples);
  audioFile.close();
}

void main_SD_Loop() {
  
}