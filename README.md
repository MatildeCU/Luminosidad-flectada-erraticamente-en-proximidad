# Documentación de un proyecto del Taller de Interacción

En este repositorio encontraras el desarrollo del uno de los proyectos del Taller de Diseño de Interacción del año 2022, de la Escuela de Arquitectura y Diseño. Desarrollado por las alumnas Valentina Dietz, Matilde Croxatto Ullrich y el alumno Andrés Aliaga Chandía. Aquí ordenamos la documentación de este proyecto para su exposición y posible re edicción ya que disponemos los archivos de corte para láser, códigos de arduino y otras informaciones necesarias.

## Observaciones de referencia

![Esta es una imagen](https://github.com/MatildeCU/Luminosidad-flectada-erraticamente-en-proximidad/blob/main/Ima/Totem%20M%C3%B3dulo%202%20Taller%20de%20Dise%C3%B1o%20de%20Interacci%C3%B3n%20Dibujo%20iso%20v1-01.jpg)

- Aproximación versátil desde el vacío expansivo al volumen próximo 
- Rodear sostenido del vacío 
- Apertura y recogimiento articulado en continuidad

## Acercamiento a la forma

## Proceso constructivo

- La luz

- Tela

- Hilos

- Mecanismos

- Arduino

- Motor Superior

- Diagrama

- Código

- Motor Inferior

- Diagrama 
- 
```
include <SoftwareSerial.h>
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
//Código
```

## Construcción Totem
/cad
/cam
## Estructura de carpetas
## Herramientas y tecnologías utilizadas

