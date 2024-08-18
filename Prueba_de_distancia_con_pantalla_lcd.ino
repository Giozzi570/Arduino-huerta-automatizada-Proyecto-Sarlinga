// Incluimos la libreria para la pantalla LCD
#include <LiquidCrystal.h>
// Definimos que puertos estamos utilizando
LiquidCrystal lcd(2,3,4,5,6,7);
// Declaramos variables
int TRIG = 9;
int ECHO = 8;
int DISTANCIA;
int DURACION;
String dis = "DISTANCIA:";


void setup() {
  // Definimos entradas,salidas y iniciamos el puerto Serial
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  Serial.begin(9600);
}

void loop() {
  // Prendermos el TRIGGER y lo apagamos para que cada 1 milisegundo mande una señal y el ECHO la reciba
  digitalWrite(TRIG,HIGH);
  delay(1);
  digitalWrite(TRIG,LOW);
  // Definimos que es duracion y lo dividimos entre 58.2 para que de la medidad en cm y que cada 250 milesimas de segundo mande el valor de la distancia actualizado
  DURACION = pulseIn(ECHO,HIGH);
  DISTANCIA = DURACION / 58.2;
  delay(250);
  // Ponemos en que linea va a estar el mensaje y hacemos que se desplaze desde la derecha a la izquierda y cada 500 milesimas de segundo cambie el valor de la DISTANCIA
  lcd.setCursor(5,0);
  lcd.print(dis);
  lcd.print(DISTANCIA);
  delay(500);
  lcd.scrollDisplayLeft();
  
}
