  #include <LiquidCrystal.h>
  int rs = 12, en=11, d4=5, d5=4, d6=3, d7=2;
  LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
  #define buzzerPin 8
  void setup() {
    lcd.begin(16,2);
    Serial.begin(9600);
    pinMode(buzzerPin, OUTPUT);
  }
  void loop() {
    char c;
    if(Serial.available()>0){
      c=Serial.read();
      if(c == '0'){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kapi Acildi");
      lcd.setCursor(0,1);
      lcd.print("Hosgeldiniz");  
      digitalWrite(buzzerPin,HIGH);
      delay(500);
      digitalWrite(buzzerPin,LOW);
      }
      if(c == '1'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Kapi kapandi");
        lcd.setCursor(0,1);
        lcd.print("Gule gule");      
        digitalWrite(buzzerPin,HIGH);
        delay(500);
        digitalWrite(buzzerPin,LOW);
      }
    }
    delay(1000);
    lcd.clear();
  }
