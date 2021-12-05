#include <LiquidCrystal.h>
const int rs = 12, e = 11, d4 =4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
int temp;
int fan= 2;
int led= 1;
int sensorpin= A5;
int min_temp= 20;

void setup () {
  lcd.begin(16, 2);
  pinMode(fan, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  temp= analogRead(sensorpin);
  temp= temp*0.4883;
  if(temp < min_temp) {
    lcd.print("Kipas off");
  }

  if(temp >= min_temp){
    digitalWrite(fan, HIGH);
    digitalWrite(led, LOW);
    lcd.print("Kipas ON");
  }
  else {
    digitalWrite(led, HIGH);
  }

  lcd.setCursor(0,1);
  lcd.print("Suhu; ");
  lcd.print(temp);
  lcd.print("C");
  delay(200);
  lcd.clear();
}
