 #include <LiquidCrystal.h>
LiquidCrystal lcd (12, 11, 5, 4, 3 ,2);

int var;
int PV;
float CO;
int SETPOINT = 0;
float Error;
float PG = 0;
int laststate;
int currentstate;
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
  // put your main code here, to run repeatedly:
  
  PV=analogRead(A0);
  Error = SETPOINT - PV;
  CO = PG * Error;
if(CO > 255){
  CO=255;
}

if (CO < 0){
    CO = 0;

}
analogWrite(9, CO);
laststate=currentstate;
if(laststate==1 && currentstate==0){
  
}
  currentstate = digitalRead(7);
  if(currentstate == 1){
    if (CP == 1 && SETPOINT < 900){
    SETPOINT = SETPOINT + 25;
    }
    if (CP == 0){
      PG = PG + 0.01;
    }
  }

  currentstate1 = digitalRead(8);
  if(currentstate1 == 1){
     if (CP == 1 && SETPOINT > 0){
    SETPOINT = SETPOINT - 25;
    }
    if (CP == 0 && PG > 0){
      PG = PG -0.1;
       }
       delay(100);
    }
 
 laststate2 = currentstate2;
  currentstate2 = digitalRead(6);
  if(laststate2 == 1 && currentstate2 == 0){
    CP = CP + 1;
    if(CP > 1){
      CP = 0;
    }
    delay(100);
  }
  
  switch(CP){
    case 0:
  lcd.setCursor(0, 1);
  lcd.print("PV = ");
  lcd.print(PV);
  lcd.print(" ");
  lcd.setCursor(0, 0);
  lcd.print("PG = ");
  lcd.print(PG);
  lcd.print(" ");
    break;
    case 1:
    lcd.setCursor(0, 1);
  lcd.print("SP = ");
  lcd.print(SETPOINT);
  lcd.print("    ");
  lcd.setCursor(0, 0);
  lcd.print("CO = ");
  lcd.print("%");
  lcd.print("         ");
  }
  Serial.print(PV); 
  Serial.print("\t");
  Serial.print(CO);
  Serial.print("\t"); 
  Serial.print(SETPOINT);
  Serial.print("\t");
  Serial.print(PG);
  Serial.print("\t");
  Serial.print(Error);
  Serial.println();
}
