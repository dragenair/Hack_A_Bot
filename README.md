# Hack_A_Bot
Robosoc Hack A Bot 2026 21st march. We would be making a robot from scratch from CAD, Programming as well as testing

## 👥 Our Team

| Name | Role | GitHub |
| :--- | :--- | :--- |
| **Utkarsh** | Lead Constructur | [@dragenair](https://github.com/dragenair) |
| **Juza** | Lead CAD designer | [@csm027](https://github.com/csm027) |
| **Sean** | Lead of Systems | [@juza-w](https://github.com/juza-w) |
| **Lun** | Lead Software | [@Lunw07](https://github.com/Lunw07) |

---

## the Projects
Catapult - Design an automated catapult that senses target distance adjusts its launch mechanism and hits targets accurately at varying ranges.
Fully automated catapult

Platformer - to build a robot which can cross gaps

## 🚀 What We Are Doing
We are designing and building a mobile robot from scratch. This project involves integrating custom hardware, real-time embedded software, and physical logic gates to navigate the RoboSoc challenge environment.

### 📐 Mechanical & CAD Design
Starting with a blank canvas, we are prototyping the physical bot:
* **Custom Chassis:** 3D-modeled parts (STL/STEP) designed for a low center of gravity.
* **Actuation:** Utilizing a **PCA9685** 16-channel driver to manage high-precision servo movements.
* **Component Housing:** Custom mounts for the **ESP32/Arduino** and power rails.

### 💻 Programming & Control
The software stack is built for speed and responsiveness:
* **Embedded Firmware:** Developed in **C++/Arduino** for low-latency motor response.
* **Data Processing:** Using **Python** (NumPy/Plotly) for sensor data analysis and performance tuning.
* **Navigation Logic:** Implementation of control loops to handle obstacle detection and movement.

### 🔢 Digital Logic & Circuitry
To ensure the bot behaves predictably, we’ve implemented hardware-level logic:
* **Digital Logic:** Utilizing NAND/NOR gate configurations for safety-stop interrupts.
* **VHDL Modules:** Custom logic blocks to offload signal processing from the main microcontroller.
* **Power Management:** Hand-wired circuits to prevent voltage drops during high-torque maneuvers.

---

## 📂 Project Structure
* `/src` - Firmware and C++ source code.
* `/cad` - 3D models and assembly files.
* `/logic` - VHDL files and digital logic diagrams.
* `/scripts` - Python tools for testing and debugging.

---

## 🛠️ Build Status
- [x] Initial Chassis Design
- [x] Circuit Protoboard Wiring
- [ ] Firmware Logic Implementation
- [ ] Final Competition Run
