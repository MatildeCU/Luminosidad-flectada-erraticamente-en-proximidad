int r2 = 3;
int g2 = 5;
int b2 = 6;

int r3 = 9;
int g3 = 10;
int b3 = 11;

int c1i = 7;
int c2i = 8;
int c3i = 12;
int c4i = 2;

void setup() {
  Serial.begin(9600);
  pinMode(r2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(g3, OUTPUT);
  pinMode(b3, OUTPUT);
  pinMode(c1i, INPUT);
  pinMode(c2i, INPUT);
  pinMode(c3i, INPUT);
  pinMode(c4i, INPUT);
  /*digitalWrite(c1d,LOW);
    digitalWrite(c1i,LOW);
    digitalWrite(c2d,LOW);
    digitalWrite(c2i,LOW);*/

}

void loop() {

  //arduino maestro-esclavo
  /*
     if (analogRead(A1) < 1){
      r = 3;
      g = 5;
      b = 6;
     }
     if (analogRead(A1) > 3){
      r = 9;
      g = 10;
      b = 11;
    }
  */
  //decrecer el delay al cambiar los colores

  if (digitalRead(c1i) == HIGH) {
    for (int d = 1000 ; d > 10 ; d --) {
      analogWrite(g, 200);
      delay(d);
      analogWrite(r, 200);
      delay(d);
      analogWrite(b, 200);
      delay(d);
      analogWrite(g, 200);
      delay(d);
    }
  }

  //aumento del color rojo

  if (digitalRead(c2i) == HIGH)
  {
    for (int i = 0 ; i < 256 ; i ++) { //rojo
      analogWrite(r, i);
      delay(100);
    }
  }

  //aumento del color azul

  if (digitalRead(c3i) == HIGH)
  {
    for (int i = 0 ; i < 256 ; i ++) { //azul
      analogWrite(b, i);
      delay(100);
    }
  }

  //crecer el delay al cambiar los colores

  if (digitalRead(c4i) == HIGH) {
    for (int d = 10 ; d < 1000 ; d ++) {
      analogWrite(b, 200);
      delay(d);
      analogWrite(g, 200);
      delay(d);
      analogWrite(r, 200);
      delay(d);
      analogWrite(b, 200);
      delay(d);
    }
  }


  else {
    for (int i = 0 ; i < 256 ; i ++) { //rojo
      analogWrite(r2, i);
      analogWrite(r3, i);
      analogWrite(g2, i);
      analogWrite(g3, i);
      analogWrite(b2, i);
      analogWrite(b3, i);
      delay(10);
    }
    for (int i = 256 ; i > 0 ; i --) {
      analogWrite(r2, i);
      analogWrite(r3, i);
      analogWrite(g2, i);
      analogWrite(g3, i);
      analogWrite(b2, i);
      analogWrite(b3, i);
      delay(10);
    }
  }

}
