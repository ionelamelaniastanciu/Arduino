#include "Arduino.h"
#include "DHT.h"
#include "LiquidCrystal_PCF8574.h"

#define DHT_PIN_DATA	2

#define LCD_ADDRESS 0x3F
//#define LCD_ADDRESS 0x27
// Define LCD characteristics
#define LCD_ROWS 2
#define LCD_COLUMNS 16
#define SCROLL_DELAY 150
#define BACKLIGHT 255

DHT dht(DHT_PIN_DATA,11);
LiquidCrystal_PCF8574 lcdI2C;

void setup() 
{   
    dht.begin();
    lcdI2C.begin(LCD_COLUMNS, LCD_ROWS, LCD_ADDRESS, BACKLIGHT);     
    lcdI2C.write("  Buna!  ");  
    
}

void loop() 
{
    lcdI2C.clear();
    float dhtHumidity = dht.readHumidity();
    float dhtTempC = dht.readTempC();

    char temperatura[4];    
    dtostrf(dhtTempC, 4, 2, temperatura);
    
    lcdI2C.write("Temp ");
    lcdI2C.write(temperatura);
    lcdI2C.write("[C]"); 
    
    lcdI2C.selectLine(2);   
    char umiditate[4];    
    dtostrf(dhtHumidity,4, 2, umiditate);  
    lcdI2C.write("Umid ");
    lcdI2C.write(umiditate);
    lcdI2C.write("[%]");    
    
    delay(10000);
   
}
