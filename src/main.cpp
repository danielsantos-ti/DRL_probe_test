#include <Arduino.h>


// Definição dos pinos
#define botaoDeTeste 18
#define PROBE_1 19
#define PROBE_2 21
#define buzzer 22
#define led 23

// Definição do tempo de espera
#define tempoDeEspera 1000

// Função setup
void setup() {
  
  // Configuração dos pinos
  pinMode(botaoDeTeste, INPUT_PULLUP);
  pinMode(PROBE_1, INPUT_PULLUP);
  pinMode(PROBE_2, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  // Inicialização da comunicação serial
  Serial.begin(115200);
  Serial.println("Iniciando o sistema");

}

void loop() {
  
  //  Leitura do estado do botão
  int estadoDoBotao = digitalRead(botaoDeTeste);
  
  // Verificação do estado do botão
  if(estadoDoBotao == LOW){

    // Acionamento do led
    digitalWrite(led, HIGH);
    Serial.println("Teste iniciado");
    delay(tempoDeEspera);

    // Leitura dos estados dos probes
    int estadoDoProbe1 = digitalRead(PROBE_1);
    int estadoDoProbe2 = digitalRead(PROBE_2);
    
    // Verificação dos estados dos probes
    if(estadoDoProbe1 == LOW && estadoDoProbe2 == LOW){
      
      // Acionamento do buzzer
      for(int i = 0; i < 4; i++){
        //tone(buzzer,1000, 200);
        digitalWrite(buzzer, HIGH);
        delay(50);
        digitalWrite(buzzer, LOW);
        delay(50);
      }
    
    }
    
    // Verificação do estado do probe 1
    else if(estadoDoProbe1 == LOW){
      //tone(buzzer, 1000, 1000);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
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
