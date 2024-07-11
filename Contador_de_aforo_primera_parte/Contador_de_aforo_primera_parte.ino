/*
 
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Contador de aforo
   Dev: Hugo Alexander Reyes Veliz 
   Fecha: 11/7/2024
*/





#include <Adafruit_NeoPixel.h>

int pines[] = {5, 6, 7, 8, 9, 10, 11};  

Adafruit_NeoPixel anillo(1, 4, NEO_GRB + NEO_KHZ800); 
long sensor;
long distancia; 
int contadorpersonas = 0;

void setup() {
  pinMode(2, OUTPUT); 
  pinMode(3, INPUT);  
  digitalWrite(2, LOW); 
  Serial.begin(9600);
  anillo.begin();
  
  for (int i = 0; i < 7; i++) {
    pinMode(pines[i], OUTPUT);
  
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      digitalWrite(10,HIGH); 
  }
}

void loop() {
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  sensor = pulseIn(3, HIGH);
  distancia = sensor / 59;
  
  if (distancia >= 6 && distancia <= 9) {
    delay(1000);
    anillo.setPixelColor(0, anillo.Color(124, 252, 0));
    anillo.show();
    mostrarNumero(contadorpersonas); 
    delay(1000);
    
    
    if (contadorpersonas < 10) {
    contadorpersonas++; 
    }
  }
  
    if (contadorpersonas >= 10) {
    anillo.setPixelColor(0, anillo.Color(255, 0, 0));
    anillo.show();
    digitalWrite(11, HIGH); 
  } else
    
    delay(100);  
}


void mostrarNumero(int numero) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(pines[i], LOW);
  }
  
  switch (numero) {
    
    case 1:
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      break;
    
    case 2:
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH);
      digitalWrite(11,HIGH);
 
      break;
    
    case 3:
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(11,HIGH); 
      break;
    
    case 4:
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(10,HIGH); 
      digitalWrite(11,HIGH); 
      break;
    
    case 5:
      digitalWrite(5, HIGH);  
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);  
      break;
    
    case 6:
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(9, HIGH); 
      digitalWrite(10,HIGH);  
      digitalWrite(11,HIGH);  
      break;
    
    case 7:
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH); 
      break;
    
    case 8:
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH); 
      digitalWrite(10,HIGH); 
      digitalWrite(11,HIGH); 
      break;
    
    case 9:
      digitalWrite(5, HIGH);  
      digitalWrite(6, HIGH);  
      digitalWrite(7, HIGH);  
      digitalWrite(10,HIGH);  
      digitalWrite(11,HIGH); 
      break;
   
  }
}
