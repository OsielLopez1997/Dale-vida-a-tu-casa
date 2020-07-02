int pinlight = A0, luz; // Pin del LDR.
int led10 = 10; // Pin del Led.

void setup() 
{
  pinMode ( led10, OUTPUT);// Configuración del led.
}

void loop() 
  {
  luz = analogRead( pinlight); // Lectura de la intensidad de luz del sensor de luz.
  if (luz > 400) // Si el valor es superior a 400
  {
    digitalWrite ( led10, LOW); // Led se apaga.
  }
  else // SI ES MAS PEQUEÑO DE 400
  {
    digitalWrite ( led10, HIGH); // Led se enciende.
  }
}
