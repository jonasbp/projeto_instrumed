#include <DHT.h>
#include <Adafruit_BMP280.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

DHT dht(2,DHT22); // Declara objeto do tipo DHT
float umid, temp2; // Declara variáveis

int bin; float tensao, temp, cal; // LM35

int bin2; float tensao2, res, lum; // LDR

Adafruit_BMP280 bmp; // PRESSÃO
float press, temp3; // PRESSÃO

LiquidCrystal_I2C lcd(0x27,16,2); // LCD

void setup() {
  //Serial.begin(9600); // Inicializa serial

  analogReference(INTERNAL);
  dht.begin(); // Inicializa objeto dht
  bmp.begin(0x76); // Inicializa objeto BMP
  lcd.init(); // Inicializa LCD
  lcd.backlight(); // Liga luz do LCD

  // BOAS VINDAS
  lcd.setCursor(0,0);
  lcd.print("INSPER");
  lcd.setCursor(0,1);
  lcd.print("INSTRUMED");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Jonas Bonfa");
  lcd.setCursor(0,1);
  lcd.print("Layne Pereira");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Inicializando"); 
  delay(2000);
  lcd.clear();
}

void loop() {
  // LM35
  bin = analogRead(A0); // Lê valor binário (A0)
  tensao = (bin/1023.0)*1.1; // Converte em tensão
  temp = 100.00*tensao; // Converte em temp.
  temp = 0.992656148 * temp + 0.266336814; // 1 a invertido, 0 b invertido
  //Serial.print("\n\nDado: ");
  //Serial.print(bin); // Exibe dado binário
  //Serial.print("\nTensão [V]: ");
  //Serial.print(tensao); // Exibe tensão
  //Serial.print("\nTemperatura [ºC]: ");
  lcd.setCursor(0,0);
  lcd.print("Temperatura LM35");
  lcd.setCursor(0,1);
  lcd.print(temp);
  lcd.print(" ");
  lcd.print((char)223);
  lcd.print("C");
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
  lcd.print(" hPa");
  delay(2000);
  lcd.clear();
  //Serial.print("\nTemperatura [ºC]: ");
  //Serial.print(temp3); // Exibe temperatura
  //delay(2000);

  //LDR
  bin2 = analogRead(A1); // Lê binário
  tensao2 = (bin2/1023.0)*1.1; // Calc. tensão
  res = tensao2*100000.0/(5.0-tensao2); // Calc. resist.
  lum = pow(10,6.5-1.25*log10(res)); // Calc. lumnos.
  //Serial.print("\n\nDado: ");
  //Serial.print(bin2); // Exibe binário
  //Serial.print("\nTensão [V]: ");
  //Serial.print(tensao); // Exibe tensão
  //Serial.print("\nResistência [kΩ]: ");
  //Serial.print(res/1000); // Exibe resistência
  //Serial.print("\nLuminosidade [Lux]: ");
  //Serial.print(lum); // Exibe luminosidade
  //delay(2000); 
  
  lcd.setCursor(0,0);
  lcd.print("Luminosidade LDR");
  lcd.setCursor(0,1);
  lcd.print(lum);
  lcd.print(" lx");
  delay(2000);
  lcd.clear();
  

}
