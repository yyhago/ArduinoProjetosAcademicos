const int buttonPin = 2; // Define o pino onde o botão está conectado
const int ledPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // Define os pinos onde os LEDs estão conectados
int ledIndex = 0; // Índice do LED atual
bool ledsOn = false; // Estado dos LEDs (se estão todos acesos ou não)
bool buttonLastState = LOW; // Estado anterior do botão

void setup() {
  pinMode(buttonPin, INPUT); // Define o pino do botão como entrada
  Serial.begin(9600); // Inicializa a comunicação serial com taxa de 9600 bauds
  for (int i = 0; i < 10; i++) { // Configura todos os pinos dos LEDs como saída
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // Garante que todos os LEDs estejam apagados no início
  }
}

void loop() {
  int buttonState = digitalRead(buttonPin); // Lê o estado atual do botão
  if (buttonState == HIGH && buttonLastState == LOW) { // Verifica se houve uma transição de baixo para alto no pino do botão
    if (!ledsOn) { // Se os LEDs não estão todos acesos
      digitalWrite(ledPins[ledIndex], HIGH); // Acende o próximo LED
      Serial.print("LED "); 
      Serial.print(ledIndex + 1); 
      Serial.println(" on"); 
      ledIndex++; // Move para o próximo LED
      if (ledIndex >= 10) { // Se todos os LEDs estão acesos
        ledsOn = true; 
        ledIndex = 9; // Configura ledIndex para o último LED
      }
    } else { // Se os LEDs estão todos acesos
      digitalWrite(ledPins[ledIndex], LOW); // Apaga o LED atual
      Serial.print("LED "); 
      Serial.print(ledIndex + 1); 
      Serial.println(" off"); 
      ledIndex--; // Move para o LED anterior
      if (ledIndex < 0) { // Se todos os LEDs foram apagados
        ledsOn = false; 
        ledIndex = 0; // Configura ledIndex para o primeiro LED
      }
    }
  }
  buttonLastState = buttonState; // Atualiza o estado anterior do botão
  delay(50); // Aguarda 50 milissegundos antes de verificar o estado do botão novamente
}
