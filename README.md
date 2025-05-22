#  Arduino Super System with VB.NET GUI

## 📌 Project Overview
The **Arduino Super System** is a multifunctional embedded automation project integrated with a **VB.NET desktop application**. It brings together real-time monitoring and remote control of multiple safety and smart automation subsystems using **Arduino Uno and Arduino Mega** microcontrollers.

This system showcases full-stack integration between **hardware sensors/actuators** and a **graphical user interface**, enabling standalone, real-time interaction via serial communication.

> 📝 This project was developed as a capstone project by an IT student team, combining hardware, software, and GUI development.

## 👥 Contributors
```
- Me: Project Manager, GUI Developer, Software Integrator, Documentation
- https://github.com/xionnnnn: Arduino Developer (Fire and Smoke Detection)
- Denmarc Maglipon: Arduino Developer (Gate Access Control)
- https://github.com/hei-design: Arduino Developer (Lightning Control)
- https://github.com/jsjs2324: Arduino Developer (Alarm System)
- Moira Chelsey Burbos: Arduino Developer (Alarm System)
- Lois Jay Rimorin: Arduino Developer (Alarm System)
- Kurt Francis Carpeso: Arduino Developer (Gate Access Control)
- Allyah Laroa: Arduino Developer (Earthquake Alarm)
- Sarah Pedillaga: Arduino Developer (Earthquake Alarm)
- Brent Kian Rasonabe: Miniature
```

## 🧩 Integrated Subsystems

1. 🔥 **Fire, Smoke, and Gas Alarm System**  
   - Detects hazardous smoke and gas levels using appropriate sensors  
   - Triggers alarms (buzzers, lights) and sends real-time status updates to the GUI

2. 🕵️🚪 **Motion Detection with Gate Access Control System**  
   - Uses PIR sensors to detect motion near a secured area (e.g., gate)  
   - Automatically activates gate response using a servo motor (e.g., opens when movement is detected)  
   - Sends motion activity and gate status feedback to the GUI

3. 💡 **Lighting Control System**  
   - Allows users to toggle lights ON/OFF directly from the GUI  
   - Operates through relay modules connected to lighting circuits

4. ⏰ **Scheduled Alarm System**  
   - Uses a Real-Time Clock (RTC) module to execute time-based actions  
   - Triggers alarms or device behaviors on predefined schedules

5. 🌎 **Earthquake Detection Simulation System**  
   - Simulates earthquake detection using a manual button press  
   - When activated, triggers alert indicators and GUI warnings  
   - Designed as a conceptual subsystem for emergency drills/testing


## 🛠️ Technologies Used
- **Frontend GUI**: VB.NET (Windows Forms)
- **Microcontrollers**: 
  - 🟦 Arduino Uno (Sensor Control)
  - 🟩 Arduino Mega (Master controller with multiple serial connections)
- **Communication**: Serial (COM Port via USB)
- **Modules & Components**: PIR sensor, Gas/Smoke sensors, Relay modules, Servo motors, RTC module, LEDs, buzzers

## 🔌 Hardware Integration Flow
1. Arduino sensors and actuators are wired and programmed using `.ino` sketches.
2. Data is transmitted between Arduino (Uno/Mega) and the VB.NET GUI over serial USB.
3. The GUI interprets data and updates status indicators.
4. Users can trigger device actions from the GUI, and commands are sent to the Arduino in real time.

## 📁 Project Folder Structure (Recommended)
```
Arduino-Super-System/
├── vbnet_gui/
│ ├── MainForm.vb
│ └── SerialCommunication.vb
├── arduino_sketches/
│ ├── fire_smoke_alarm.ino
│ ├── alarm_system.ino
│ ├── lighting_control.ino
│ └── gate_access.ino
│ └── earthquake.ino
├── docs/
│ ├── wiring_diagram.png
│ ├── system_design.pdf
│ └── user_manual.pdf
└── README.md
```

## 🧪 How to Run
### Hardware:
- Upload sketches to the Arduino Uno and Mega.
- Connect both boards to PC via USB.
- Ensure proper wiring (refer to `wiring_diagram.png`).

### Software:
1. Open the VB.NET solution in Visual Studio.
2. Configure COM port for serial communication.
3. Run the GUI and begin interaction with real-time data.

## 🎓 Capstone Project Context
This system was built as a project to integrate embedded systems with desktop applications. It combines real-world automation with user-friendly controls in a single interactive platform.

## 📜 License
This project is for educational use only. For permissions or contributions, contact the development team.
---
