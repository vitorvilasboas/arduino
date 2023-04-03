/*
   SKETCH:  Irrigação Inteligente
   AUTOR:   Vitor Vilas Boas
   DATA:    30/03/2022
*/
bool leituraSensor;
bool leituraAnterior;
int valor_analogico;

void setup() {
  pinMode(2, INPUT); //Sensor
  pinMode(12, OUTPUT); //Atuador - rele / válvula solenoide / bomba
  
  //LEDs
  pinMode(5, OUTPUT);  //vermelho
  pinMode(6, OUTPUT);  //amarelo
  pinMode(8, OUTPUT);  //verde

//  Serial.begin(9600);
//  pinMode(1, INPUT); //Sensor Analogico
}

void loop() {
  leituraSensor = digitalRead(2);

  if (leituraSensor == HIGH) {
     //No estado seco
     digitalWrite(5, HIGH);  //vermelho
     digitalWrite(8, LOW);   //verde
  } else {
     //No estado úmido
     digitalWrite(5, LOW);   //vermelho
     digitalWrite(8, HIGH);  //verde
  }

  //Ao entrar no estado seco  
  if (leituraSensor && !leituraAnterior) {
     delay(5000);
     digitalWrite(5, LOW);   //vermelho
     digitalWrite(6, HIGH);  //amarelo

     while (digitalRead(2)) {
        digitalWrite(12, HIGH); // liga válvula  
        delay(500);
        digitalWrite(12, LOW);  // desliga válvula  
        delay(10000);          
     }
     digitalWrite(6, LOW);  //amarelo
  }
  leituraAnterior = leituraSensor;

//  valor_analogico = analogRead(1);
//  Serial.print("Porta analogica: ");
//  Serial.print(valor_analogico);
//  if (valor_analogico > 0 && valor_analogico < 400)   // solo úmido - verde
//  if (valor_analogico > 400 && valor_analogico < 800) // umidade moderada - amarelo
//  if (valor_analogico > 800)                          // solo seco - vermelho
  
}
