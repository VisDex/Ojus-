#define  trigPin 13
#define echoPin 12
#define buzzer 11
#define buzzer2 10
#define buzzer3 9
#define buzzer4 8
#define ledlight 7

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(buzzer3, OUTPUT);
  pinMode(buzzer4, OUTPUT);
  pinMode(ledlight, OUTPUT);
}void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 

  if (distance < 50) {
    digitalWrite(buzzer,HIGH); ;
  delay(100);
  }else {
    digitalWrite(buzzer,LOW);// ultrasonic sensor
  if (distance >= 400 || distance <= 0){
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }  } delay(500);
   if (analogRead(A0)<100){
digitalWrite(buzzer2,HIGH);
delay(50);
digitalWrite(buzzer2,LOW);
delayMicroseconds(10);}
else {digitalWrite(buzzer2,LOW);}// Step sensor
if (analogRead(A1)>70){
digitalWrite(buzzer3,HIGH);}
else {digitalWrite(buzzer3,LOW);}// heat sensor
if (analogRead(A4)>800){
digitalWrite(buzzer4,HIGH);
delay(200);
digitalWrite(buzzer4,LOW);
delayMicroseconds(100);}
else {digitalWrite(buzzer4,LOW);}// water sensor ok
if (analogRead(A5)>800){
digitalWrite(ledlight,HIGH); 
delay(50);
digitalWrite(ledlight,LOW);
delayMicroseconds(10);}
else {digitalWrite(ledlight,LOW);}}// light sensor ok