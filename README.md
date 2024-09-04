# Projetos de Arduino para Aprendizado

Este repositório contém três projetos desenvolvidos como parte de trabalhos escolares utilizando a plataforma Tinkercad. O objetivo desses projetos é aprofundar o conhecimento na linguagem de programação Arduino e em práticas de eletrônica básica.

## Screenshots dos Projetos

![Primeira Tela](/pictureScreen/image.png)
![Segunda Tela](/pictureScreen/image2.png)
![Terceira Tela](/pictureScreen/image3.png)


## Índice

1. [Projeto 1: Controle de Servo com Modo de Varredura e Aleatório](#projeto-1-controle-de-servo-com-modo-de-varredura-e-aleatório)
2. [Projeto 2: Controle de LEDs com Sequência e Botão](#projeto-2-controle-de-leds-com-sequência-e-botão)
3. [Projeto 3: Controle de LEDs com Modo Selecionável](#projeto-3-controle-de-leds-com-modo-selecionável)
4. [Como Utilizar](#como-utilizar)
5. [Considerações Finais](#considerações-finais)

## Projeto 1: Controle de Servo com Modo de Varredura e Aleatório

### Descrição
Este projeto utiliza um servo motor e um potenciômetro para criar dois modos de operação: varredura contínua e movimento aleatório. Além disso, LEDs indicam o modo atual.

### Código

```cpp
#include <Servo.h>

Servo servoMotor;
const int pinoServo = 9;
const int pinoBotao = 2;
const int pinoPotenciometro = A0;
const int pinoLedVerde = 5;
const int pinoLedVermelho = 6;

bool modoVarredura = true;

void setup() {
  pinMode(pinoBotao, INPUT);
  pinMode(pinoLedVerde, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pinoBotao), alternarModo, RISING);
  servoMotor.attach(pinoServo);
}

void loop() {
  if (modoVarredura) {
    int posicao = map(analogRead(pinoPotenciometro), 0, 1023, 0, 180);
    servoMotor.write(posicao);
    digitalWrite(pinoLedVerde, HIGH);
    digitalWrite(pinoLedVermelho, LOW);
  } else {
    int posicao = random(0, 181);
    servoMotor.write(posicao);
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoLedVermelho, HIGH);
    delay(500);
  }
}

void alternarModo() {
  modoVarredura = !modoVarredura;
}
```

### Explicação
- **Objetivo**: Controlar um servo motor com dois modos de operação (varredura e aleatório) e indicar o modo com LEDs.
- **Componentes**: Servo motor, potenciômetro, LEDs, botão.
- **Funcionamento**: O botão alterna entre os modos de varredura (com o potenciômetro) e aleatório (movimento aleatório do servo). LEDs indicam o modo atual.

## Projeto 2: Controle de LEDs com Sequência e Botão

### Descrição
Este projeto utiliza uma série de LEDs e um botão para criar uma sequência de acendimento e apagamento dos LEDs.

### Código

```cpp
const int botaoPin = 2; 
const int ledPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
int ledIndex = 0; 
bool ledsOn = false; 
bool buttonLastState = LOW;

void setup(){ 
  pinMode(botaoPin, INPUT); 
  Serial.begin(9600); 
  for (int i = 0; i < 10; i++) { 
    pinMode(ledPins[i], OUTPUT); 
    digitalWrite(ledPins[i], LOW); 
  } 
}

void loop() { 
  int buttonState = digitalRead(botaoPin);
  if (buttonState == HIGH && buttonLastState == LOW) { 
    if (!ledsOn) {
      digitalWrite(ledPins[ledIndex], HIGH); 
      Serial.print("LED "); 
      Serial.print(ledIndex + 1); 
      Serial.println(" on"); 
      ledIndex++;
      if (ledIndex >= 10) { 
        ledsOn = true; ledIndex = 9;
      } 
    } else {
      digitalWrite(ledPins[ledIndex], LOW); 
      Serial.print("LED "); 
      Serial.print(ledIndex + 1); 
      Serial.println(" off"); ledIndex--;
      if (ledIndex < 0) { 
        ledsOn = false; ledIndex = 0;
      } 
    } 
  } 
  buttonLastState = buttonState; delay(50); 
}
```

### Explicação
- **Objetivo**: Controlar uma sequência de LEDs utilizando um botão para acender e apagar LEDs em ordem.
- **Componentes**: LEDs, botão.
- **Funcionamento**: O botão altera o estado dos LEDs entre aceso e apagado, sequencialmente. LEDs são acesos e apagados conforme o botão é pressionado.

## Projeto 3: Controle de LEDs com Modo Selecionável

### Descrição
Neste projeto, três LEDs são controlados com diferentes padrões de iluminação baseados no modo selecionado através de um botão.

### Código

```cpp
const int botaoPin = 2;
const int ledAzulPin = 13;
const int ledBrancoPin = 12;
const int ledAmareloPin = 11;

int estadoBotao = 0;
int modo = 0;

void setup() {
  pinMode(ledAzulPin, OUTPUT);
  pinMode(ledBrancoPin, OUTPUT);
  pinMode(ledAmareloPin, OUTPUT);
  pinMode(botaoPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  estadoBotao = digitalRead(botaoPin);
  if (estadoBotao == LOW) {
    delay(50);
    while(digitalRead(botaoPin) == LOW);
    delay(50);
    modo++;
    if (modo > 3) {
      modo = 1;
    }
    Serial.println("Modo: " + String(modo));
  }
  
  if (modo == 1) {
    digitalWrite(ledAzulPin, HIGH);
    delay(500);
    digitalWrite(ledAzulPin, LOW);
    delay(500);
  } 
  else if (modo == 2) {
    digitalWrite(ledAzulPin, HIGH);
    delay(250);
    digitalWrite(ledAzulPin, LOW);
    digitalWrite(ledBrancoPin, HIGH);
    delay(250);
    digitalWrite(ledBrancoPin, LOW);
    digitalWrite(ledAmareloPin, HIGH);
    delay(250);
    digitalWrite(ledAmareloPin, LOW);
    delay(250);
  } 
  else if (modo == 3) {
    digitalWrite(ledAzulPin, HIGH);
    digitalWrite(ledBrancoPin, HIGH);
    digitalWrite(ledAmareloPin, HIGH);
    delay(500);
    digitalWrite(ledAzulPin, LOW);
    digitalWrite(ledBrancoPin, LOW);
    digitalWrite(ledAmareloPin, LOW);
    delay(500);
  }
}
```

### Explicação
- **Objetivo**: Controlar três LEDs com diferentes padrões de iluminação baseados em modos.
- **Componentes**: LEDs, botão.
- **Funcionamento**: O botão alterna entre três modos, cada um com um padrão de iluminação específico para os LEDs.

## Como Utilizar

1. **Configuração do Hardware**:
   - Conecte os componentes aos pinos especificados no código.
   - Use a plataforma Tinkercad ou um ambiente de prototipagem físico para montar o circuito.

2. **Upload do Código**:
   - Conecte seu Arduino ao computador.
   - Abra a IDE Arduino e selecione a placa correta.
   - Copie e cole o código correspondente ao seu projeto.
   - Faça o upload para o Arduino.

3. **Execução**:
   - Observe os LEDs e o comportamento conforme descrito em cada projeto.

## Considerações Finais

Esses projetos foram desenvolvidos para aprendizado e prática com a linguagem de programação Arduino e eletrônica básica. São exemplos ideais para quem está começando a explorar o potencial do Arduino em projetos interativos e educativos.