#include <ESP32Servo.h>

Servo miMenique;
Servo miAnular;
Servo miMedio;
Servo miIndice;
Servo miPulgar;

#define menique 27
#define anular 26
#define medio 25
#define indice 33
#define pulgar 32


String output27State = "off";
String output26State = "off";
String output25State = "off";
String output33State = "off";
String output32State = "off";

const int output26 = 26;
const int output27 = 27;
const int output25 = 25;
const int output33 = 33;
const int output32 = 32;



void setup() {
  miMenique.attach(menique);
  miMenique.write(0);       
  miAnular.attach(anular);
  miAnular.write(0); 
  miMedio.attach(medio);
  miMedio.write(15); 
  miIndice.attach(indice);
  miIndice.write(15); 
  miPulgar.attach(pulgar);
  miPulgar.write(15);   
} 

void mano_cerrada(){
  miMenique.write(15);
  miAnular.write(15);
  miMedio.write(15);
  miIndice.write(0); 
  miPulgar.write(0); 

  delay(3000);
  
}

void mano_abierta(){
  miMenique.write(0);
  miAnular.write(0);
  miMedio.write(0);
  miIndice.write(15); 
  miPulgar.write(15); 

  delay(3000);
  
}

void dedo_1a1(){
  miMenique.write(20);
  delay(1000);
  miAnular.write(20);
  delay(1000);
  miMedio.write(0);
  delay(1000);
  miIndice.write(0); 
  delay(1000);
  miPulgar.write(0); 
  delay(2000);

  miMenique.write(0);
  delay(1000);
  miAnular.write(0);
  delay(1000);
  miMedio.write(20);
  delay(1000);
  miIndice.write(20); 
  delay(1000);
  miPulgar.write(20); 
  
  delay(3000);
}



void loop(){
  dedo_1a1();
}