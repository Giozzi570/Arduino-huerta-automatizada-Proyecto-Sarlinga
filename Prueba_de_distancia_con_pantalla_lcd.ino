#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
int TRIG = 9;
int ECHO = 8;
int DISTANCIA;
int DURACION;
String dis = "DISTANCIA:";


void setup() {
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG,HIGH);
  delay(1);
  digitalWrite(TRIG,LOW);
  
  DURACION = pulseIn(ECHO,HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);
  delay(250);
  lcd.setCursor(5,0);
  lcd.print(dis);
  lcd.print(DISTANCIA);
  delay(500);
  lcd.scrollDisplayLeft();
  
}
