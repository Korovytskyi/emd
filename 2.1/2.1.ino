const int buttonPin = 2;  // Пін, на якому підключена кнопка
const int ledPin = 13;    // Пін, на якому підключений діод

volatile int buttonCounter = 0;  // Лічильник натискань кнопки

void IRAM_ATTR handleInterrupt() {
  buttonCounter++;
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(buttonPin), handleInterrupt, FALLING);
}

void loop() {
  // Вмикання/вимикання діода в залежності від лічильника
  digitalWrite(ledPin, buttonCounter % 2);

  
  if (digitalRead(buttonPin) == LOW) {  // Якщо кнопка натиснута

  } 

  delay(100);  // Затримка для стабілізації зчитування кнопки
}