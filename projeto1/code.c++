#include <Servo.h> // Inclui a biblioteca Servo para controlar o servo motor

Servo servoMotor; // Cria um objeto Servo chamado servoMotor
const int pinoServo = 9; // Define o pino onde o servo motor está conectado
const int pinoBotao = 2; // Define o pino onde o botão está conectado
const int pinoPotenciometro = A0; // Define o pino onde o potenciômetro está conectado
const int pinoLedVerde = 5; // Define o pino onde o LED verde está conectado
const int pinoLedVermelho = 6; // Define o pino onde o LED vermelho está conectado

bool modoVarredura = true; // Variável que controla o modo de operação (varredura ou aleatório)

void setup() {
  pinMode(pinoBotao, INPUT); // Define o pino do botão como entrada
  pinMode(pinoLedVerde, OUTPUT); // Define o pino do LED verde como saída
  pinMode(pinoLedVermelho, OUTPUT); // Define o pino do LED vermelho como saída
  attachInterrupt(digitalPinToInterrupt(pinoBotao), alternarModo, RISING); // Configura uma interrupção para mudar o modo ao pressionar o botão
  servoMotor.attach(pinoServo); // Conecta o servo motor ao pino definido
}

void loop() {
  if (modoVarredura) { // Verifica se o modo de varredura está ativado
    int posicao = map(analogRead(pinoPotenciometro), 0, 1023, 0, 180); // Lê o valor do potenciômetro e o mapeia para o intervalo de 0 a 180 graus
    servoMotor.write(posicao); // Define a posição do servo motor com base no valor do potenciômetro
    digitalWrite(pinoLedVerde, HIGH); // Acende o LED verde
    digitalWrite(pinoLedVermelho, LOW); // Apaga o LED vermelho
  } else { // Se o modo de varredura não estiver ativado
    int posicao = random(0, 181); // Gera uma posição aleatória para o servo motor
    servoMotor.write(posicao); // Define a posição do servo motor com o valor aleatório
    digitalWrite(pinoLedVerde, LOW); // Apaga o LED verde
    digitalWrite(pinoLedVermelho, HIGH); // Acende o LED vermelho
    delay(500); // Aguarda 500 milissegundos antes de mudar a posição do servo motor
  }
}

void alternarModo() {
  modoVarredura = !modoVarredura; // Alterna o valor da variável modoVarredura entre true e false
}
