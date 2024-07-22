#include<DHT.h>
#define DHTPIN 3
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int val;
int tempin =A2;

int sensor =4;
int sensor1 =5;
int BUZZER =6;
int sensor2 =7;
void setup ()
{
  pinMode(sensor, INPUT);
  pinMode(sensor, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(BUZZER, OUTPUT);
  dht.begin();
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{if (digitalRead(sensor ==0),(sensor1 ==0),(sensor2 ==0)) 
  {digitalWrite(BUZZER, LOW);}
  else {digitalWrite(BUZZER, HIGH);}

  val =analogRead(tempin);
  float mv =(val/1024.0)*5000;
  float cel =mv/10;
  Serial.print("TEMPRATURE=");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();

  digitalRead(DHTPIN);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(t);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Hum:");
  lcd.print(h);
  lcd.print(" %");
}






