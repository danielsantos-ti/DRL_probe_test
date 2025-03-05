#include <Arduino.h>

#define botaoDeTeste 18
#define PROBE_1 19
#define PROBE_2 21
#define buzzer 22
#define led 23

#define tempoDeEspera 1000


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
  
  if(estadoDoBotao == LOW){

    digitalWrite(led, HIGH);
    Serial.println("Teste iniciado");
    delay(tempoDeEspera);

    int estadoDoProbe1 = digitalRead(PROBE_1);
    int estadoDoProbe2 = digitalRead(PROBE_2);
    
    if(estadoDoProbe1 == LOW && estadoDoProbe2 == LOW){
      
      for(int i = 0; i < 4; i++){
        //tone(buzzer,1000, 200);
        digitalWrite(buzzer, HIGH);
        delay(50);
        digitalWrite(buzzer, LOW);
        delay(50);
      }
    
    }
    
    else
    {
      //tone(buzzer, 1000, 1000);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
    }
    
    digitalWrite(led, LOW);
  }

}
