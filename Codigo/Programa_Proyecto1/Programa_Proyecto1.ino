#define P1A 10
#define P2A 11
#define EN12 9

void setup() {
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(P1A, OUTPUT);
  pinMode(P2A, OUTPUT);
  pinMode(EN12, OUTPUT);
}
 
void loop() {
  long duracion = 0;
  long distancia = 0;
  
  digitalWrite(12, LOW);//Trigger
  delayMicroseconds(4);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
 
  duracion = pulseIn(13, HIGH);
  duracion = duracion/2;
  distancia = duracion/29;
  
  delay(50);
  
  if (distancia <= 120){
    int Potencia;
    Potencia = map(distancia, 0, 120, 255, 70);
    digitalWrite(EN12 ,HIGH);
    analogWrite(P1A,Potencia);
    digitalWrite(P2A,LOW);
  }else{
    digitalWrite(EN12 ,HIGH);
    analogWrite(P1A,0);
    digitalWrite(P2A,LOW);
  }
}
