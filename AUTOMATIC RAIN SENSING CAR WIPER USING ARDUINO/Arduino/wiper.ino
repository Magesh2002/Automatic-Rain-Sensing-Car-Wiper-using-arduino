#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
Servo myservo; 

int pos = 0; 
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  myservo.attach(9);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   AUTOMATIC "); 
  lcd.setCursor(0,1);
  lcd.print("   CAR WIPER ");
  delay(5000); 
}

void loop() 
{
sensorValue = analogRead(A0);
Serial.println(sensorValue);
if(sensorValue>800){
  myservo.write(180);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("    NO RAIN ");
  delay(1000);
  }
if(sensorValue<=800 && sensorValue>600){
  lcd.print("AMOUNT: LOW ");
  lcd.setCursor(0,0);
  lcd.print("IT IS RAINING
  ");
  lcd.setCursor(0,1);
  for (pos = 180; pos >= 0; pos-=1) {
    myservo.write(pos);            
    delay(3);                    
  }
  for (pos = 0; pos <= 180; pos+=1) { 
    myservo.write(pos);             
    delay(3);        
  }
  delay(2000);
}

if(sensorValue<=600 && sensorValue>460){
  lcd.setCursor(0,0);
  lcd.print("IT IS RAINING   ");
  lcd.setCursor(0,1);
  lcd.print("AMOUNT: MEDIUM ");
  for (pos = 180; pos >= 0; pos-=1) {
    myservo.write(pos);            
    delay(3);                   
  }
  for (pos = 0; pos <= 180; pos+=1) { 
    myservo.write(pos);             
    delay(3);        
  }
  delay(1000);
}

if(sensorValue<460){
  lcd.setCursor(0,0);
  lcd.print("IT IS RAINING   ");
  lcd.setCursor(0,1);
  lcd.print("AMOUNT: HIGH    ");
  for (pos = 180; pos >= 0; pos-=1) {
    myservo.write(pos);            
    delay(3);                    
  }
  for (pos = 0; pos <= 180; pos+=1) { 
    myservo.write(pos);             
    delay(3);        
  }
  delay(100);
}

}