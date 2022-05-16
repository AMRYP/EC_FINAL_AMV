 #include <LiquidCrystal.h>
LiquidCrystal lcd (12, 11, 5, 4, 3 ,2);

int laststate;
int currentstate;
int var;
int PV;
int SETPOINT = 900;
int HYS = 50;
int CO = 0;
int currentstate1;
int laststate1;
int currentstate2;
int laststate2;
int CP;

 

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
Serial.begin (9600);
pinMode(7, INPUT_PULLUP);
currentstate= digitalRead(7);
pinMode(9,OUTPUT);
pinMode(8, INPUT_PULLUP);
currentstate1= digitalRead(8);
pinMode(6, INPUT_PULLUP);
currentstate2= digitalRead(6);
}

void loop(){
  PV=analogRead(A0);
  // put your main code here, to run repeatedly:
if(PV <= SETPOINT-HYS){
  CO=255;
}
if(PV >= SETPOINT+HYS){
  CO=0;

}
analogWrite(9, CO);
laststate=currentstate;
if(laststate==1 && currentstate==0){



}

laststate = currentstate;
  currentstate = digitalRead(7);
  if(laststate == 1 && currentstate == 0){
    if (CP == 1){
    SETPOINT = SETPOINT + 25;
    }
    if (CP == 0){
      HYS = HYS +5;
    }
  }
  
laststate1 = currentstate1;
  currentstate1 = digitalRead(8);
  if(laststate1 == 1 && currentstate1 == 0){
     if (CP == 1){
    SETPOINT = SETPOINT - 25;
    }
    if (CP == 0){
      HYS = HYS -5;
    }
  }
  laststate2 = currentstate2;
  currentstate2 = digitalRead(6);
  if(laststate2 == 1 && currentstate2 == 0){
    CP = CP + 1;
    if(CP > 1){
      CP = 0;

    }
  }

switch (CP) {
  case 0:
lcd.setCursor(0,0);
lcd.print("CO = ");
lcd.print(CO);
lcd.print("   ");
lcd.setCursor(0,1);
lcd.print("HYS = ");
lcd.print(HYS);
lcd.print("   ");
    break;
  case 1:
lcd.setCursor(0,0);
lcd.print("PV = ");
lcd.print(PV);
lcd.print("   ");
lcd.setCursor(0,1);
lcd.print("SP = ");
lcd.print(SETPOINT);
lcd.print("   ");
    break;
  default:
    break;
}
Serial.print(CO);
Serial.print("\t");
Serial.print(HYS);
Serial.print("\t");
Serial.print(SETPOINT);
Serial.print("\t");
Serial.print(PV);
Serial.println("\t");

}
