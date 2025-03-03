#include <Arduino.h>

#define botaoDeTeste 18
#define PROBE_1 19
#define PROBE_2 21
#define buzzer 22
#define led 23

#define tempoDeEspera 3000


void setup() {
  
  pinMode(botaoDeTeste, INPUT_PULLUP);
  pinMode(PROBE_1, INPUT_PULLUP);
  pinMode(PROBE_2, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(115200);
  Serial.println("Iniciando o sistema");

}

void loop() {
  
  int estadoDoBotao = digitalRead(botaoDeTeste);
  int estadoDoProbe1 = digitalRead(PROBE_1);
  int estadoDoProbe2 = digitalRead(PROBE_2);

  if(estadoDoBotao == LOW){

    digitalWrite(led, HIGH);
    delay(tempoDeEspera);

    while(!(estadoDoProbe1 == LOW) && (estadoDoProbe2 == LOW))
    {
      
    }
    
    digitalWrite(led, LOW);
    tone(buzzer, 1000, 200);
    delay(200);
    //noTone(buzzer);

  }

}
