#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

// WLAN-Zugangsdaten
const char* ssid = "WlAnLAPTOP";
const char* password = "112233445566";

// Webserver läuft auf Port 80
ESP8266WebServer server(80);

// NTP-Client
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "time.nist.gov", 3600, 60000);  // NTP-Server, Zeitverschiebung in Sekunden, Intervall der Abfrage in Millisekunden

void setup() {
  // Seriellen Monitor starten
  Serial.begin(115200);
  
  // WLAN-Verbindung herstellen
  WiFi.begin(ssid, password);
  Serial.println("Verbindet zum WLAN...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  // Verbunden
  Serial.println("");
  Serial.print("Verbunden! IP-Adresse: ");
  Serial.println(WiFi.localIP());
  
  // NTP-Client starten
  timeClient.begin();
  
  // Initiale Zeitabfrage
  Serial.println("Frage initiale Zeit vom NTP-Server ab...");
  if (timeClient.update()) {
    Serial.println("Zeit erfolgreich bezogen!");
    Serial.println(timeClient.getFormattedTime());
  } else {
    Serial.println("Zeit konnte nicht bezogen werden!");
  }
  
  // Endpunkt definieren
  server.on("/", handleRoot);
  
  // Server starten
  server.begin();
  Serial.println("HTTP Server gestartet");
}

void loop() {
  server.handleClient();
  timeClient.update();  // Aktualisiert die Zeit in regelmäßigen Abständen
}

void handleRoot() {
  String html = "<html><body><h1>Aktuelle Uhrzeit</h1><p>";
  html += timeClient.getFormattedTime();
  html += "</p></body></html>";
  server.send(200, "text/html", html);
}
