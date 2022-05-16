#include <LiquidCrystal.h>

LiquidCrystal lcd (12, 11, 5, 4, 3 ,2);

int LDR = A0;
int POT = A5;
int LED = 9;
int PV = 0;
int PtValue = 0;
int co = 0 ;
int var;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode (LED,OUTPUT);
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:

 PV = analogRead (LDR);
 PtValue = analogRead (POT);
 co = map(PtValue, 0, 1023, 0, 255);
 var = map(co, 0, 255, 0, 100);
 analogWrite(LED,co);
 Serial.print ("input =");
 Serial.print (PtValue);
 Serial.print ("\t co = ");
 Serial.print (co);
 Serial.print ("\t PV = ");
 Serial.print (PV);
 Serial.println ("");
 
 
lcd.setCursor(0,0);
lcd.print("PV;");
lcd.print (PV);
lcd.print("  ");
lcd.setCursor(0,1);
lcd.print("co;");
lcd.print (var);
lcd.print("%  ");
}
