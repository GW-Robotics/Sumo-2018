# Sumo 2018
### Instructions
Move the sumo folder wherever you like, but do not rename the folder or the file inside.
You can freely edit the contents of sumo.ino however you like.

In the Arduino IDE, click on __Sketch -> Include Library -> Add .ZIP Library__ 
and add the *SparkFun_TB6612FNG_Arduino_Library-master.zip* from this repository.  This is required for
the sumo.ino file to compile successfully.

To control the robot, once the bluetooth module is connected to the arduino and supplied with power, connect to HC-06 on your laptop's bluetooth with pin code 1234.  Then, open up Mac.zip or Windows.zip depending on your OS and run the executable inside. You may need to disable your antivirus because it won't recognize the file.  The program will scan your system for available serial ports and then ask you to select one.  You may have to try multiple ports to find which one coorespondes with the HC-06 bluetooth module.  Once connected, use the arrow keys on your laptop to control the robot.
