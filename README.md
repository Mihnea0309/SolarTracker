<h1>Solar tracker</h1>

<h2>Objectives</h2>
The main objective of this project is to implement a solar panel developed with a technology to track the light. The system is made to optimise the efficiency with which the solar energy is being gained by automatically adjusting the angles of the panel depending on the position of the light.
<br />

<h2>The description of the solution</h2>
I made the tracking system on two axes using accessible materials, such as:

- Servo Motors: two SG90 90° servomotors, one for each axe, to ensure precise and controlled rotation of the solar panel
- Light sensors: Four type 5528 light sensors (LDR - Light Dependent Resistor) mounted in different corners of the solar panel to detect light intensity and send signals to the control unit.
- 10kΩ resistors
- Control unit: an Arduino Uno microcontroller programmed to process the data from the light sensors and control the drive motors, thus ensuring optimal orientation of the solar panel, using a breadboard
- Mini photovoltaic panel 5V 25mA
- Mounting bracket: PAN-TILT camera bracket, one recessed shunt canister cover and one exposed shunt canister

<h2>Project realization:</h2>

- First, we mounted the servos to the camera stand with screws and over that we put the recessed canister cover on which the four photoresistors are located.
- The next step was to drill a hole in the cover of the apparent by-pass can to epoxy the bracket onto it, and another one to run the wires from the motors and photoresistors into the box that will contain the breadboard and Arduino board. One last hole was drilled on the side for the microcontroller power cable. This was done using a heated screwdriver. 
- I then made the entire circuit without connecting the wires to the photoresistors. After putting it in the apparent can, we connected it to the photoresistors.
<p align="center">
  <img src="https://i.imgur.com/OzYa18Y.png" height="80%" width="80%" alt="Disk Sanitization Steps"/>
</p>
- Next, we worked on realizing the code for the optimal operation of the support. The workaround is to try to make the bracket go towards the light so that the values transmitted by the four sensors are as equal as possible. We did this by comparing the opposite sides two by two, the values of which we obtained after calculating the arithmetic average of two adjacent sensors. If one of the sides has a higher value, the support moves in the direction of that side.

<h2>Testing the solution</h2>
To test the project, we performed the following steps:
- We loaded the code on the Arduino board.
- Once loaded, the bracket moved to the coordinates we gave, the initial positions being 0 on each axis.
- Then, using a flashlight, we performed the testing, by which we could observe that the bracket works as we intended. We checked each photoresistor individually by illuminating each one independently and then each side. We also checked how it reacts to different light sources, such as from a lamp, a monitor, but also whether it works optimally in both a bright and a dark environment.


<h2>Languages Used</h2>

- <b>C</b> 

<h2>Environments Used </h2>

- <b>Arduino IDE</b>

<h3><a href = "https://video-mea.s3.eu-north-1.amazonaws.com/Videoclip+proiect.mp4">Video of the Solar Tracker explained in romanian</a></h3>
<h3><a href = "https://video-mea.s3.eu-north-1.amazonaws.com/Videoclip%20proiect%20subtitrat.mp4">Video of the Solar Tracker explained with subtitles in english.</a></h3>




<!--
 ```diff
- text in red
+ text in green
! text in orange
# text in gray
@@ text in purple (and bold)@@
```
--!>
