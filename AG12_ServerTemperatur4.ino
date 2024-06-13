#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// WiFi Einstellungen
const char* ssid = "WlAnLAPTOP";
const char* password = "112233445566";

int adcValue = 0;  // Variable to store Output of ADC
const int analogPin = A0;  // Define the pin for ADC reading

// Create an instance of the server
ESP8266WebServer server(80);

String ipAddress;

// Function to replace placeholders with actual values
String processor(const String& var){
  if(var == "IP_ADDRESS"){
    return ipAddress;
  }
  return String();
}

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>ESP8266 Web Server</title>
</head>
<body>
<h1>Temperature Sensor</h1>
<p>IP Address: %IP_ADDRESS%</p>
<p>Current Temperature: <span id="temperature">0.0</span> °C</p>
<script>
    setInterval(function() {
      fetch('/temperature')
        .then(response => response.text())
        .then(data => {
          document.getElementById('temperature').innerText = data;
        });
    }, 2000); // Update every 2 seconds
</script>
</body>
</html>
)rawliteral";

void handleRoot() {
  String html = index_html;
  html.replace("%IP_ADDRESS%", ipAddress);
  server.send(200, "text/html", html);
}

void handleTemperature() {
  adcValue = analogRead(analogPin); // Read the Analog Input value
  float voltage = adcValue * (3.3 / 1023.0); // Convert ADC value to voltage

  // Assuming using LM35 temperature sensor
  float temperatureC = voltage * 100.0; // Convert voltage to temperature (10mV per degree Celsius)

  server.send(200, "text/plain", String(temperatureC));
}

void setup() {
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.print(ssid);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to WiFi");
  ipAddress = WiFi.localIP().toString();
  Serial.print("IP address: ");
  Serial.println(ipAddress);
  
  // Define the root endpoint
  server.on("/", handleRoot);
  
  // Define the temperature endpoint
  server.on("/temperature", handleTemperature);
  
  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Handle client requests
  server.handleClient();
}
