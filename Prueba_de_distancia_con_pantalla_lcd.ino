int IN1 = 6;
int IN2 = 7;
const int BotonHorario=2;
const int BotonAntiHorario=3;
int val;
int valor;
void setup(){
pinMode(BotonHorario,INPUT);
pinMode(BotonAntiHorario,INPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);

Serial.begin(9600);
}
void loop(){
val=digitalRead(BotonHorario);
if  (val==HIGH){
Serial.println("BotonHorario = 1");
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
delay(2000);
}
else {
Serial.println("BotonHorario = 0");
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
}

valor=digitalRead(BotonAntiHorario);
if   (valor==HIGH){
Serial.println("BotonAntiHorario = 1");
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
delay(2000);
}
else {
Serial.println("BotonAntiHorario = 0");
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
}
}
