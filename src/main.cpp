/*
Data de criação: 03/03/2025
Descrição do projeto:
Código verifica a presença de parafusos na peça.Caso os parafusos estejam presentes,
o sistema deve acionar um LED verde e um buzzer para indicar sucesso no teste.
Caso contrário, um LED vermelho deve ser acionado e um buzzer deve ser ativado.

--
Versão: v1.1.1 - Úlima atualização: 04/03/2025
Descrição:
- Adiciona LED vermelho para indicar falha no teste.
- Adiciona LED verde para indicar sucesso no teste.
- Aumenta o tempo do beep do buzzer para 5 segundos.

--
Versão: v1.0.1 - Úlima atualização: 03/03/2025
Descrição: Adiciona variável para controlar o tempo de espera do buzzer.

--
Versão: v1.0.0 - Úlima atualização: 03/03/2025
Descrição: Código verifica a presença de parafusos na peça.

Autores:
- Daniel Santos - Engenheiro de Software
- Vagner Martines - Técnico de eletrônica
- Ezequiel Paiva - Técnico de eletrônica
- Alvaro Lazaroff - Técnico de eletrônica

*/

#include <Arduino.h>

// Definição dos pinos
const int botaoDeTeste = 15;
const int PROBE_1 = 4;
const int PROBE_2 = 5;
const int buzzer = 21;
const int led_verde = 18; // Pino do LED verde
const int led_vermelho = 19; // Pino do LED vermelho
const int transistor = 2; // Pino do relé

// Definição do tempo de espera
const int tempoDeEspera = 1000; // 1 segundo

// Definição do tempo de giro do relé
const int tempoDeGiroDoCarga = 800; // 800ms

// Definição do tempo de espera do buzzer
const int tempoDeEsperaBuzzer = 5000; // 5 segundos

// Função setup
void setup() {
  
  // Configuração dos pinos
  pinMode(botaoDeTeste, INPUT_PULLUP);
  pinMode(PROBE_1, INPUT_PULLUP);
  pinMode(PROBE_2, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(transistor, OUTPUT);

  // Garantia de que os pinos estão desligados no início
  digitalWrite(led_verde, LOW);
  digitalWrite(led_vermelho, LOW); 
  digitalWrite(transistor, LOW);
  digitalWrite(buzzer, LOW);


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
    Serial.println("Teste iniciado");
    delay(tempoDeEspera);

    // Leitura dos estados dos probes
    int estadoDoProbe1 = digitalRead(PROBE_1);
    int estadoDoProbe2 = digitalRead(PROBE_2);

    // Resetando os estados dos LEDs e do transistor
    digitalWrite(led_verde, LOW);
    digitalWrite(led_vermelho, LOW);
    digitalWrite(transistor, LOW);
    
    // Verificação do estado dos probes
    if(estadoDoProbe1 == LOW && estadoDoProbe2 == LOW){
      
      // Aciona o LED Verde
      digitalWrite(led_verde, HIGH);
      // Acionamento do buzzer
      for(int i = 0; i < 4; i++){
        digitalWrite(buzzer, HIGH);
        delay(50);
        digitalWrite(buzzer, LOW);
        delay(50);
      }

    // Aciona o LED verde.
    delay(tempoDeEspera);
    digitalWrite(led_verde, LOW);
    digitalWrite(transistor, HIGH);
    delay(tempoDeGiroDoCarga);
    digitalWrite(transistor, LOW);
    Serial.println("Teste aprovado.");
    
    }
    
    // Verificação do estado dos probes
    else if(estadoDoProbe1 == LOW){
      // Aciona o LED Vermelho
      digitalWrite(led_vermelho, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(tempoDeEsperaBuzzer);
      digitalWrite(buzzer, LOW);
      Serial.println("Teste reprovado.");
    }
    else
    {
      // Aciona o LED Vermelho
      digitalWrite(led_vermelho, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(tempoDeEsperaBuzzer);
      digitalWrite(buzzer, LOW);
      Serial.println("Teste reprovado.");
    }
    
  }

  delay(tempoDeEspera);
  digitalWrite(led_verde, LOW);
  digitalWrite(led_vermelho, LOW);
  digitalWrite(transistor, LOW);

}
