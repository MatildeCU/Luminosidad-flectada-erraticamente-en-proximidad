# Documentación de un proyecto del Taller de Interacción

En este repositorio encontraras el desarrollo del uno de los proyectos del Taller de Diseño de Interacción del año 2022, de la Escuela de Arquitectura y Diseño. Desarrollado por las alumnas Valentina Dietz, Matilde Croxatto Ullrich y el alumno Andrés Aliaga Chandía. Aquí ordenamos la documentación de este proyecto para su exposición y posible re edicción ya que disponemos los archivos de corte para láser, códigos de arduino y otras informaciones necesarias.

## Observaciones de referencia

![Esta es una imagen](https://github.com/MatildeCU/Luminosidad-flectada-erraticamente-en-proximidad/blob/main/Ima/Totem%20M%C3%B3dulo%202%20Taller%20de%20Dise%C3%B1o%20de%20Interacci%C3%B3n%20Dibujo%20iso%20v1-01.jpg)

- Aproximación versátil desde el vacío expansivo al volumen próximo 
- Rodear sostenido del vacío 
- Apertura y recogimiento articulado en continuidad

## Acercamiento a la forma

Se conversó como grupo sobre las diversas observaciones y encuentros que tuvimos, llegando a una observación por cada uno, que guiará la propuesta final del totem. Se determinó el concepto de proximidad como uno de estos, por lo cual unos de los inputs del Tótem es un sensor de ultra sonido el cual mide la distancia de un objeto enviando y recibiendo señales sonoras. La segunda característica observada es lo errático, aquello es expresado el en el movimiento de dentro del Tótem, el cual se efectuará mediante un motor activado por los sensores ultrasónicos. Este movimiento será expresado por una tela al interior del objeto. Luz Flectada es aquello que se logró en la unión se estos conceptos.

Además se presentarán dos output con máximos y mínimos, la intensidad de las luces manejadas con botones ubicados en los laterales del Tótem y la altura en desplazamiento de estas. Esto ya que se dispondrán ocho botones en total, cada cara contará con dos, los cuales se podrán activar en pares o individualmente. Cara placa con los botones estará en distintas alturas, así se tendrá que disponer el cuerpo a estirarse o a recogerse para activarlos.

### A escala menor
Partimos probando cilindros de tela que se van recogiendo mientras se proyecta la textura de estos mismos en contraluz. La luz central se va controlando manualmente en búsqueda de pruebas; subir y bajar, acercarse y alejarse, etc. A partir de estas pruebas van apareciendo distintas proyecciones en el espacio, de las cuales podemos rescatar algunas más interesantes que otras. La luz se hace parte relevante en la proyección cuando ambas telas se superponen en movimiento y la fuente luminica se va acercando a la "arruga".

![Esta es una imagen](Construccion_escala_menor_totem_MVA_pruebas_constructivas_(2).jpg)
![Esta es una imagen]()
![Esta es una imagen]()

## Proceso constructivo

Comenzamos realizando las pruebas a escala 1:1. en donde pudimos replicar de cierta manera lo descubierto en el movimiento de las telas, pero esta vez a través de hilos. En donde los hilos integrados a la tela arrugan esta misma para ir formando distintas texturas dentro del espacio en contraluz.

- La luz
![Esta es una imagen](500px-Luz_flectada_MVA.png)
![Esta es una imagen](500px-Luz_flectada_mva_2.png)
![Esta es una imagen](600px-Luz_totem_MVA_(1).jpg)
![Esta es una imagen](600px-Luz_totem_MVA_(12.png)
![Esta es una imagen](600px-Luz_totem_MVA_(2).jpg)
![Esta es una imagen](600px-Luz_totem_MVA_(3).jpg)

- Tela
![Esta es una imagen](500px-Pruebas_tela_escala_real_mva_(2).png)
![Esta es una imagen](Hilos_tela_mva_2.png)

- Hilos
![Esta es una imagen](600px-Hilos_tela_mva.jpg)
![Esta es una imagen]()


- Mecanismos
![Esta es una imagen](600px-Mecanismo_tela_hilos_mva.jpg)
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

![Esta es una imagen](800px-Totem_escala_real_terminado.jpg)
![Esta es una imagen]()
/cad
/cam
## Estructura de carpetas
## Herramientas y tecnologías utilizadas

