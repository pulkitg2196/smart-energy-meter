#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
#define pulse 13
int i,Pulse;
float one_pulse=0.3125;


void setup()
{
  Serial.begin(9600);
pinMode(pulse, INPUT);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("SmartElectricity");
lcd.setCursor(0,1);
lcd.print("   Meter");
delay(4000);
lcd.clear();

}

void loop()
{
   int Pulse=0;
 float Rupee=0,Unit=0;
 lcd.clear();
 while(1)
 {
  if(digitalRead(pulse))
  {
   i++;
   Pulse++;
   Unit=one_pulse*i/10;                  // unit is defined
   Rupee=Unit*10;                             // unit rate is defined
   while(digitalRead(pulse));
  }


lcd.setCursor(0,0);
lcd.print("Rupee: ");
lcd.print(Rupee);
lcd.setCursor(0,1);
lcd.print("Unit: ");
lcd.print(Unit);
Serial.println(Unit);
Serial.println("\n");
Serial.println(Rupee);
delay(10);
}
}
