const int analogPin = 34;  // Пін для фоторезистора
const int numTimers = 5;   // Кількість таймерів

unsigned long timerIntervals[numTimers] = {1000, 2000, 3000, 4000, 5000};  // Інтервали таймерів (в мілісекундах)
unsigned long timerLastTrigger[numTimers] = {0};  // Останні часи спрацювання таймерів

void setup() {
  Serial.begin(115200);

  // Налаштування таймерів
  for (int i = 0; i < numTimers; i++) {
    timerLastTrigger[i] = millis();
  }
}

void loop() {
  // Зчитування даних по АЦП за різними інтервалами таймерів
  for (int i = 0; i < numTimers; i++) {
    if (millis() - timerLastTrigger[i] >= timerIntervals[i]) {
      int sensorValue = analogRead(analogPin);
      Serial.print("Timer ");
      Serial.print(i + 1);
      Serial.print(": Sensor Value = ");
      Serial.println(sensorValue);

      timerLastTrigger[i] = millis();  // Оновлення часу спрацювання таймера
    }
  }

  // Ваш додатковий код можна додати тут
}