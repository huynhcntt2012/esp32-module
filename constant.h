const char* serverUrl = "http://139.180.155.245:1880/api/data";
// MQTT Broker
const char* mqtt_server = "139.180.155.245";
const int mqtt_port = 1883;
//cau truc luu data
const char* topic_sub = "nha/den1";          // Nhận lệnh bật/tắt
const char* topic_pub = "nha/status/den1";   // Gửi trạng thái hiện tại
const char* topic_pub_pir = "nha/PIR";  
const char* topic_volume = "music/volume";  


unsigned long previousMillis = 0;
const long interval = 10000; // 10 giây

// Variables to send to the database
int intValue = 0;
float floatValue = 0.01;
String stringValue = "";

float temperature = 10;
float humidity = 11;
float id = 45;

const int relayPin = 2;     // Relay
const int pirPin = 14;      // PIR OUT

