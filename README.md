# Echosign

*Developed by Alfred and Haron, Grade 9 (2023)*

<img width="351" height="425" alt="image" src="https://github.com/user-attachments/assets/47d6f77e-8bc9-4526-9da5-c102a58ce9fd" />

---
## Demo Video

[![Echosign Demo](https://img.youtube.com/vi/Sl1a8Vcy5Fw/maxresdefault.jpg)](https://www.youtube.com/watch?v=Sl1a8Vcy5Fw)

## Abstract

According to the World Federation of the Deaf, there are more than 70 million deaf people worldwide. They have no means of communication with majority of people who don’t know Sign Language. They spend sizable amounts of money for personal translators who follow them everywhere they go. That is why me and my team of 9th Graders decided to create a device that can translate hands signs into text and speech in real-time.

This prototype uses 10 sensors on each finger to calculate the angle of the finger bend. An accelerometer is present in each hand for grasping X, Y, and Z axis location of both the hands, all of this is then sent to a computer for converting and translating each hand sign. Right now, we are building an AI system that can automatically recognize hands signs without manually entering each finger angle and X, Y, Z position. Our aim is to make a device that's easy to use, portable, and helps deaf people communicate better and more independently.


---

## Hardware

Components:

| Part                              | Usage                                                                     |
| --------------------------------- | ------------------------------------------------------------------------- |
| **Arduino Nano**                  | MCU for reading and relaying analog and digital signals from the sensors. |
| **Flex Sensors (Spectra Symbol)** | A variable resistor that changes its resistance according to its flex.    |
| **HC-04 BLE**                     | Relays the output from the Nano to a PC or Phone.                         |
| **ADXL345**                       | A device that can give its X-Y-Z position in real time.                   |
| **Battery Pack**                  | 4.8 V 3 A 2000mAh                                                         |
| **Gloves**                        | Comfortable and wearable enclosure for the device.                        |
| **PCB**                           | Custom PCB to eliminate wiring and improve durability.                    |

Please see the KiCAD schematics for the wiring diagram.

## Firmware

### Gloves Side (C/C++)

It uses the analog and digital pins to gather the states of all 10 fingers and relative position of the hand, concatenates it into a single string with each sensor reading separated by a comma and routes it to the host via the HC-04 Bluetooth module using the UART protocol every 1 second.

Since two separate gloves are used the device name assigned to the HC-04 modules must be differentiated.

### Host Side (Python)

Both the gloves connect to the host via Bluetooth and a Python script obtains the real-time sensor string, splits it, and assigns the split values into respective variables.

Then our basic algorithm takes these values and checks if the values are within a certain range of the preloaded word's sensor signature and returns what it thinks the word is if the probability is more than 80%.

It uses a TTS (Text-To-Speech) library for converting predicted text into speech.

---



*Last updated 9/2026*
