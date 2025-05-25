#define WIFI_SSID "Huynh"
#define WIFI_PASSWORD "0353744710"

#define LED_PIN 2
#define FPSerial Serial1  // For ESP32, use hardware serial port 1
#define CS_PIN 5  // Chân CS bạn đã chọn

SPIClass spi = SPIClass(VSPI);  // Dùng SPI mặc định trên ESP32 (VSPI)

#define MIC_PIN 34  // GPIO nối chân OUT của MAX4466

#define SAMPLE_RATE 8000    // Tần số lấy mẫu (Hz)
#define RECORD_SECONDS 10   // Thời gian ghi âm