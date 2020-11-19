#include <DHT.h>
#include <Adafruit_BMP280.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

DHT dht(2,DHT22); // Declara objeto do tipo DHT
float umid, temp2; // Declara variáveis

int bin; float tensao, temp; // LM35

Adafruit_BMP280 bmp; // PRESSÃO
float press, temp3; // PRESSÃO

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600); // Inicializa serial

  analogReference(INTERNAL);
  dht.begin(); // Inicializa objeto dht
  bmp.begin(0x76); // Inicializa objeto BMP
  lcd.init(); // Inicializa LCD
  lcd.backlight(); // Liga luz do LCD
}

void loop() {
  //lcd.setCursor(0,0);
  //lcd.print("INSPER");
  //lcd.setCursor(0,1);
  //lcd.print("INSTRUMED");
  //delay(2000);
  //lcd.clear();
  
  //lcd.setCursor(0,0);
  //lcd.print("Jonas Bonfa");
  //lcd.setCursor(0,1);
  //lcd.print("Layne Pereira");
  //delay(2000);
  //lcd.clear();
  
  //lcd.setCursor(0,0);
  //lcd.print("Inicializando"); 
  //lcd.setCursor(0,1);
  //lcd.print("sensores");
  //delay(2000);
  //lcd.clear();

  
  // LM35
  bin = analogRead(A0); // Lê valor binário (A0)
  tensao = (bin/1023.0)*1.1; // Converte em tensão
  temp = 100.00*tensao+0.00; // Converte em temp.
  //Serial.print("\n\nDado: ");
  //Serial.print(bin); // Exibe dado binário
  //Serial.print("\nTensão [V]: ");
  //Serial.print(tensao); // Exibe tensão
  //Serial.print("\nTemperatura [ºC]: ");
  lcd.setCursor(0,0);
  lcd.print("Temperatura LM35");
  lcd.setCursor(0,1);
  lcd.print(temp);
  lcd.print((char)223);
  delay(2000);
  lcd.clear();
  //lcd.print(temp);// Escreve no LCD
  //Serial.print(temp); // Exibe temperatura
  //delay(2000);

  //DHT
  umid = dht.readHumidity(); // Lê umidade
  temp2 = dht.readTemperature(); // Lê temperatura
  umid = 1.00*umid + 0.00; // Calibração
  //Serial.print("\n\nUmidade [%]: ");
  lcd.setCursor(0,0);
  lcd.print("Umidade DHT");
  lcd.setCursor(0,1);
  lcd.print(umid);
  lcd.print(" %");
  delay(2000);
  lcd.clear();
  //Serial.print(umid); // Exibe umidade
  //Serial.print("\nTemperatura [ºC]: ");
  //Serial.print(temp2); // Exibe temp.
  //lcd.print(temp2);// Escreve no LCD
  //delay(2000);

  // PRESSÃO
  press = bmp.readPressure(); // Lê pressão
  temp3 = bmp.readTemperature();// Lê temperatura
  //Serial.print("\n\nPressão [hPa]: ");
  //Serial.print(press/100); // Exibe pressão
  lcd.setCursor(0,0);
  lcd.print("Pressao BPM");
  lcd.setCursor(0,1);
  lcd.print(press/100);
  lcd.print(" [hPa]");
  delay(2000);
  lcd.clear();
  //Serial.print("\nTemperatura [ºC]: ");
  //Serial.print(temp3); // Exibe temperatura
  //delay(2000);

}
