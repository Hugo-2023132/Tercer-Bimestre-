/*
 
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Identificación por radio frecuencia
   Dev: Hugo Alexander Reyes Veliz 
   Fecha: 11/7/2024
*/


#include <SPI.h>
#include <MFRC522.h>


#define RST_PIN  9    // configuramos el pin 9 para resent del MFRC522
#define SS_PIN   10   //
#define ledVerde 4   // led verde en el pin 4
#define ledRojo  5   // led rojo en el pin 5
#define Buzzer 3 

MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;  

//codigo de la tarjeta
byte tag1[4]= {0xC3, 0x20, 0xD7, 0x1C};

byte tagActual[4]; // almacena el UID de la tarjeta acutal 

void setup(){
  Serial.begin(9600);  
  while(!Serial); // Comprobar si ya ha iniciado 
  SPI.begin(); // iniciar la comunicación SPI 
  mfrc522.PCD_Init(); // Inicia la comunicación con el mudulo RFID
  pinMode(ledVerde,OUTPUT); // Configura el led verde como salida
  pinMode(ledRojo, OUTPUT); // Configura el led rojo como salida 
  
 
}

void loop(){
  if(!mfrc522.PICC_IsNewCardPresent()) // comprobar si esta presente la tarjeta 
  return;

  if(!mfrc522.PICC_ReadCardSerial()) // leer la tarjeta 
  return;

  Serial.print(F("Card UID:"));
   dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size); // obtiene los valores leidos de la tarjeta 

  digitalWrite(ledVerde, LOW); // apagar los leds 
  digitalWrite(ledRojo,  LOW);
}

void dump_byte_array(byte *buffer, byte bufferSize) { // realiza la lectura del codigo de la tarjeta y comprueba 
  for( byte i = 0; i < bufferSize; i++){ // extrae los valores del codigo 
    Serial.print(buffer[i] < 0x10 ? "0" : " ");
    Serial.print(buffer[i], HEX);
    tagActual[i]=buffer[i];
  }

  if (compararArray(tagActual,tag1)){ // comprobar el acceso 
    Serial.println("Aceso Permitido");
    digitalWrite(ledVerde,HIGH);
    tone(Buzzer, 200);
    delay(4000);
    noTone(Buzzer);
  }
  else{
    Serial.println(" Aceso Denegado ");  // si el codigo no esta registrado denegar acceso 
    digitalWrite(ledRojo,HIGH);
    tone(Buzzer, 400); 
    delay(4000);
    noTone(Buzzer);

  }
}

boolean compararArray(byte Array1[], byte Array2[]){ // compara codigo leido  con el registrado previamente 

  if(Array1[0] != Array2[0]) return(false);
  if(Array1[1] != Array2[1]) return(false);
  if(Array1[2] != Array2[2]) return(false);
  if(Array1[3] != Array2[3]) return(false);
  return(true);
  
}
