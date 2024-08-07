#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include <SoftwareSerial.h>
SoftwareSerial mySerial (2, 3);   //(RX, TX);
const int buzzer = 9; //buzzer to arduino pin 9

String val = "Welcome";
String oldval;
String newval = "Welcome";
int i = 0;

void setup(){
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  lcd.init(); // initialize the lcd 
  lcd.init(); // Print a message to the LCD.
  lcd.backlight();
  lcd.begin(16,2);  // put your setup 
  mySerial.begin(9600);
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Wireless Notice");
  lcd.setCursor(0, 1);
  lcd.print("     Board     ");
  delay(3000);
  lcd.clear();
  lcd.print("Welcome");
}

void loop(){
  val = mySerial.readString();
  val.trim();
  Serial.println(val);
  if(val != oldval)
  {
    newval = val;
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
}
  val = oldval;
  Serial.println(val);
  lcd.clear();
  lcd.setCursor(16, 0);
  lcd.print(newval);
  for(int counter = 1; counter < 24; counter++){
    lcd.scrollDisplayLeft();
    delay(400);
    /*
    lcd.print(newval);
    delay(1000);
    
    */
    }
  readSerialPort();
  }

void readSerialPort(){
  while (Serial.available()){
    delay(10);
    char c = Serial.read();
  }
}
