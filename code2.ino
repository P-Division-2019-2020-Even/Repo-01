#include <Wire.h> 
#include<LiquidCrystal_I2C.h>
#include<Servo.h>

LiquidCrystal_I2C lcd(0x27,16,2);  

const int onPIN = 6;
const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;

const int ledPin1 = 26;
const int ledPin2 = 27;
const int ledPin3 = 28;
const int ledPin4 = 29;

//int buttonState1 = 0;
//int buttonState2 = 0;

int servopin1 = 8;
int servopin2 = 9;
Servo servo1;  // RIGHT servo 
Servo servo2;  // LEFT servo 

void setup() {
  Serial.begin(9600);
    
    lcd.init();                      
    lcd.init();                      
    lcd.backlight();
    lcd.setCursor(0,0);

    lcd.print("Let's Start ???");


  pinMode(onPIN, INPUT);  
  pinMode(buttonPin1, INPUT);  
  pinMode(buttonPin2, INPUT);  
  pinMode(buttonPin3, INPUT);  
  pinMode(buttonPin4, INPUT);
  
  servo1.attach(servopin1);
  servo2.attach(servopin2);
  servo1.write(180);
  servo2.write(180);

  lcd.begin(16,2);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}
void loop()
{
    lcd.init();                      
    lcd.init();                      
    lcd.backlight();
    lcd.setCursor(0,0);

//  When SWITCH button is OFF

  if(digitalRead(onPIN) == LOW)
  {
    lcd.clear();
    lcd.print("Let's Start ???");    
  }

//  When SWITCH button is ON

  if(digitalRead(onPIN) == HIGH)
  {
    lcd.clear();
    lcd.print("Select TUNE");
    delay(3000);
    lcd.clear();
    lcd.print("1st or 2nd tune");
    delay(3000);
    lcd.clear();

    // When both TUNE selecting buttons are ON
    
    if(digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) ==HIGH)
    {
      lcd.clear();
      lcd.print("ON only ");
      lcd.setCursor(0,1);
      lcd.print("ONE Button.");
      delay(5000);
      lcd.clear();
    }

    // TUNE Selection
    
    if(digitalRead(buttonPin1)== HIGH && digitalRead(buttonPin2) == LOW)
    {
      // When TUNE 1 is selected
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("1st Tune ");    
      lcd.setCursor(0,1);
      lcd.print("Selected ");
      delay(3000);
      lcd.clear();
      lcd.print("Select ");
      lcd.setCursor(0,1);
      lcd.print("REPETITIONS ");
      delay(3000);
      lcd.clear();
      lcd.print("Select 3 or ");
      lcd.setCursor(0,1);
      lcd.print("6 Repetitions ");
      delay(3000);

      // When both REpETITION buttons are ON

      if(digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) ==HIGH)
      {
        lcd.clear();
        lcd.print("ON only ");
        lcd.setCursor(0,1);
        lcd.print("ONE button.");
        delay(5000);
        lcd.clear();
      }

      // When 3 Repetition is selected
      
      if(digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) ==LOW)
      {
        lcd.clear();
        delay(2000);
        lcd.print("3 Repetitions ");
        lcd.setCursor(0,1);
        lcd.print("Selected");
        tune1(3);
        lcd.clear();
      }

      // When 6 Repetition is selected
      
      if(digitalRead(buttonPin3) == LOW && digitalRead(buttonPin4) ==HIGH)
      {
        lcd.clear();
        delay(2000);
        lcd.print("6 Repetitions ");
        lcd.setCursor(0,1);
        lcd.print("Selected");
        tune1(6);
        lcd.clear();
      }

    }

    // When Tune 2 is selected
    
    if(digitalRead(buttonPin1) == LOW && digitalRead(buttonPin2) == HIGH)
    {
      lcd.clear();
      lcd.print("2nd Tune ");    
      lcd.setCursor(0,1);
      lcd.print("Selected");    
      delay(3000);
      lcd.clear();
      lcd.print("Select ");
      lcd.setCursor(0,1);
      lcd.print("REPETITIONS. ");
      delay(3000);
      lcd.clear();
      lcd.print("Select 3 or  ");
      lcd.setCursor(0,1);
      lcd.print("6 Repetition ");
      delay(3000);

      // When both Repetition buttons are selected
      
      if(digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) ==HIGH)
      {
        lcd.clear();
        lcd.print("ON only ");
        lcd.setCursor(0,1);
        lcd.print("ONE Button.");
        delay(5000);
        lcd.clear();
      }

      // When 3 Repetition is selected
      
      if(digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) ==LOW)
      {
        lcd.clear();
        delay(2000);
        lcd.print("3 Repetitions ");
        lcd.setCursor(0,1);
        lcd.print("Selected");
        tune2(3);
        lcd.clear();
      }

      // When 6 Repetition is selected
      
      if(digitalRead(buttonPin3) == LOW && digitalRead(buttonPin4) ==HIGH)
      {
        lcd.clear();
        delay(2000);
        lcd.print(" 6 Repetitions ");
        lcd.setCursor(0,1);
        lcd.print("Selected");
        tune2(6);
        lcd.clear();
      }

    }

  }
}


void tune1(int r)
{
  int i,s1;
  delay(1000);
  for(i=0;i<r;i++)
  {
    for(s1=0;s1<3;s1++)
    {
      servo1.write(0);
      delay(500);
      servo1.write(45); 
      servo2.write(0);
      delay(500);
      servo2.write(45);
      delay(1000);
      servo2.write(0);
      delay(500);
      servo2.write(45);
    }
    servo1.write(0);  
  digitalWrite(ledPin1, HIGH);
  delay(500);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2, HIGH);
  delay(500);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3, HIGH);
  delay(500);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4, HIGH);
  delay(500);
  digitalWrite(ledPin4,LOW);
  }

  lcd.clear();  
}

void tune2(int r) 
{
  int j;
  //if(buttonState2 ==HIGH)

  for(j=0;j<r;j++)
  {
    servo1.write(0);
    delay(1000);
    servo1.write(45);
    delay(1000);
    servo1.write(0);
    delay(1000);
    servo1.write(45);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo2.write(45);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo2.write(45);
    servo1.write(0);
    delay(1000);
    servo1.write(45);
    delay(1000);
    servo1.write(0);
    delay(1000);
    servo1.write(45);
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo2.write(45);
    delay(1000);

  digitalWrite(ledPin1, HIGH);
  delay(500);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2, HIGH);
  delay(500);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3, HIGH);
  delay(500);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4, HIGH);
  delay(500);
  digitalWrite(ledPin4,LOW);
  }

  lcd.clear();
}
