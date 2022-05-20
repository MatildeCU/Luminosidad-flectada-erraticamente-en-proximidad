int r1 = 3;
int g1 = 5;
int b1 = 6;

int r4 = 9;
int g4 = 10;
int b4 = 11;

int c1d = 7;
/*int c2d = 8; //disminuir
  int c3d = 2; //aumentar*/
int c4d = 1;

//MOTOR
int radio = 10; // medida del radio del eje del motor en milimetros
int distancia = 1300; // distancia de recorrido de la cuerda en milimetros
int duracion = 10; // tiempo del recorrido en segundos, 10 para enrollar y 10 para desenrollar
const int stepPin = 2; // pin de conexión al arduino
const int dirPin = 4; // pin de conexión al arduino
const int enPin = 12; // pin de conexión al arduino

int unidadtiempo = (0.0455 / radio); // constante dividida por el radio del eje del motor
int total = 200; // tiempo dividido por unidadtiempo
int perimetro = (2 * PI*radio); // perímetro del espesor del eje del motor
int calculo1 = (distancia / perimetro); // cálculo para saber cuantas vueltas debe dar el motor en una distancia determinada
int calculo2 = (calculo1 * 1600); // cálculo 1 por 1600 (correspondiente a una vuelta del motor)


void setup()
{
  Serial.begin (9600);
  pinMode(r1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(c1d, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(g4, OUTPUT);
  pinMode(b4, OUTPUT);
  pinMode(c4d, OUTPUT);

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);

  digitalWrite(c1d, LOW); //aumentar
  digitalWrite(c4d, LOW); //disminuir

}

void loop()
{
  if (digitalRead(c4d) == HIGH) 
  {
    Serial.println("disminuir");
    digitalWrite(dirPin, HIGH);
    for (int x = 0; x < calculo2; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(total);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(total);
    }
  }

  digitalWrite(c1d, LOW);
  if (digitalRead(c1d) == HIGH) {
    Serial.println("aumentar");
    digitalWrite(dirPin, HIGH);
    for (int x = calculo2; x > 0; x--) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(total);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(total);
     }
  }

  else {
    for (int i = 0 ; i < 256 ; i ++) {
      analogWrite(r1, i);
      analogWrite(r4, i);
      analogWrite(g1, i);
      analogWrite(g4, i);
      analogWrite(b1, i);
      analogWrite(b4, i);
      delay(10);
    }
    for (int i = 256 ; i > 0 ; i --) {
      analogWrite(r1, i);
      analogWrite(r4, i);
      analogWrite(g1, i);
      analogWrite(g4, i);
      analogWrite(b1, i);
      analogWrite(b4, i);
      delay(10);
    }


  }
}
