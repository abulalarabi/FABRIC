## Abstract

Sign language serves individuals with hearing impairments as a crucial mode of communication through visual-manual means. While embodiment is a well-established concept across multiple disciplines, limited research has directly addressed how to lower the barriers to engaging with the physical body for spatial perception and interaction. Embodied robots remain cost-prohibitive, and existing open-source robot fabrication platforms often fail to fully capture the nuances of human communication. These systems typically rely on predefined behaviors and require substantial technical expertise to reprogram for broader bodily interactions—such as those found in domains like construction or healthcare.

We introduce **FABRIC**: an end-to-end toolkit for fabricating and programming bodily language for human-robot interaction. FABRIC enables users to build a fully 3D-printable robot using affordable consumer-grade FDM printers. The system leverages learning-from-demonstration (LfD) techniques to capture and replicate users’ upper-torso movements—including arms and hands—for expressive robotic motion. A visual programming interface allows users to append or sequence demonstrations using inputs from videos, live cameras, and expandable phrase libraries, thereby lowering the barrier to designing embodied, expressive robots.

<p align="center">
  <img src="figures/applications/sentences.jpg" width="95%">
</p>

## Paper Citation
BIBTEX coming soon.

## System Overview

![FABRIC robot components](figures/structurev3.jpg)

Components of the FABRIC robot:  
(a) Assembled FABRIC unit  
(b) Shoulder joints  
(c) Finger movement servos mounted inside the upper arm  
(d) Elbow and wrist joint  
(e) Robotic hand

## Bill of Materials
### BoM and Component List

| Component                           | Quantity       | URL |
|------------------------------------|----------------|-----|
| ESP32 microcontroller              | 1              | [Link](https://www.amazon.com/s?k=ESP32+microcontroller) |
| PCA9685 Servo Driver               | 2              | [Link](https://www.amazon.com/s?k=PCA9685+Servo+Driver+module) |
| LM2596S DC-DC Converter            | 1              | [Link](https://www.amazon.com/s?k=LM2596S+DC-DC+Converter) |
| MG996R Servos (arm)                | 8              | [Link](https://www.amazon.com/s?k=MG996R+servo+motor) |
| SG90 Servos (finger/wrist)        | 14             | [Link](https://www.amazon.com/s?k=SG90+mini+servo+motor) |
| PLA Filament (~1.5 kg)            | ~1.5 kg        | [Link](https://www.amazon.com/s?k=PLA+1.75mm+3D+printer+filament) |
| TPU Filament (~0.25 kg)           | ~0.25 kg       | [Link](https://www.amazon.com/s?k=TPU+1.75mm+flexible+filament) |
| PTFE Tube                          | 1 meter        | [Link](https://www.amazon.com/s?k=PTFE+tube+1.75mm) |
| Power Adapter (12V 10A)           | 1              | [Link](https://www.amazon.com/s?k=12V+10A+DC+power+adapter) |
| Display (7" Raspberry Pi LCD)     | 1              | [Link](https://www.amazon.com/s?k=7+inch+Raspberry+Pi+LCD+touch+screen) |
| Jumper Wires, Headers             | —              | [Link](https://www.amazon.com/s?k=jumper+wires+male+to+female+kit) |
| Nylon String (Cables)             | —              | [Link](https://www.amazon.com/s?k=nylon+string+for+robotics) |
| Superglue                         | —              | [Link](https://www.amazon.com/s?k=superglue) |
| Screws, zip ties                  | —              | [Link](https://www.amazon.com/s?k=M3+screws+zip+ties+kit) |

## Design Files
<table>
  <tr>
    <td align="center">
      <a href="design_files/body">
        <img src="design_files/thumbnails/body.png" height="120px"><br/>
        <sub><b>Body</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="design_files/elbow">
        <img src="design_files/thumbnails/elbow.png" height="120px"><br/>
        <sub><b>Elbow</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="design_files/head">
        <img src="design_files/thumbnails/head.png" height="120px"><br/>
        <sub><b>Head</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="design_files/shoulder">
        <img src="design_files/thumbnails/shoulder.png" height="120px"><br/>
        <sub><b>Shoulder</b></sub>
      </a>
    </td>
  </tr>
  <tr>
    <td align="center">
      <a href="design_files/wrist+hand">
        <img src="design_files/thumbnails/wrist.png" height="120px"><br/>
        <sub><b>Wrist + Hand</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="design_files/rivets">
        <img src="design_files/thumbnails/rivets.png" height="120px"><br/>
        <sub><b>Rivets</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="design_files/stand">
        <img src="design_files/thumbnails/stand.png" height="120px"><br/>
        <sub><b>Stand</b></sub>
      </a>
    </td>
    <td></td>
  </tr>
</table>

## Firmware
Arduino firmware for ESP32

## Frontend

## Backend