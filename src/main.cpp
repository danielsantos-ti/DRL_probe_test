
/*
Data de criação: 03/03/2025
Versão: v1.0.0 - Úlima atualização: 03/03/2025
Descrição: Código desenvolvido para checar a presença de parafusos do drive do DLR (VW216), utilizando o ESP32 para processar o teste.

Autores:
- Daniel Santos - Engenheiro de Software
- Vagner Martines - Técnico de eletrônica
- Ezequiel Paiva - Técnico de eletrônica
- Alvaro Lazaroff - Técnico de eletrônica


Descrição
Código desenvolvido para checar a presença de parafusos do drive do DLR (VW216), utilizando o ESP32 para processar o teste.
*/

#include <Arduino.h>

// Definição dos pinos
const int botaoDeTeste = 18;
const int PROBE_1 = 19;
const int PROBE_2 = 21;
const int buzzer = 22;
const int led = 23;

// Definição do tempo de espera
const int tempoDeEspera = 1000; // 1 segundo

// Definição do tempo de espera do buzzer
const int tempoDeEsperaBuzzer = 5000; // 5 segundos

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
    
    // Verificação do estado dos probes
    if(estadoDoProbe1 == LOW && estadoDoProbe2 == LOW){
      
      // Acionamento do buzzer
      for(int i = 0; i < 4; i++){
        digitalWrite(buzzer, HIGH);
        delay(50);
        digitalWrite(buzzer, LOW);
        delay(50);
      }
    
    }
    
    // Verificação do estado dos probes
    else if(estadoDoProbe1 == LOW){
      digitalWrite(buzzer, HIGH);
      delay(tempoDeEsperaBuzzer);
      digitalWrite(buzzer, LOW);
    }
    else
    {
      digitalWrite(buzzer, HIGH);
      delay(tempoDeEsperaBuzzer);
      digitalWrite(buzzer, LOW);
    }
    
    digitalWrite(led, LOW);
  }

}
