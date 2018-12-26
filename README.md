# Home-Automation-System
Radio Frequency Identification (RFID) scanner is used within the home security device that takes the stored information of two  tags, the user is able to decide which tag can allow access to be granted and another tag that denies the access.  An ESP8266 micro-controller(micro- controller with WIFI module) is used to recognize the information for the access granted tag and the access denied tag. Two more ESP8266 micro-controllers will be connected to a Liquid Crystal Display(LCD) and a servomotor where these devices will demonstrate certain tasks based on which tag is used. The LCD will show "Access denied" and the servo motor will not respond, if the access denied tag is used on the RFID. The LCD will show "Access Granted" and the servo motor will sweep from 0 to180 degrees and back ,if the the access granted tag is used. The user is able to use this system through an IOT platform where the three ESP8266 micro-controllers are connected. 