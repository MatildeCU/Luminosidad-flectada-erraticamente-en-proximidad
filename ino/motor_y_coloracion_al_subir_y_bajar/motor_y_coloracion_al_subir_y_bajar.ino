int r1 = 3;
int g1 = 5;
int b1 = 6;

int r4 = 9;
int g4 = 10;
int b4 = 11;

int c1d = 7;
int c2d = 8; //disminuir
int c3d = 2; //aumentar
int c4d = 1;

int radio = 10; // medida del radio del eje del motor en milimetros
int distancia = 1000; // distancia de recorrido de la cuerda en milimetros
int duracion = 40; // tiempo del recorrido en segundos, 10 para enrollar y 10 para desenrollar
const int stepPin = 2; // pin de conexión al arduino
const int dirPin = 4; // pin de conexión al arduino
const int enPin = 12; // pin de conexión al arduino

int unidadtiempo = (0.0455 / radio); // constante dividida por el radio del eje del motor
int total = 50; // tiempo dividido por unidadtiempo
int perimetro = (2 * PI*radio); // perímetro del espesor del eje del motor
int calculo1 = (distancia / perimetro); // cálculo para saber cuantas vueltas debe dar el motor en una distancia determinada
int calculo2 = (calculo1 * 1600); // cálculo 1 por 1600 (correspondiente a una vuelta del motor)

void setup() {

  Serial.begin(9600);
  pinMode(r1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(g4, OUTPUT);
  pinMode(b4, OUTPUT);
  pinMode(c1d, OUTPUT); //ciclo for cambio colores
  pinMode(c2d, OUTPUT); //disminuir
  pinMode(c3d, OUTPUT); //aumentar
  pinMode(c4d, OUTPUT); //color random

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);

  digitalWrite(c2d, LOW); //disminuir
  digitalWrite(c3d, LOW); //aumentar
  randomSeed(analogRead(c4d)); //random colores

}

void loop() {


  //MOTOR
  // DISMINUIR sentido de giro del motor a la izquierda
  digitalWrite(dirPin, LOW);

  Serial.println("disminuir");
  for (int x = 0; x < calculo2; x++) {
    /* int l = map(x, 0, 104000, 0, 255);
      analogWrite(r1, l);
      analogWrite(r4, l);
      analogWrite(g1, l);
      analogWrite(g4, l);
      analogWrite(b1, l);
      analogWrite(b4, l);
    */digitalWrite(c1d, LOW);
    if (analogRead(c1d) == HIGH) {
    }
    
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(total);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(total);
  }
  // AUMENTAR sentido de giro del motor a la derecha
  digitalWrite(dirPin, HIGH);

  Serial.println("aumentar");
  for (int x = calculo2; x > 0; x--) {
    int l = map(x, 0, 104000, 0, 250);
    analogWrite(r1, l);
    analogWrite(r4, l);
    analogWrite(g1, l);
    analogWrite(g4, l);
    analogWrite(b1, l);
    analogWrite(b4, l);
    if (digitalRead(c1d) == HIGH) {

    }
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(total);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(total);
  }


}

/*// COLOR RANDOM
  //cambio de color de manera azarosa cada vez que se activa
  int vf = 0;
  vf = digitalRead(c4d);
  if (vf) {
  float col1 = random(0, 255);
  float col2 = random(0, 255);
  float col3 = random(0, 255);
  Serial.print("entro");
  analogWrite(r4, col1);
  analogWrite(g4, col2);
  analogWrite(b4, col3);
  delay(1000);

  }
  else {
  analogWrite(r4, 0);
  analogWrite(g4, 0);
  analogWrite(b4, 0);
  delay(100);

  }*/
