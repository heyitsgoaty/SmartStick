#include <Ultr  asonic.h>
#include "pitches.h"
#define Trigger 13
#define Echo 12
#define parlante 3
#define tacto 8
#define vibrador 9
Ultrasonic U1(Trigger,Echo);

void setup() {
pinMode(parlante, OUTPUT);
pinMode(tacto, INPUT);
pinMode(vibrador, OUTPUT);
}

void loop() {

byte inicio;

inicio = digitalRead(tacto);

while(inicio == LOW) // Cuando el sensor de tacto detecte por primera vez la mano de algun dueño, empezara el programa a travez de un bucle infinito como es la funcion loop.
{
  evaluar_sensor();
  evaluar_distancia(); // esa es la tarea principal, evaluara la distancia a travez del sensor ultrasonico
}


}


void evaluar_distancia()
{  
  
float distance;

distance= U1.Ranging(CM);


if(distance<= 25 && distance>20 )
{
  analogWrite(vibrador, 170);
}

if(distance <=20 && distance>8 )
{
 analogWrite(vibrador, 190);
}

if(distance <=8 && distance >0 )
{
analogWrite(vibrador, 230);
}

else
{
  analogWrite(vibrador, 0);}

}

void evaluar_sensor()

{   byte evaluacion;
    analogWrite(vibrador, 0);
    delay(4000); // damos una espera de 3 seg, es por que a veces el ciego puede soltar para acomodar o sacar algun objeto
    evaluacion = digitalRead(tacto);
   if(evaluacion == HIGH ) //evaluamos si el sensor de dato este inactivo, osea ya no esta en contacto con la mano de su dueño

    {
      
       evaluacion = digitalRead(tacto); //evaluara nuevamente por si el palo sigue fuera de su lugar
       while(evaluacion== HIGH) //entramos otro bucle infinito, acabara si el palo regresa a la manos de su dueño.
           {
             tone(parlante, NOTE_C6);
             evaluacion =digitalRead(tacto);

           }
       noTone(parlante);
    }

    
}

