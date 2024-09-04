const int botaoPin = 2; // Define o pino onde o botão está conectado
const int ledAzulPin = 13; // Define o pino onde o LED azul está conectado
const int ledBrancoPin = 12; // Define o pino onde o LED branco está conectado
const int ledAmareloPin = 11; // Define o pino onde o LED amarelo está conectado

int estadoBotao = 0; // Armazena o estado atual do botão
int modo = 0; // Armazena o modo atual (1, 2 ou 3)

void setup() {
  pinMode(ledAzulPin, OUTPUT); // Define o pino do LED azul como saída
  pinMode(ledBrancoPin, OUTPUT); // Define o pino do LED branco como saída
  pinMode(ledAmareloPin, OUTPUT); // Define o pino do LED amarelo como saída
  pinMode(botaoPin, INPUT_PULLUP); // Define o pino do botão como entrada com resistor pull-up interno ativado
  Serial.begin(9600); // Inicializa a comunicação serial com taxa de 9600 bauds
}

void loop() {
  estadoBotao = digitalRead(botaoPin); // Lê o estado atual do botão
  if (estadoBotao == LOW) { // Verifica se o botão está pressionado (estado LOW devido ao resistor pull-up)
    delay(50); // Aguarda 50 milissegundos para debounce
    while(digitalRead(botaoPin) == LOW); // Aguarda o botão ser liberado
    delay(50); // Aguarda 50 milissegundos após a liberação do botão
    modo++; // Incrementa o modo
    if (modo > 3) { // Se o modo ultrapassar 3, reinicia para 1
      modo = 1;
    }
    Serial.println("Modo: " + String(modo)); // Imprime o modo atual na comunicação serial
  }
  
  if (modo == 1) { // Modo 1: Piscar LED azul
    digitalWrite(ledAzulPin, HIGH); // Acende o LED azul
    delay(500); // Aguarda 500 milissegundos
    digitalWrite(ledAzulPin, LOW); // Apaga o LED azul
    delay(500); // Aguarda 500 milissegundos
  } 
  else if (modo == 2) { // Modo 2: Sequência de LEDs azul, branco e amarelo
    digitalWrite(ledAzulPin, HIGH); // Acende o LED azul
    delay(250); // Aguarda 250 milissegundos
    digitalWrite(ledAzulPin, LOW); // Apaga o LED azul
    digitalWrite(ledBrancoPin, HIGH); // Acende o LED branco
    delay(250); // Aguarda 250 milissegundos
    digitalWrite(ledBrancoPin, LOW); // Apaga o LED branco
    digitalWrite(ledAmareloPin, HIGH); // Acende o LED amarelo
    delay(250); // Aguarda 250 milissegundos
    digitalWrite(ledAmareloPin, LOW); // Apaga o LED amarelo
    delay(250); // Aguarda 250 milissegundos
  } 
  else if (modo == 3) { // Modo 3: Todos os LEDs acesos
    digitalWrite(ledAzulPin, HIGH); // Acende o LED azul
    digitalWrite(ledBrancoPin, HIGH); // Acende o LED branco
    digitalWrite(ledAmareloPin, HIGH); // Acende o LED amarelo
    delay(500); // Aguarda 500 milissegundos
    digitalWrite(ledAzulPin, LOW); // Apaga o LED azul
    digitalWrite(ledBrancoPin, LOW); // Apaga o LED branco
    digitalWrite(ledAmareloPin, LOW); // Apaga o LED amarelo
    delay(500); // Aguarda 500 milissegundos
  }
}
