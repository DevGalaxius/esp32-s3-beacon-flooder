# 🛜 ESP32-S3 Beacon Flooder

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform: ESP32](https://img.shields.io/badge/Platform-ESP32-blue.svg)](https://www.espressif.com/)
[![Arduino](https://img.shields.io/badge/Built%20with-Arduino-green.svg)](https://www.arduino.cc/)

> **[FLOOD MAX]**  
> Ex: "200+ fake WiFi networks that dominate the airwaves"

## ✨ Features

- 🎯 **200 unique SSIDs** with funny names
- 🔒 **WPA2 secured** appearance (lock icon)
- 📶 **Maximum signal strength** (20.5dBm)
- 🏆 **Appears at TOP** of WiFi lists
- ⚡ **Optimized for ESP32-S3-Zero**

## 📸 Preview

[TU_METS_UN_SCREENSHOT_ICI_QUAND_TU_AURAS_TESTÉ]

## 🛠️ Hardware

- **ESP32-S3-Zero** (Waveshare)
- USB-C cable

## 📥 Installation

1. Install [Arduino IDE](https://www.arduino.cc/en/software)
2. Add ESP32 board support in Preferences
3. Select board: **ESP32S3 Dev Module**
4. Upload code
5. Scan WiFi and enjoy!

## ⚙️ Configuration

```cpp
#define CHANNEL     1      // WiFi channel (1, 6, or 11)
#define NUM_SSIDS   200    // Number of networks
#define TX_POWER    78     // Max power
