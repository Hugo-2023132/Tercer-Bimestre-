#include <LedControl.h> // Libreria que me permita usar el IC MAX7219 (matriz led)

#define din_matrix 3 // pin3 del arduino conectado al pin DIN de la mtriz de led
#define cs_matrix  2 // pin2 del arduino conectado al pin CS de la mtriz de led
#define clk_matrix 4 // pin4 del arduino conectado al pin CLK de la mtriz de led
#define ch_A0 A0

int valor = 0;
int tiempo_espera;

LedControl PacmanMatrix = LedControl(din_matrix, clk_matrix, cs_matrix,1);

// variables
byte pacman_boca_abierta[8] = {
B00111100,
B01000010,
B10000100,
B10001000,
B10001000,
B10000100,
B01000010,
B00111100
};

byte pacman_boca_cerrada[8] = { 
B00111100,
B01000010,
B10000001,
B10000001,
B10001111,
B10000001,
B01000010,
B00111100,

};

void setup(){
 Serial.begin(9600);
 PacmanMatrix.shutdown(0, false); 
 PacmanMatrix.setIntensity(0, 15);
 PacmanMatrix.clearDisplay(0);
 Serial.println("uso de la matriz led");
 
  
}

void loop(){
 valor = analogRead(ch_A0);   
 tiempo_espera = map(valor,0,1023,50,1500);
 Pacmanabierto();
 delay(tiempo_espera);
 Pacmancerrado();
 delay(tiempo_espera);
 

}


void Pacmanabierto(){
for(int i=0; i<8; i++)
 {
 PacmanMatrix.setRow(0,i,pacman_boca_abierta[i]);
 }  
}


void Pacmancerrado(){
for(int i=0; i<8; i++)
 {
 PacmanMatrix.setRow(0,i,pacman_boca_cerrada[i]);
 }  
}
  
