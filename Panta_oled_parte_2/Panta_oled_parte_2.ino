
/*
 
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Pantalla Oled
   Dev: Hugo Alexander Reyes Veliz 
   Fecha: 18/7/2024
*/





#include <Wire.h>             //libreria que me permite usar el protocolo i2c
#include <Adafruit_GFX.h>     //libreria que me permite el uso de graficos en la pantalla oled
#include <Adafruit_SSD1306.h> //libreria que me permite el uso del controlador de la pantalla OLED

//Directivas del preprocesador
#define widht_oled    128       
#define height_oled   64        
#define pot_pin       A0        

Adafruit_SSD1306 oled_display(widht_oled,height_oled,&Wire, -1);

unsigned int adc_valor;


void setup() 
{
 Serial.begin(9600);  
 delay(100);          
 Serial.println("Uso de la pantalla oled");
 pinMode(A0, INPUT);

 //Inicio la comunicacion con la pantalla OLEC

 if(!oled_display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
 {
  Serial.println("No puedo comunicarme con la pantalla oled");
  Serial.println("Favor de revisar conexiones o alimentacion");
  while(1);  
 }

 oled_display.setTextSize(4);
 
 //Defino el color del texto a imprimir (la pantalla es monocromatica)
 oled_display.setTextColor(SSD1306_WHITE);
 
 //Coloco el cursor en una posicion especifica
 oled_display.setCursor(0, 0);
 
 //Imprimo la cadena de texto
 oled_display.println("Hugo Reyes");
 oled_display.display();
}


void loop() 
{
  
 oled_display.setTextSize(2);
 
 //Defino el color del texto a imprimir (la pantalla es monocromatica)
 oled_display.setTextColor(SSD1306_WHITE);
 
 //Coloco el cursor en una posicion especifica
 oled_display.setCursor(0, 0);
 
 //Imprimo la cadena de texto
 oled_display.println("Valor del ADC");
 
 //Muestro en pantalla la cadena 
 oled_display.display();
  adc_valor = analogRead(A0);       //leo el valor del canal 0 del ADC
  Serial.print("El valor del ADC es de: ");
  Serial.println(adc_valor);
  oled_display.setTextSize(3);
  oled_display.setTextColor(SSD1306_WHITE);
  oled_display.setCursor(40,20);
  oled_display.println(adc_valor);
  oled_display.display();
  delay(150);
  oled_display.clearDisplay();
}
