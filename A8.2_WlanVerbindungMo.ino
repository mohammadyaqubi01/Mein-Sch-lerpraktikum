#include <ESP8266WiFi.h>

// WiFi parameters to be configured
const char* ssid = "WlAnLAPTOP"; // Replace with your network's SSID
const char* password = "112233445566"; // Replace with your network's password

void setup() {
    Serial.begin(115200);
    delay(10);

    // Connect to Wi-Fi
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("Connected!");
}

void loop() {
    // Your main loop code here
}
