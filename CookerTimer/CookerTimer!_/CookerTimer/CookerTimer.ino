

#include <LiquidCrystal.h>  // Лобавляем необходимую библиотеку
LiquidCrystal lcd(PD7, PD6, PD5, PD4, PD3, PD2); // (RS, E, DB4, DB5, DB6, DB7)

int nMin=0;
int iMin=0;
int iSec=0;

void Off()
{
  digitalWrite(A0,LOW);
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
  digitalWrite(A3,LOW);

  int iSnd=10;
  
  while(true)
  {
    digitalWrite(12,HIGH); //LED on
    delay(50);
    
    
    for(int i=0;i<=50;i++)
    {
      if(iSnd>0){digitalWrite(11,HIGH);} //Speaker on
      delay(1);
      digitalWrite(11,LOW); //Speaker off
      delay(1);
    }
    
        
    digitalWrite(12,LOW);  //LED off
    delay(50);


    for(int i=0;i<=50;i++)
    {
      if(iSnd>0){digitalWrite(11,HIGH);} //Speaker on
      delay(1);
      digitalWrite(11,LOW); //Speaker off
      delay(1);
    }

   iSnd-=1;
    
   // Serial.write('*');
    
  }
}

void On()
{
  delay(1000);
  digitalWrite(A0,HIGH);
  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);
  digitalWrite(A3,HIGH);
}

void setup() {
  // put your setup code here, to run once:

 // Serial.begin(9600);

  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH); //LED on

  pinMode(11,OUTPUT);
  digitalWrite(11,LOW); //Speaker off

  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  
  On();
  //delay(1000);
  //Off();
  
  

  lcd.begin(16, 2);                  // Задаем размерность экрана

  lcd.setCursor(0, 0);              // Устанавливаем курсор в начало 1 строки


  pinMode(A4,INPUT_PULLUP);
  pinMode(A5,INPUT_PULLUP);

  //Serial.print(digitalRead(A4));
  //Serial.print(digitalRead(A5));
    
  if(digitalRead(A5)==LOW && digitalRead(A4)==LOW) {nMin=10;}
  if(digitalRead(A5)==LOW && digitalRead(A4)==HIGH) {nMin=15;}
  if(digitalRead(A5)==HIGH && digitalRead(A4)==LOW) {nMin=3;}
  if(digitalRead(A5)==HIGH && digitalRead(A4)==HIGH) {nMin=5;}
  
  iMin=nMin;
  iSec=0;
  lcd.print(nMin);       // Выводим текст
  lcd.print(" minutes");       // Выводим текст

  On();

}



void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  //Serial.write('.');

  lcd.begin(16, 2);
  lcd.print(nMin);
  lcd.print(" minutes");
   
  lcd.setCursor(0, 1);              // Устанавливаем курсор в начало 2 строки
  lcd.print("left:");         // Выводим текст
  lcd.print(iMin);         // Выводим текст
  lcd.print("min ");         // Выводим текст
  lcd.print(iSec);         // Выводим текст
  lcd.print("sec   ");         // Выводим текст
  
  
  
  if(iMin==0 && iSec==0){Off();}
   
  if(iSec==0 && iMin!=0){iSec=59;iMin=iMin-1;} else {iSec=iSec-1;}
  
 

}
