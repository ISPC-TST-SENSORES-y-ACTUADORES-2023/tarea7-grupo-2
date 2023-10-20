#include <LiquidCrystal.h>
#include "DHT.h" //Librería DHT11_22
DHT dht(2, DHT22); //

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

float xhumedad = 0;
float xtemperatura =0;
float xhumedadAux = 101;
float xtemperaturaAux =81;

void setup() {
  dht.begin(); 
  pinMode(A0, INPUT);


  lcd.begin(20, 4); // Inicializar el LCD con el número de  columnas y filas del LCD
  lcd.setCursor(5,0);
  lcd.print("Sensores");
  lcd.setCursor(8,1);
  lcd.print("y");
  lcd.setCursor(5,2);
  lcd.print("Actuadores");
  lcd.setCursor(5,3);
  lcd.print("Trabajo # 7");
  delay(3000);
  lcd.clear();
  }

void loop() {

  xhumedad = dht.readHumidity(); //Leer humedad
  xtemperatura = dht.readTemperature(); //Leer temperatura    

         if ((xhumedad != xhumedadAux) || (xtemperatura != xtemperaturaAux))
          {
                xhumedadAux = xhumedad;   
                xtemperaturaAux =xtemperatura;
                lcd.print("Humedad:"); 
                lcd.setCursor(9,0);
                lcd.print(xhumedadAux);
                lcd.setCursor(14,0);
                lcd.print("%"); 

                lcd.setCursor(0,2);
                lcd.print("Temperatura: ");
                lcd.setCursor(13,2);
                lcd.print(xtemperaturaAux);
                lcd.setCursor(19,2);
                lcd.print("C");
                lcd.setCursor(0,0);
               
                
          }
 }