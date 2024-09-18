codigo de pantalla lcd y sensores-botones
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>                                // Incluimos todas las librerias
#include <LiquidCrystal.h>
#define DHTTYPE DHT11
#define SHT A0
#define RELE_ON 0
// Son logica inversa por lo tanto se activan con 0 y se apagan con 1
#define RELE_OFF 1

// Definimos que puertos estamos utilizando
int ledBuenaH = 10;// Definimos el led que va a prender cuando haya buena humedad
int ledMalaH = 9;// Definimos el puerto al que va a ir la señal del arduino 
int releElectroValvula = 11; // Definimos el puerto al que va a ir la señal del Arduino 
int STH = 8;   //Sensor Temperatura & Humedad
int valorHumedad = 0; 
LiquidCrystal lcd(2,3,4,5,6,7);

DHT dht(STH,DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//Establece la velocidad de datos en bits por segundo para la transmisión de datos en serie
  lcd.begin(16,2);
  dht.begin();
  pinMode(releElectroValvula,OUTPUT);// Definimos el pin para que se comporte como una salida
  pinMode(led,OUTPUT);// Definimos el pin para que se comporte como una salida
  pinMode(ledRojo,OUTPUT);// Definimos el pin para que se comporte como una salida
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
    int valorHumedad = map(analogRead(SHT),0 , 1023 , 100 ,0);
   if(valorHumedad > 50){
    digitalWrite(ledRojo,HIGH);
    delay(1000);
    digitalWrite(ledRojo,LOW);
    digitalWrite(releElectroValvula,RELE_ON);
    Serial.println("Electrovalvula abierta");
    }
    else{
      digitalWrite(led,HIGH);
      delay(1000);
      digitalWrite(led,LOW);
      digitalWrite(releElectroValvula,RELE_OFF);
      Serial.println("Electrovalvula cerrada");
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
