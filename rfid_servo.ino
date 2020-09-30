  #include <SPI.h>
  #include <deprecated.h>
  #include <MFRC522.h>
  #include <MFRC522Extended.h>
  #include <require_cpp11.h>
  #include <Servo.h>
  int RST_PIN = 9;
  int SS_PIN = 10;
  int servoPin = 8;
  int kapi = 45;
  byte ID[4] = {25, 11, 152, 40}; 
  Servo motor;
  MFRC522 rfid (SS_PIN, RST_PIN);
  
  void setup() {
  motor.attach(servoPin);
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  }
  
  void loop() {
  if(!rfid.PICC_IsNewCardPresent())
    return;
  if(!rfid.PICC_ReadCardSerial())
    return;
  if (rfid.uid.uidByte[0] == ID[0] && rfid.uid.uidByte[1] == ID[1] && rfid.uid.uidByte[2] == ID[2] && rfid.uid.uidByte[3] == ID[3]){
      //ekranaYazdir();  
      if(kapi == 45){
      //Serial.println("kapi acildi");
      motor.write(kapi);
      //delay(1000);
      kapi =90;
      //send
      Serial.print('1');
      delay(500);  
    }else if (kapi == 90){
      //Serial.println("kapi kapandi");
      motor.write(kapi);
      //delay(1000);
      kapi=45;  
      //send
      Serial.print('0');
      delay(500);  
    }
  }else {
  Serial.println("yetkisiz kart");
  //ekranaYazdir();    
  }
  rfid.PICC_HaltA();
  }
  
  void ekranaYazdir(){
    Serial.println("ID numara: ");
    for(int sayac = 0;sayac < 4; sayac++){
    Serial.println(rfid.uid.uidByte[sayac]);
    Serial.println(" ");
  }
  Serial.println("");
  }
