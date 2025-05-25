class Logger {
public:
    Logger(const String& deviceId, PubSubClient& mqttClient, const String& topicPrefix = "logs/", bool enableSerialLog = true)
        : _deviceId(deviceId), _mqttClient(mqttClient), _topicPrefix(topicPrefix), _enableSerialLog(enableSerialLog) {}

    void info(const String& message) { sendLog("INFO", message); }
    void warning(const String& message) { sendLog("WARNING", message); }
    void error(const String& message) { sendLog("ERROR", message); }

private:
    void sendLog(const String& level, const String& message) {
        String topic = _topicPrefix + _deviceId;
        String payload = "{\"device\":\"" + _deviceId + "\",\"level\":\"" + level + "\",\"message\":\"" + message + "\"}";
        if (_enableSerialLog) {
            Serial.println("[" + level + "] " + message);
        }
        _mqttClient.publish(topic_sub_log, "sssss");
        _mqttClient.publish(topic.c_str(), payload.c_str());
    }

    String _deviceId;
    PubSubClient& _mqttClient;
    String _topicPrefix;
    bool _enableSerialLog;
};

