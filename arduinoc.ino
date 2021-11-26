#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

typedef struct Advertising {
  int pay;
  char text[512];
} Advertising;

void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  lcd.begin(16, 2);
}

void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get count byte:

    String s = Serial.readStringUntil('\n');
    
    /*int bytesCount;
    Serial.readBytes( (char*)&bytesCount ,4);
    char buf[bytesCount] = {0};
    Serial.readBytes(buf, bytesCount);
*/
    lcd.print(s);
    
    // send sensor values:
    //Serial.write(buf, sizeof(buf));
  }
  
}
