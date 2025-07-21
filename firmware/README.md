## 📦 Requirements

### 🧠 Hardware
- ESP32 board
- 2x PCA9685 16-channel Servo Drivers

### 🛠️ Libraries
Install the following libraries via the Arduino Library Manager:
- `Adafruit PWM Servo Driver Library`

## ⚙️ Wiring

Make sure the PCA9685 drivers are connected via I2C:
- Right driver: I2C address `0x40`
- Left driver: I2C address `0x41`

Connect the ESP32 I2C pins (as defined in the code):
- `SDA` → GPIO 8
- `SCL` → GPIO 9

## 🚀 Upload and Run

1. Open the sketch in **Arduino IDE**.
2. Select the correct **Board** (e.g., ESP32 Dev Module) and **Port**.
3. Install all required libraries.
4. Upload the sketch to your ESP32.
5. Open the **Serial Monitor** with baud rate `115200`.

## 🧪 Usage

Control the servo poses by sending formatted commands over Serial:

### ▶️ Commands Format
Command follows CSV format. Each command must be followed by **newline (`\n`)**.

- Update left servo target pose:
l:90,90,90,90,90,90,90,90,90,90,90

- Update right servo target pose:
r:45,45,45,45,45,45,45,45,45,45,45

- Execute motion:
e

This moves both left and right servos to their updated target poses.

### 💡 Notes
- Values must be **11 comma-separated integers** representing angles from `0` to `180`.
- Angles will be mapped to the correct PWM range using `sermin` and `sermax`.


## 🛠️ Functions Overview

| Function       | Purpose                                           |
|----------------|----------------------------------------------------|
| `initPose()`   | Sets all servos to initial pose                   |
| `moveTo()`     | Moves right servos smoothly to a new pose         |
| `moveToL()`    | Moves left servos smoothly to a new pose          |
| `moveBoth()`   | Moves both left and right servos together         |
| `alphabet()`   | Moves a subset of right servos (e.g., finger group) |
| `parseAndStore()` | Parses incoming serial data and stores pose     |