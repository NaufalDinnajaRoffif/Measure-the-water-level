#define TRIGPIN 9
#define ECHOPIN 8

#define LEDPIN1 13
#define LEDPIN2 12

long timer;
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);

  pinMode(LEDPIN1, OUTPUT);
  pinMode(LEDPIN2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  timer = pulseIn(ECHOPIN, HIGH);
  distance = timer/58;
  delay(100);

  digitalWrite(LEDPIN2, HIGH);

  if(distance > 0 && distance <= 2){
    digitalWrite(LEDPIN1, HIGH);
    digitalWrite(LEDPIN2, LOW);
  }else if(distance > 4 && distance <= 6){
    digitalWrite(LEDPIN1, LOW);
    digitalWrite(LEDPIN2, HIGH);
  }else{
    digitalWrite(LEDPIN1, LOW);
    digitalWrite(LEDPIN2, LOW);
  }

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.println();
}
