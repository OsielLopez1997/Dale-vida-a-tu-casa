#define pot A0 //Pin del Pot.
#define led 9//Pin del led.
int dato;

void setup()
{
  pinMode(led, OUTPUT); //Configurado el pin especificado para que se comporte como salida.
  pinMode(pot, INPUT);  //Configurado el pin especificado para que se comporte como entrada.
}

void loop()
{
dato = analogRead(pot); //Lee la entrada analógica del pot.
dato = dato/4; //Se divide para obetener un número entre 0 y 255.
analogWrite(led, dato);//Enviar el valor del dato al led.
}
