const char* serverUrl = "http://139.180.155.245:1880/api/data";
// MQTT Broker
const char* mqtt_server = "fwa-ec.one";
const int mqtt_port = 8883;
//cau truc luu data
const char* topic_sub = "nha/den1";          // Nhận lệnh bật/tắt
const char* topic_pub = "nha/status/den1";   // Gửi trạng thái hiện tại
const char* topic_pub_pir = "nha/PIR";  
const char* topic_volume = "music/volume";  
const char* topic_pub_log = "logs";   // Gửi trạng thái hiện tại
const char* topic_iremote = "iremote";   // Gửi trạng thái hiện tại
const char* topic_motor = "motor";   // Gửi trạng thái hiện tại
const char* topic_max4466 = "max4466";   // Gửi trạng thái hiện tại
const char* topic_pub_log_wav = "wavfile";

String currentFile = "/music.mp3";// Biến tên file mp3 đang phát



const char* topic_dfplayer = "dfplayer/files";


// Variables to send to the database
int intValue = 0;
float floatValue = 0.01;
String stringValue = "";

unsigned long previousMillis = 0;
const long interval1s = 1000;  
const long interval2s = 2000;  
const long interval3s = 3000; 
bool ledState = false;

// ESP32 PWM test with Motor Shield L293D

int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int enable1Pin = 14; 

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;


float temperature = 10;
float humidity = 11;
float id = 45;

const int relayPin = 2;     // Relay
const int pirPin = 14;      // PIR OUT

const char* mqtt_topic = "esp32/pir";

