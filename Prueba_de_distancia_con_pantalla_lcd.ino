#define sensor A05
int led = 10;
int ledRojo = 9;
#include <LiquidCrystal.h>
// Definimos que puertos estamos utilizando
LiquidCrystal lcd(12,11,5,4,3,2);
int valorHumedad = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  lcd.begin(16,2);
  pinMode(led,OUTPUT);
  pinMode(ledRojo,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  int valorHumedad = map(analogRead(sensor),0 , 1023 , 100 ,0);
  if(valorHumedad>50){
    digitalWrite(led,HIGH);
    digitalWrite(ledRojo,LOW);
    }
    else{
      digitalWrite(ledRojo,HIGH);
      digitalWrite(led,LOW);
    }
  
  lcd.setCursor(5,0);
  lcd.print("Humedad:");
  lcd.print(valorHumedad);
  lcd.setCursor(5,1);
  lcd.print("Temperatura:");
  lcd.print(valorHumedad);
  delay(500);
  lcd.scrollDisplayLeft();
