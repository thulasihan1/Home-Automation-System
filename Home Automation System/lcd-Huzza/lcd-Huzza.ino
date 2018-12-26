//////////////////////////////////////////////////////////////////////////////////
//                             Setup for LCD                          //
//////////////////////////////////////////////////////////////////////////////////
/*
   Connection Map

   SCL - SCL
   SDA - SDA
   VCC - USB (yes, it's 5v, but the I2C on the 3.3v ESP8266 does not complain)
   Gnd - Gnd
*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>



//////////////////////////////////////////////////////////////////////////////////
//                             Setup for CAYENNE IOT                            //
//////////////////////////////////////////////////////////////////////////////////

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>

// WiFi network info.
char ssid[] = "hello";
char wifiPassword[] = "323045302";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "5a00d640-ede8-11e8-8cb9-732fc93af22b";
char password[] = "5fa877084b2fba4ba13728711d244b9340bceeeb";
char clientID[] = "7b28f9d0-edfa-11e8-b82d-f12a91579eed";

unsigned long lastMillis = 0;




//////////////////////////////////////////////////////////////////////////////////
//                                      Setup                                   //
//////////////////////////////////////////////////////////////////////////////////
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  lcd.init();
  lcd.backlight();

  Serial.begin(115200);

  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  pinMode(0, OUTPUT);
}


//////////////////////////////////////////////////////////////////////////////////
//                                      Loop                                    //
//////////////////////////////////////////////////////////////////////////////////
void loop() {
  Cayenne.loop();

}

// Default function for sending sensor data at intervals to Cayenne.
// You can also use functions for specific channels, e.g CAYENNE_OUT(1) for sending channel 1 data.
CAYENNE_OUT_DEFAULT()
{
  // Write data to Cayenne here. This example just sends the current uptime in milliseconds on virtual channel 0.
  // Cayenne.virtualWrite(0, millis());
  // Some examples of other functions you can use to send data.
  //Cayenne.celsiusWrite(1, 22.0);
  //Cayenne.luxWrite(2, 700);
  //Cayenne.virtualWrite(3, 50, TYPE_PROXIMITY, UNIT_CENTIMETER);
}

// Default function for processing actuator commands from the Cayenne Dashboard.
// You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
  CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
  //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}

CAYENNE_IN(V5) {
  int buttonstate = (getValue.asInt());
  if (buttonstate == 1) {
    lcd.setCursor(5, 0);
    lcd.print("Welcome");

    delay(1000);
    lcd.clear();
  }
  else {
    lcd.setCursor(5, 0);
    lcd.print("Tag Not");
    lcd.setCursor(5, 1);
    lcd.print("Valid");
    delay(1000);
    lcd.clear();
  }

}