const char* root_ca = \
"-----BEGIN CERTIFICATE-----\n"
"MIIFJTCCBA2gAwIBAgISBRV8eTvPPAwHEM21s3Wzu6NZMA0GCSqGSIb3DQEBCwUA\n"
"MDMxCzAJBgNVBAYTAlVTMRYwFAYDVQQKEw1MZXQncyBFbmNyeXB0MQwwCgYDVQQD\n"
"EwNSMTAwHhcNMjUwNDEyMDU1MDU2WhcNMjUwNzExMDU1MDU1WjAVMRMwEQYDVQQD\n"
"Ewpmd2EtZWMub25lMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAp8pz\n"
"8aCRCUkb232ZPT9k5uIQHihsgsBj70kI2DwNUj3TWCaBa93468Z/n8mXE5SR4hwH\n"
"e/ideq3DphCdAkVnkKL6JY41PLOwPLAW0nHN2EIxotpP1o1H0xDDoeJ9Aa1cyplD\n"
"XWGoIi7QS8C1X3OSkEldkRhzGyPOXEzG+yGobDmj0UmIPlUXRD5U7xFKRC8D+Jrk\n"
"3txjuGm2YmgEuhVSOXHJfHxIPIPVxPxXLl6UEUHlCvz09QKMmNGxBkip+lVABSuz\n"
"KcS40h/DAFNmk2FKMRcDGwz+RbX9PD9LRg8CWu4vrOrPLdcGkngle4eNZUjZqhit\n"
"Zc7krY1QKz3rYOLCrQIDAQABo4ICTzCCAkswDgYDVR0PAQH/BAQDAgWgMB0GA1Ud\n"
"JQQWMBQGCCsGAQUFBwMBBggrBgEFBQcDAjAMBgNVHRMBAf8EAjAAMB0GA1UdDgQW\n"
"BBTEhmUxx6rAZiB+l2GO+nfAwEGh5DAfBgNVHSMEGDAWgBS7vMNHpeS8qcbDpHIM\n"
"EI2iNeHI6DBXBggrBgEFBQcBAQRLMEkwIgYIKwYBBQUHMAGGFmh0dHA6Ly9yMTAu\n"
"by5sZW5jci5vcmcwIwYIKwYBBQUHMAKGF2h0dHA6Ly9yMTAuaS5sZW5jci5vcmcv\n"
"MCUGA1UdEQQeMByCCmZ3YS1lYy5vbmWCDnd3dy5md2EtZWMub25lMBMGA1UdIAQM\n"
"MAowCAYGZ4EMAQIBMC4GA1UdHwQnMCUwI6AhoB+GHWh0dHA6Ly9yMTAuYy5sZW5j\n"
"ci5vcmcvOTAuY3JsMIIBBQYKKwYBBAHWeQIEAgSB9gSB8wDxAHYAfVkeEuF4Knsc\n"
"YWd8Xv340IdcFKBOlZ65Ay/ZDowuebgAAAGWKMKizwAABAMARzBFAiAWW4PkjWlp\n"
"O88ssEQalFWiZCu2X58fuGMSXS4Y7ZdWmQIhANmwScdT0MrSovaziarUku26kZLn\n"
"w9gEFYXGdT+3u7ztAHcArxgaKNaMo+CpikycZ6sJ+Lu8IrquvLE4o6Gd0/m2Aw0A\n"
"AAGWKMKlnAAABAMASDBGAiEAzNJCCkKhJZusYuxX90auQcsqnQf30YoI5PFpm5SG\n"
"P1oCIQCe6/RRtAphWW2YSmG4d1Y9SEFFs/3UXOwbBNWnSprH+jANBgkqhkiG9w0B\n"
"AQsFAAOCAQEArjt/co5hAD0yOL4+AwNGGS10UnYUZBCnHFnUdohMhIyF6Mne8goQ\n"
"bBVFJqlsjjEaZb1YQ5R6q+9yNw4rKhOBYMp4OoosqQzPdcffvpy9VGNCKhW4WFbC\n"
"swrsk5DYz9ypAn5ViMeC8E5DFsqO+XiBMQ2u870gXbLbGtmorRTCdR1bPInO3kUO\n"
"IPWjnhofZq6sJZy5PY9oLtecz7+a9XdK3yWjtW7ePrm9RegEdShFAWrsmMuM9/iA\n"
"4FIjY0M4IODEgLLGZa33T688XEqYGzylZn9+uqCDLmnMy27Hg/PCxYPVeSDv1nsz\n"
"D3UJUBOOttHogEDT22SYMATzYS+IVFLpWw==\n"
"-----END CERTIFICATE-----\n"
"-----BEGIN CERTIFICATE-----\n"
"MIIFBTCCAu2gAwIBAgIQS6hSk/eaL6JzBkuoBI110DANBgkqhkiG9w0BAQsFADBP\n"
"MQswCQYDVQQGEwJVUzEpMCcGA1UEChMgSW50ZXJuZXQgU2VjdXJpdHkgUmVzZWFy\n"
"Y2ggR3JvdXAxFTATBgNVBAMTDElTUkcgUm9vdCBYMTAeFw0yNDAzMTMwMDAwMDBa\n"
"Fw0yNzAzMTIyMzU5NTlaMDMxCzAJBgNVBAYTAlVTMRYwFAYDVQQKEw1MZXQncyBF\n"
"bmNyeXB0MQwwCgYDVQQDEwNSMTAwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEK\n"
"AoIBAQDPV+XmxFQS7bRH/sknWHZGUCiMHT6I3wWd1bUYKb3dtVq/+vbOo76vACFL\n"
"YlpaPAEvxVgD9on/jhFD68G14BQHlo9vH9fnuoE5CXVlt8KvGFs3Jijno/QHK20a\n"
"/6tYvJWuQP/py1fEtVt/eA0YYbwX51TGu0mRzW4Y0YCF7qZlNrx06rxQTOr8IfM4\n"
"FpOUurDTazgGzRYSespSdcitdrLCnF2YRVxvYXvGLe48E1KGAdlX5jgc3421H5KR\n"
"mudKHMxFqHJV8LDmowfs/acbZp4/SItxhHFYyTr6717yW0QrPHTnj7JHwQdqzZq3\n"
"DZb3EoEmUVQK7GH29/Xi8orIlQ2NAgMBAAGjgfgwgfUwDgYDVR0PAQH/BAQDAgGG\n"
"MB0GA1UdJQQWMBQGCCsGAQUFBwMCBggrBgEFBQcDATASBgNVHRMBAf8ECDAGAQH/\n"
"AgEAMB0GA1UdDgQWBBS7vMNHpeS8qcbDpHIMEI2iNeHI6DAfBgNVHSMEGDAWgBR5\n"
"tFnme7bl5AFzgAiIyBpY9umbbjAyBggrBgEFBQcBAQQmMCQwIgYIKwYBBQUHMAKG\n"
"Fmh0dHA6Ly94MS5pLmxlbmNyLm9yZy8wEwYDVR0gBAwwCjAIBgZngQwBAgEwJwYD\n"
"VR0fBCAwHjAcoBqgGIYWaHR0cDovL3gxLmMubGVuY3Iub3JnLzANBgkqhkiG9w0B\n"
"AQsFAAOCAgEAkrHnQTfreZ2B5s3iJeE6IOmQRJWjgVzPw139vaBw1bGWKCIL0vIo\n"
"zwzn1OZDjCQiHcFCktEJr59L9MhwTyAWsVrdAfYf+B9haxQnsHKNY67u4s5Lzzfd\n"
"u6PUzeetUK29v+PsPmI2cJkxp+iN3epi4hKu9ZzUPSwMqtCceb7qPVxEbpYxY1p9\n"
"1n5PJKBLBX9eb9LU6l8zSxPWV7bK3lG4XaMJgnT9x3ies7msFtpKK5bDtotij/l0\n"
"GaKeA97pb5uwD9KgWvaFXMIEt8jVTjLEvwRdvCn294GPDF08U8lAkIv7tghluaQh\n"
"1QnlE4SEN4LOECj8dsIGJXpGUk3aU3KkJz9icKy+aUgA+2cP21uh6NcDIS3XyfaZ\n"
"QjmDQ993ChII8SXWupQZVBiIpcWO4RqZk3lr7Bz5MUCwzDIA359e57SSq5CCkY0N\n"
"4B6Vulk7LktfwrdGNVI5BsC9qqxSwSKgRJeZ9wygIaehbHFHFhcBaMDKpiZlBHyz\n"
"rsnnlFXCb5s8HKn5LsUgGvB24L7sGNZP2CX7dhHov+YhD+jozLW2p9W4959Bz2Ei\n"
"RmqDtmiXLnzqTpXbI+suyCsohKRg6Un0RC47+cpiVwHiXZAW+cn8eiNIjqbVgXLx\n"
"KPpdzvvtTnOPlC7SQZSYmdunr3Bf9b77AiC/ZidstK36dRILKz7OA54=\n"
"-----END CERTIFICATE-----\n";
