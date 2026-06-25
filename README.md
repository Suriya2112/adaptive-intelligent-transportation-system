# 🚑 Adaptive Intelligent Transportation System

> An IoT-based smart traffic management system that creates an automatic emergency corridor for ambulances using intelligent divider control, real-time GPS tracking, and automated signal prioritization.

---

## 📖 Overview

In densely populated urban areas, traffic congestion is a critical barrier to emergency medical response. This project addresses that by building a **Smart Ambulance Corridor** — a system that detects an approaching ambulance and automatically clears its path through:

- Moving road dividers via servo motor control
- Adjusting traffic signals in real time
- Sending GPS-linked SMS alerts to emergency contacts
- Displaying live system status on an LCD

The entire system runs on an **ESP32 NodeMCU**, making it low-cost, scalable, and deployable in smart city infrastructure.

---

## ✨ Features

- 🔍 **Automatic Ambulance Detection** — IR sensors identify emergency vehicles in both lanes
- 🚧 **Intelligent Divider Control** — Servo motor opens/closes the road divider automatically
- 🚦 **Traffic Signal Prioritization** — LEDs simulate smart signal management for the ambulance lane
- 📲 **Emergency SMS Alerts** — GSM module sends real-time notifications with Google Maps location link
- 📍 **GPS Location Tracking** — Live coordinates for ambulance navigation and monitoring
- 🖥️ **LCD Status Display** — Shows system state (detecting, corridor open, normal mode)
- 🔔 **Audible Buzzer Alert** — Audible warning on ambulance detection
- 🌐 **IoT-Enabled Automation** — Fully automated with no manual intervention required

---

## 🔧 Hardware Components

| Component | Role |
|---|---|
| ESP32 NodeMCU | Central controller |
| IR Sensor (x2) | Vehicle detection (Lane 1 & Lane 2) |
| Servo Motor | Divider / barrier control |
| GSM Module | SMS alerts with location |
| GPS Module | Real-time location tracking |
| 16x2 LCD Display | System status messages |
| LEDs (R/Y/G) | Traffic signal indication |
| Buzzer | Audible emergency alert |
| Power Supply | System power |

---

## 🗂️ System Architecture

```
INPUT MODULES                              OUTPUT MODULES
─────────────                              ──────────────
IR Sensor 1 (Lane 1) ──┐                ┌── Servo Motor (Divider)
IR Sensor 2 (Lane 2) ──┤                ├── Traffic Lights (LEDs)
GPS Module           ──┤── ESP32 ───────┤── 16x2 LCD Display
                        │  (NodeMCU)    ├── Buzzer
                        │               └── GSM → Mobile User (SMS + Maps Link)
                        └──────────────────────────────────────┘
```

**System Workflow:**
```
Ambulance Detected → Divider Opens → Signal Control Activated → Location Sent via SMS → User Receives Alert
```

---

## ⚙️ How It Works

1. IR sensors continuously monitor both lanes for incoming vehicles.
2. On ambulance detection, the ESP32 triggers the control sequence.
3. The **servo motor rotates 90°** to open the road divider, creating a clear corridor.
4. Traffic signals switch to prioritize the ambulance lane.
5. The **GSM module dispatches an SMS** with the GPS coordinates (as a Google Maps link) to predefined contacts.
6. The **LCD updates** with the current system status.
7. After a set delay, the divider closes and the system returns to normal monitoring mode.

---

## 💻 Sample Code (Simplified Demo)

```cpp
#include <ESP32Servo.h>

Servo divider;
int irSensor = 32;
int servoPin = 4;

void setup() {
  pinMode(irSensor, INPUT);
  divider.attach(servoPin);
  divider.write(0); // Divider closed by default
  Serial.begin(9600);
}

void loop() {
  int vehicleDetected = digitalRead(irSensor);

  if (vehicleDetected == LOW) {
    Serial.println("Emergency vehicle detected");
    divider.write(90);  // Open divider
    delay(3000);
    divider.write(0);   // Close divider
  }
}
```

> **Note:** This is a simplified public demo. The complete implementation (GSM/GPS integration, multi-lane logic, signal control) is withheld due to ongoing research and IP considerations.

---

## 🛠️ Technologies Used

- **Microcontroller:** ESP32 NodeMCU
- **IDE:** Arduino IDE
- **Communication:** GSM (SMS), GPS (NMEA)
- **Actuation:** Servo Motor Automation
- **Sensing:** IR Sensors
- **Display:** 16x2 LCD Module
- **Domain:** IoT & Embedded Systems

---

## 🚀 Applications

- Smart City Traffic Infrastructure
- Emergency Medical Services (EMS)
- Intelligent Highway Corridors
- Urban Emergency Management
- Public Safety Systems

---

## 📈 Future Enhancements

- [ ] AI-based vehicle recognition (camera + ML model)
- [ ] Cloud server integration & remote dashboard
- [ ] Mobile application for live monitoring
- [ ] Real-time traffic analytics
- [ ] Coordination of multiple simultaneous ambulances
- [ ] Integration into a broader smart city network

---

## 👤 Author

**Suriya Narayanan S**  
Domain: Internet of Things (IoT) & Smart Transportation Systems  
GitHub: [@Suriya2112](https://github.com/Suriya2112)

---

## 📄 License

This project is for academic and research purposes. Complete source code is not publicly available at this time due to ongoing research publication.

---

*Built to save lives — one green corridor at a time. 🚑💨*
