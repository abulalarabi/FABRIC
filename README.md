## Abstract

Sign language serves individuals with hearing impairments as a crucial mode of communication through visual-manual means. While embodiment is a well-established concept across multiple disciplines, limited research has directly addressed how to lower the barriers to engaging with the physical body for spatial perception and interaction. Embodied robots remain cost-prohibitive, and existing open-source robot fabrication platforms often fail to fully capture the nuances of human communication. These systems typically rely on predefined behaviors and require substantial technical expertise to reprogram for broader bodily interactions—such as those found in domains like construction or healthcare.

We introduce **FABRIC**: an end-to-end toolkit for fabricating and programming bodily language for human-robot interaction. FABRIC enables users to build a fully 3D-printable robot using affordable consumer-grade FDM printers. The system leverages learning-from-demonstration (LfD) techniques to capture and replicate users’ upper-torso movements—including arms and hands—for expressive robotic motion. A visual programming interface allows users to append or sequence demonstrations using inputs from videos, live cameras, and expandable phrase libraries, thereby lowering the barrier to designing embodied, expressive robots.

<p align="center">
  <img src="figures/applications/sentences.jpg" width="95%">
</p>

## System Overview

![FABRIC robot components](figures/structurev3.jpg)

Components of the FABRIC robot:  
(a) Assembled FABRIC unit  
(b) Shoulder joints  
(c) Finger movement servos mounted inside the upper arm  
(d) Elbow and wrist joint  
(e) Robotic hand
