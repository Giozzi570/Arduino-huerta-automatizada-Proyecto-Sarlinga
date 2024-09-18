 codigo de pantalla lcd y sensores-botones
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>
#define DHTTYPE DHT11
#define sensorHumedad A0

// Definimos que puertos estamos utilizando
int led = 10;
int ledRojo = 9;
int STH = 8;   //Sensor Temperatura & Humedad
int valorHumedad = 0; 
LiquidCrystal lcd(2,3,4,5,6,7);

DHT dht(STH,DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  lcd.begin(16,2);
  dht.begin();
  pinMode(led,OUTPUT);
  pinMode(ledRojo,OUTPUT);
}


void loop() {
  float h = dht.readHumidity();       //Lee Humedad ambiente
    float t = dht.readTemperature();    //Lee Temperatura ambiente

    Serial.print("Humedad: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.print(" *C");
    Serial.println();
    delay(2000);
    int valorHumedad = map(analogRead(sensorHumedad),0 , 1023 , 100 ,0);
  if(valorHumedad>50){
    digitalWrite(led,HIGH);
    digitalWrite(ledRojo,LOW);
    }
    else{
      digitalWrite(ledRojo,HIGH);
      digitalWrite(led,LOW);
    }
  
  lcd.setCursor(5,0);
  lcd.print("HumedadGND:");
  lcd.print(valorHumedad);
  lcd.setCursor(5,1);
  lcd.print("TemperaturaENV:");
  lcd.print(t);
  lcd.setCursor(5,1);
  lcd.print("HumedadENV:");
  lcd.print(h);
  delay(500);
  lcd.scrollDisplayLeft();}


#include "DHT.h"

int BAP = 3;   //Botón Arranque/Parada
int BR = 4;    //Bomba Riego
int EV = 5;    //Electroválvula
int BMM = 6;   //Botón Marcha Motor
int M = 7;     //Motor
//int SAB = 8;   //Sensor Agua Bomba
int SHT = A0;  //Sensor Humedad Tierra
int STH = 9;   //Sensor Temperatura & Humedad


  {
  humedad = analogRead(A0);

 if(humedad>=721 && humedad<=1024){
   digitalWrite(Br,LOW);
 }
 else{
   digitalWrite(Br,HIGH);
 }
 Serial.println(humedad);
 delay(500);
  }
}
