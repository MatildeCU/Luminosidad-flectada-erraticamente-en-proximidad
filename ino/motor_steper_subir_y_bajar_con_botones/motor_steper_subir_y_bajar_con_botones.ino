#include <SoftwareSerial.h>

//Valores editables
int radio=10; // medida del radio del eje del motor en milimetros
int distancia= 100; // distancia de recorrido de la cuerda en milimetros
int duracion=10; // tiempo del recorrido en segundos, 10 para enrollar y 10 para desenrollar


const int stepPin = 5; // pin de conexión al arduino
const int dirPin = 11; // pin de conexión al arduino
const int enPin = 12; // pin de conexión al arduino

int unidadtiempo=(0.0455/radio); // constante dividida por el radio del eje del motor
int total= 50; // tiempo dividido por unidadtiempo
int perimetro=(2*PI*radio); // perímetro del espesor del eje del motor
int calculo1=(distancia/perimetro); // cálculo para saber cuantas vueltas debe dar el motor en una distancia determinada
int calculo2=(calculo1*1600); // cálculo 1 por 1600 (correspondiente a una vuelta del motor)

int aumentar = 7;  
int disminuir = 8; 

void setup() {
  Serial.begin(9600);
 pinMode(stepPin,OUTPUT);
 pinMode(dirPin,OUTPUT);
 pinMode(enPin,OUTPUT);
 digitalWrite(enPin,LOW);
pinMode(disminuir, OUTPUT);
  pinMode(aumentar, OUTPUT);
  digitalWrite(aumentar,LOW);
  digitalWrite(disminuir,LOW);

}
void loop() {
 digitalWrite(dirPin,HIGH); // sentido de giro del motor a la derecha
 if (digitalRead(aumentar) == HIGH)
 {
  Serial.println("aumentar");
 //for(int x = 0; x < calculo2; x++) { // ciclo for para mantener la duración del ciclo
 digitalWrite(stepPin,HIGH);
 delayMicroseconds(total);
 digitalWrite(stepPin,LOW);
 delayMicroseconds(total);
 //}
 }
 //delay(10); // un segundo de retraso
 
 digitalWrite(dirPin,LOW); // sentido de giro del motor a la izquierda
 if (digitalRead(disminuir) == HIGH)
 {
  Serial.println("disminuir");
 //for(int x = 0; x < calculo2; x++) {
 digitalWrite(stepPin,HIGH);
 delayMicroseconds(total);
 digitalWrite(stepPin,LOW);
 delayMicroseconds(total);
 //}
 }
 //delay(10); // un segundo de retraso
}
