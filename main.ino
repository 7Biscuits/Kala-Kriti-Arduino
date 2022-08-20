#include <Adafruit_LiquidCrystal.h> //  This is Library for Oled 
#define OLED_RESET 4 //  This for reset. It is not Important to write
Adafruit_LiquidCrystal lcd(0);
int sensor = A0;
int buzzer = 2;
int red = 10;
int green = 8;
int blue = 9;
int gasLevel = 0; //int variable for gas level
String quality = "";

void setup() {

  Serial.begin(9600); //start serial comms
  pinMode(buzzer, OUTPUT); //set beeper for output
  pinMode(sensor, INPUT); //set sensor for input
  pinMode (red, OUTPUT);
  pinMode (green, OUTPUT);
  pinMode (blue, OUTPUT);
  lcd.begin(16, 2); // This is the address of our display so dont change it.
  lcd.clear(); // This is for clear Oled. If you will not this is print Adafruit Logo
  lcd.setBacklight(1); // This is color of text without this you can't see text
  lcd.println("KALA-KRITI");
  lcd.display(); // THIS IS ALWAYS USE AT LAST OF CODING AFTER PRINT ANYTHING IN OLED
  delay(2000);
}

void loop() {

  gasLevel = analogRead(sensor);
  Serial.print(" Gas Level:");
  Serial.println(gasLevel);
  digitalWrite (green, LOW);
  digitalWrite (red, LOW);
  digitalWrite (blue, LOW);
  digitalWrite (buzzer, LOW);

  if (gasLevel < 150) {
    quality = "GOOD";
    digitalWrite (green, HIGH);
    delay(500);
  }

  else if (gasLevel > 150 and gasLevel < 250) {
    quality = "Unhealthy";
    digitalWrite (blue, HIGH);
    tone(buzzer, 800, 50);
    delay(200);
  }

  else if (gasLevel > 250) {
    quality = "Hazardous ";
    digitalWrite (red, HIGH);
    digitalWrite( buzzer, HIGH);
    delay(200);
  }

  lcd.clear();
  lcd.setBacklight(1);
  lcd.setCursor(0, 0);
  lcd.print("Air Quality is: ");
  lcd.setCursor(100, 0);
  lcd.print(gasLevel);
  lcd.setCursor(0, 15);
  lcd.println(quality);
  lcd.display();
  delay(500);
} 
