# Instagram Portal WiFi Captive

A captive portal project for ESP8266 that simulates Instagram login page.

## Features
- Realistic Instagram login interface
- Automatic captive portal redirect
- Credential storage
- Admin panel for viewing stored data
- Mobile-responsive design

## Hardware Requirements
- ESP8266 board (NodeMCU, Wemos D1 Mini, etc.)
- USB cable for programming

## Software Requirements
- Arduino IDE
- ESP8266 board package
- Required libraries:
  - ESP8266WiFi
  - DNSServer
  - ESP8266WebServer

## Installation
1. Install Arduino IDE
2. Add ESP8266 board support to Arduino IDE
3. Install required libraries
4. Upload the code to your ESP8266

## Usage
1. Upload the code to ESP8266
2. Power on the device
3. Connect to "Free WiFi" network
4. Wait for the captive portal or navigate to 192.168.4.1
5. Access admin panel at 192.168.4.1/admin (default password: zaid46)

## Configuration
You can modify these settings in the code:
- WiFi SSID (default: "Free WiFi")
- Admin password
- Maximum stored credentials (default: 50)

## Disclaimer
This project is for educational purposes only. Do not use it for malicious purposes.

## License
This project is for educational purposes only.
