#include <ESP8266WiFi.h>
 
void setup() {
  Serial.begin(115200);
  Serial.println("ESP Gestartet");
  WiFi.begin("WlAnLAPTOP", "112233445566");
 
  Serial.println("Verbindung wird hergestellt...");
 while (WiFi.status() != WL_CONNECTED) 
 {
    delay(500);
    Serial.print(".");
  {
  Serial.println();
  }
  Serial.println("Verbindung erfolgreich! IP Adresse: ");
 Serial.println(WiFi.localIP());
}
}
void loop() {


}
