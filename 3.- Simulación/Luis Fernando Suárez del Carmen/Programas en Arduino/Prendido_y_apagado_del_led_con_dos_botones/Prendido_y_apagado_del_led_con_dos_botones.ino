int LED = 5; //Pin del Led.
int PULL1 = 4;//Pin del pulsador 1.
int PULL2 = 3;//Pin del pulsador 2.

void setup()
{
  pinMode (LED, OUTPUT); // Salida de la señal para prender el led.
  pinMode (PULL1, INPUT);//Pulsador como entrada 1.
  pinMode (PULL2, INPUT);//Pulsador como entrada 2.
}

void loop()
{
  if (digitalRead(PULL1)==HIGH)//Se pulsa el boton 1 para encender el led.
  {
    digitalWrite(LED, HIGH);// El led enciende.
  }
  if (digitalRead (PULL2)==HIGH)//Se pulsa el boton 2 para apagar el led.
  {
    digitalWrite(LED, LOW);//El led se apaga.
  }
}
