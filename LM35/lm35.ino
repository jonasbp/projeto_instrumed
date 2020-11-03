// Código retirado dos slides de Instrumentação e Medição
//Utilizando o fundo de escala 1,1
int bin; float tensao, temp; // Declara variáveis
void setup()
{
    Serial.begin(9600); // Inicializa serial
    analogReference(INTERNAL); // Fundo escala 1,1 V
}
void loop()
{
    bin = analogRead(A0); // Lê valor binário
    tensao = (bin/1023.0)*1.1; // Converte em tensão
    temp = 100.00*tensao+0.00; // Converte em temp.
    Serial.print("\n\nDado: ");
    Serial.print(bin); // Exibe dado binário
    Serial.print("\nTensão [V]: ");
    Serial.print(tensao); // Exibe tensão
    Serial.print("\nTemperatura [ºC]: ");
    Serial.print(temp); // Exibe temperatura
    delay(2000);
}