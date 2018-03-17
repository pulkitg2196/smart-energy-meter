#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
#define pulse1 8
#define pulse2 9
#define pulse3 10
#define pulse4 11
int i;
float one_pulse=0.03125;


void setup()
{
  Serial.begin(9600);
pinMode(pulse1, INPUT);
pinMode(pulse2, INPUT);
pinMode(pulse3, INPUT);
pinMode(pulse4, INPUT);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("SmartElectricity");
lcd.setCursor(0,1);
lcd.print("     Meter");
delay(4000);
lcd.clear();

}

void loop()
{
   
 float Rupee=0,Unit=0;
 lcd.clear();
 while(1)
 {
  
  if(digitalRead(pulse1)==1)
  {
   i++;
   Unit=one_pulse*i/10;    
   Rupee=Unit*10;          
  
  }
  if(digitalRead(pulse2)==1)
  {
   i++;
   Unit=one_pulse*i/10;    
   Rupee=Unit*10;          
   
  }
  if(digitalRead(pulse3)==1)
  {
   i++;   
   Unit=one_pulse*i/10;                  
   Rupee=Unit*10;                        
   
  }
  if(digitalRead(pulse4)==1)
  {
   i++;   
   Unit=one_pulse*i/10;                  
   Rupee=Unit*10;                             
   }
lcd.setCursor(0,0);
lcd.print("Rupees: ");
lcd.print(Rupee);
lcd.setCursor(0,1);
lcd.print("Unit: ");
lcd.print(Unit);
Serial.println(Unit);
//Serial.println("\n");
Serial.println(Rupee);
delay(100);
}
}
