``` 🧩 1. Setup Overview

Components:

ESP32 with DHT11

Node.js + Express server

HTML page that shows latest temperature & humidity

ESP32 sends data using an HTTP POST request to the Node.js API

⚙️ 2. Node.js Server Code (Express)
📁 server.js
const express = require('express');
const app = express();
const port = 3000;

// Middleware to parse JSON data
app.use(express.json());

// Store latest sensor data
let sensorData = {
  temperature: 0,
  humidity: 0,
  timestamp: Date.now()
};

// API to receive data from ESP32
app.post('/api/data', (req, res) => {
  const { temperature, humidity } = req.body;
  if (temperature !== undefined && humidity !== undefined) {
    sensorData = { temperature, humidity, timestamp: Date.now() };
    console.log("Data received:", sensorData);
    res.json({ success: true, message: 'Data received successfully' });
  } else {
    res.status(400).json({ success: false, message: 'Invalid data format' });
  }
});

// API to send data to webpage
app.get('/api/data', (req, res) => {
  res.json(sensorData);
});

// Serve static webpage
app.use(express.static('public'));

app.listen(port, () => console.log(`Server running on http://localhost:${port}`));

🌐 3. Webpage (Frontend)

Create folder public/index.html next to your server.js file:

📄 public/index.html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>ESP32 DHT11 Dashboard</title>
  <style>
    body { font-family: Arial; text-align: center; margin-top: 50px; background: #f4f4f4; }
    .card { background: white; padding: 30px; border-radius: 15px; width: 300px; margin: auto; box-shadow: 0 0 10px rgba(0,0,0,0.1); }
    h2 { color: #333; }
    p { font-size: 20px; color: #555; }
  </style>
</head>
<body>
  <div class="card">
    <h2>🌡️ DHT11 Sensor Data</h2>
    <p id="temp">Temperature: -- °C</p>
    <p id="hum">Humidity: -- %</p>
    <p id="time">Last Updated: --</p>
  </div>

  <script>
    async function getData() {
      const res = await fetch('/api/data');
      const data = await res.json();
      document.getElementById('temp').innerText = `Temperature: ${data.temperature} °C`;
      document.getElementById('hum').innerText = `Humidity: ${data.humidity} %`;
      document.getElementById('time').innerText = `Last Updated: ${new Date(data.timestamp).toLocaleTimeString()}`;
    }
    setInterval(getData, 3000);
    getData();
  </script>
</body>
</html>

🔌 4. ESP32 Code (Arduino IDE)

Make sure you have:

DHT11 library

WiFi library

📄 esp32_dht11.ino
#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 4          // GPIO pin where DHT11 is connected
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// Replace with your WiFi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Replace with your Node.js server IP
const char* serverURL = "http://192.168.1.100:3000/api/data"; // Change IP!

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    if (isnan(temp) || isnan(hum)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    HTTPClient http;
    http.begin(serverURL);
    http.addHeader("Content-Type", "application/json");

    String jsonData = "{\"temperature\":" + String(temp) + ",\"humidity\":" + String(hum) + "}";
    int httpResponseCode = http.POST(jsonData);

    if (httpResponseCode > 0) {
      Serial.println("Data sent successfully");
    } else {
      Serial.print("Error sending data: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("WiFi not connected");
  }

  delay(5000); // send every 5 seconds
}

🚀 5. How to Run Everything

Run your server:

node server.js


Open browser → http://localhost:3000

ESP32 will start sending data automatically.

The webpage updates every 3 seconds. ```