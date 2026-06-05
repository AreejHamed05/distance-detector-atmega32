# Distance Detector with ATmega32

A real-time distance measurement system using an ATmega32 microcontroller
and HC-SR04 ultrasonic sensor, with live readings displayed on a 16x2 LCD screen.
Measures distances from 2 cm up to 400 cm with high accuracy and responsiveness.
Built as a personal project.

**July 2025 – August 2025**

---

## Overview

This project implements a compact, real-time distance measurement system
built around the ATmega32 microcontroller programmed in embedded C.
An HC-SR04 ultrasonic sensor emits 40 kHz sound waves and measures the
echo return time using the AVR's Input Capture Unit (ICU) on Timer1.
The calculated distance is displayed live on a 16x2 LCD, refreshed every
100 milliseconds for smooth real-time tracking. The system is suitable for
obstacle detection, robotics, and basic security applications.


---

## Features

- Measures distances from 2 cm to 400 cm using HC-SR04 ultrasonic sensor
- Echo time captured via AVR Timer1 Input Capture Unit (ICU) — no polling
- Distance calculated using the formula: `Distance (cm) = Echo Time (µs) / 58`
- Live output refreshed every 100ms on a 16x2 LCD
- LCD line 1 displays `Distance = XX.X`, line 2 permanently shows `cm`
- Potentiometer-adjusted LCD contrast for optimal visibility
- Known limitation: out-of-range targets (too close or too far) cause
  trigger/echo overlap, resulting in invalid readings on the LCD

---

## Hardware Components

| Component                  | Quantity |
|----------------------------|----------|
| ATmega32 Microcontroller   | 1        |
| HC-SR04 Ultrasonic Sensor  | 1        |
| 16x2 LCD Screen            | 1        |
| Potentiometer (LCD contrast)| 1       |
| Resistors                  | —        |
---

## Software & Tools

- Embedded C
- AVR-GCC / Atmel Studio
- AVR Timer1 Input Capture Unit (ICU)
- Libraries used: [list your .h and .c files here]

---

## How It Works

1. On power-up, the ATmega32 initializes the LCD and ultrasonic sensor driver
2. A fixed `Distance =` label appears on LCD line 1
3. Every 100ms, the microcontroller sends a short trigger pulse to the HC-SR04
4. The sensor emits a 40 kHz ultrasonic burst and waits for the echo
5. Timer1's ICU captures the echo pulse duration in microseconds
6. Distance is calculated using:
7. The result is written to the LCD immediately — if the object moves,
   the reading updates in real time
8. If no valid echo is received (target out of range), trigger and echo
   signals overlap, causing the LCD to display an invalid value —
   a known hardware limitation of the HC-SR04 at range boundaries

---

## Credits

Personal project — developed independently with minor collaborative input.

---

## License

MIT License — feel free to use and build on this.
