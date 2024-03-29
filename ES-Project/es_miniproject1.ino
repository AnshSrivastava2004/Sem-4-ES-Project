#include<LiquidCrystal.h>

int sensorPin = 0;
int led = 12;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(13,OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

float voltage;
float temperatureC;
int reading;

void read() {
   	reading = analogRead(sensorPin);
 // measure the 5v with a meter for an accurate value
 //In particular if your Arduino is USB powered
  	voltage = reading * 4.99;
 	voltage /= 1024.0;
 // now print out the temperature
  	temperatureC = (voltage - 0.5) * 100;
}

void displaytemp()  {
	lcd.clear();
	lcd.setCursor(0, 0);

    String display = "Temperature: ";
  	lcd.print(display);
  	delay(100);
  	lcd.setCursor(0,1);
    lcd.print(temperatureC);
  	lcd.print(" C");
  
  	delay(250);
}

void blinkLED() {
	digitalWrite(led, HIGH);
  	delay(500); 
  	digitalWrite(led, LOW);
  	delay(500);
}

void loop() {
  	read();
	Serial.print(temperatureC);
 	Serial.println(" C");
  
  	while(temperatureC > 5){
  		tone(13,250,250);
    	read();
    	displaytemp();
     	blinkLED();
        lcd.print(temperatureC);
  	lcd.print(" C");
    }
  
  	displaytemp();

 	delay(1000);
	  	digitalWrite(led, LOW);

}
 

