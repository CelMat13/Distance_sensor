#define trigPin 12
#define echoPin 11

void setup()
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(8, OUTPUT);// wyjście dla diody
}



void loop() 
{ 
  Serial.print(zmierzOdleglosc());
  Serial.println(" cm");

  zakres(0, 25);//włącz diodę, jeśli miedzy 10cm a 25 cos jest
  
  
  delay(500);
  

}

int zmierzOdleglosc()
{
  long czas, dystans;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;

  return dystans;
}

void zakres(int a, int b)
{
  int jakDaleko = zmierzOdleglosc();
  if ((jakDaleko > a) && (jakDaleko < b)) {
    digitalWrite(8, HIGH);//wlacz diode
  }else {
    digitalWrite(8, LOW);// wylacz diode
  }
}
