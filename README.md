# 🏥 Touch-Based Device Control System for Bedridden Patients
# 📖 Table of Contents
- Overview
- Problem Statement
- Proposed Solution
- Objectives
- Features
- Hardware Requirements
- Software Requirements
- Block Diagram
- Project Hardware
- Working Principle
- Password Authentication
- Password Update Process
- Communication Protocols
- Software Modules
- Results
- Applications
- Advantages
- Future Enhancements
- Learning Outcomes
- Author
# 📖 Project Overview
The Touch-Based Device Control System for Bedridden Patients is an Embedded Systems project developed to assist patients with limited mobility in operating electrical appliances independently through a secure touch-based interface.
The system uses the LPC2148 ARM7 Microcontroller as the central processing unit to coordinate the operation of multiple peripherals including a resistive touchscreen, matrix keypad, LCD display, EEPROM, buzzer, and external interrupt module.
To ensure secure operation, every user must authenticate using a password entered through the keypad. The password is stored permanently inside the AT25LC512 SPI EEPROM, allowing it to remain available even after power loss.
After successful authentication, the touchscreen becomes active, enabling the patient to control connected appliances by simply touching predefined regions on the screen. Each touch location corresponds to a specific device, making the interface intuitive and easy to use.
The project demonstrates practical implementation of Embedded C programming,ARM7 peripheral interfacing,SPI communication,EEPROM memory management,and touchscreen-based system.
# ❗ Problem Statement
Patients who are bedridden often depend on caregivers to perform simple daily tasks such as switching electrical appliances ON or OFF. Traditional wall-mounted switches are difficult or impossible to reach, reducing patient independence and comfort.
There is a need for an easy-to-use, secure, and reliable device control system that enables patients to operate appliances with minimal physical effort while preventing unauthorized access.
# 💡 Proposed Solution
This project introduces a secure touch-based appliance control system designed specifically for bedridden patients.
The system authenticates users through a password entered using a matrix keypad. Once authentication is successful, the resistive touchscreen is activated, allowing the patient to control connected devices through simple touch inputs.
An external interrupt mechanism provides secure password modification, while the AT25LC512 EEPROM stores updated passwords permanently using SPI communication.
# 🎯 Objectives
- Assist bedridden patients in controlling appliances independently.
- Improve patient comfort and accessibility.
- Prevent unauthorized access using password authentication.
- Store passwords securely in EEPROM.
- Implement touch-based appliance control.
- Demonstrate Embedded C programming on LPC2148 ARM7.
# ⭐ Features
- Password-Protected Login
- Resistive Touchscreen Interface
- LCD-Based User Interface
- EEPROM Password Storage
- SPI Communication
- Matrix Keypad Password Entry
- External Interrupt Password Update
- Device ON/OFF Control
- Modular Embedded C Software Design
- User-Friendly Operation
# 🧩 Hardware Requirements

| Component | Purpose |
|-----------|---------|
| LPC2148 ARM7 | Main Controller |
| Resistive Touch Screen | User Input |
| 16×2 LCD | Display Messages |
| Matrix Keypad | Password Entry |
| AT25LC512 EEPROM | Password Storage |
| LEDs | Device Simulation |
| Buzzer | Emergency Alert |
| External Interrupt Switch | Password Update |
| Power Supply | System Power |
# 💻 Software Requirements

- Embedded C
- Keil uVision IDE
- Flash Magic
- Proteus (Optional for Simulation)

---

# 🖼️ Block Diagram

<img width="1392" height="1130" alt="BLOCK DIAGRAM" src="https://github.com/user-attachments/assets/555529d2-bda8-4e13-8df2-786026fd0266" />

# 📸 Project Hardware
<img width="1200" height="1600" alt="image" src="https://github.com/user-attachments/assets/8f3e746a-eaf8-476b-b379-b79c40b74e4c" />
<img width="1200" height="1600" alt="image" src="https://github.com/user-attachments/assets/617cc181-c0df-4789-891c-b04cf948bbdd" />
<img width="1200" height="1600" alt="image" src="https://github.com/user-attachments/assets/6830518a-f16b-4616-a411-cbcc6f6ebb5c" />
<img width="1200" height="1600" alt="image" src="https://github.com/user-attachments/assets/61a490e5-75b2-4ff1-a236-0fccf7f9d1a1" />






# ⚙️ Working Principle

### Step 1 – System Initialization

The LPC2148 initializes the LCD, keypad, EEPROM, touchscreen, GPIO ports, SPI interface, and interrupt controller.

### Step 2 – Password Authentication

The user enters a password through the keypad.

The controller retrieves the stored password from EEPROM via SPI and compares it with the entered password.

### Step 3 – Touchscreen Activation

If authentication succeeds, the touchscreen becomes active.

The user touches predefined regions corresponding to different appliances.

### Step 4 – Device Control

The controller reads touchscreen coordinates and identifies the selected device.

The selected appliance changes between ON and OFF.

The LCD continuously displays appliance status.

### Step 5 – Continuous Operation

The controller continuously monitors user touches until the system is reset or powered OFF.

---

# 🔐 Password Update Process

The password can be updated securely using an external interrupt.

1. Press the interrupt switch.
2. Enter the current password.
3. Verify password.
4. Enter a new password.
5. Confirm the new password.
6. Store the updated password into EEPROM through SPI communication.

The new password remains stored even after power OFF.

---

# 📡 Communication Protocols

## SPI

Used for communication between LPC2148 and AT25LC512 EEPROM.

Functions:

- Password Read
- Password Storage
- Password Update

## UART

Used during debugging and serial communication.

## External Interrupt

Used to activate password modification mode.

---

# 🧩 Software Modules

- LCD Driver
- Matrix Keypad Driver
- SPI Driver
- EEPROM Driver
- UART Driver
- Touchscreen Driver
- Interrupt Driver
- Password Authentication Module
- Password Update Module
- Device Control Module

# 📊 Results

The developed system successfully authenticates users using password verification, securely stores passwords in EEPROM, enables touchscreen-based appliance control, and provides interrupt-driven password modification.

The project demonstrates reliable operation of LCD, keypad, EEPROM, touchscreen, SPI communication, and Embedded C software integration.

---

# 🚀 Applications

- Smart Hospital Rooms
- Bedridden Patient Assistance
- Elderly Care Systems
- Home Automation
- Healthcare Automation
- Rehabilitation Centers
- Smart Medical Equipment

---

# ✅ Advantages

- Easy to operate
- Secure authentication
- Low power consumption
- Reliable EEPROM storage
- Modular software design
- User-friendly interface
- Expandable architecture
# 🔮 Future Enhancements

- IoT Integration
- Wi-Fi Connectivity
- Bluetooth Control
- Android Mobile Application
- Voice Recognition
- Biometric Authentication
- Cloud Monitoring
- AI-Based Patient Assistance

---

# 📚 Learning Outcomes

- ARM7 LPC2148 Programming
- Embedded C Programming
- LCD Interfacing
- Matrix Keypad Interfacing
- Resistive Touchscreen Interfacing
- EEPROM Programming
- SPI Communication
- UART Communication
- Interrupt Programming
- Embedded System Design

---

# 👩‍💻 Author

**Sirichandana Rapelli**

Electronics and Communication Engineering

Embedded Systems Enthusiast

GitHub:https://github.com/sirichandanarapelli04
---

## 🙏 Acknowledgement

This project was developed as part of an Embedded Systems academic program to demonstrate secure touch-based appliance control using the LPC2148 ARM7 microcontroller, Embedded C programming, SPI communication, EEPROM storage, and resistive touchscreen interfacing.

---

⭐ **Thank you for visiting this repository!**
