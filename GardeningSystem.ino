// include the library code:
#include <LiquidCrystal.h>
#include<dht.h>
dht DHT;
#define DHT11_PIN 6
const int VAL_PROBE = 0; //Analog pin 0
const int relay = 8;
const int relay2 = 9;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
Serial.begin(9600);
pinMode(VAL_PROBE , INPUT );
pinMode(relay , OUTPUT );
pinMode(relay2 , OUTPUT );
// set up the LCD's number of columns and rows:
lcd.begin(16, 2);
 // Print a message to the LCD.
lcd.print("Humidity" );
lcd.setCursor(0, 1);
lcd.print("temperature" );
Serial.println("ONLY FOR HUMIDITY");
 
}

void loop() {
////////////////////////////////////////////////////////// HUMIDITY&TEMP START
int chk = DHT.read11(DHT11_PIN);  
lcd.setCursor(9, 0);// set the cursor to column 0, line 1
lcd.print(DHT.humidity, 1);
lcd.setCursor(12, 1);
lcd.print(DHT.temperature, 1);
delay(2000);
/////////////////////////////////////////////////////// END

////////////////////////////////////////////////////////MOISTURE SENSOR START

int moisture = analogRead(VAL_PROBE);
Serial.println(moisture);
//delay(1000);
if (moisture <100) {

  Serial.println("WET");
  digitalWrite(relay,HIGH); //UNTUK LAMPU
  //delay(1000);
  
  }
else if( moisture>100 && moisture <900 ){
Serial.println("NORMAL");
digitalWrite(relay,LOW);
digitalWrite(relay2,LOW);
//delay(1000);

}

else if(moisture>900){
Serial.println("DRY");
 digitalWrite(relay2,HIGH);//UNTUK PAIP
//delay(1000);  
  }
/////////////////////////////////////////////////// END 
}

