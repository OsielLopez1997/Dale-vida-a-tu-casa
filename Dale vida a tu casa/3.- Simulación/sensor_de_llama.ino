int led = 11;
int valorSensor =0;
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop()
{
  valorSensor = analogRead(A0);
  Serial.println(valorSensor);
  if (valorSensor < 500)
  {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(50);
  }
}
