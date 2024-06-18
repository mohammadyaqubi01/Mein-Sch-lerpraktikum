void setup() {
  // Startet die serielle Kommunikation mit 115200 Baud
  Serial.begin(115200);
}

void loop() {
  // Gibt "Hello World!" auf dem seriellen Monitor aus
  Serial.println("Hello World!");
  // Wartet 1 Sekunde (1000 Millisekunden)
  delay(1000);
}
