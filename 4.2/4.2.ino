#include <Arduino.h>

// Функція для розрахунку експоненційного згладжування
template<typename T>
T exponentialMovingAverage(T current, T previous, float alpha) {
    return alpha * current + (1.0 - alpha) * previous;
}

void setup() {
    Serial.begin(115200);

    const int dataSize = 1000;  // Розмір вхідного масиву даних
    float sensorData[dataSize];
    
    // Згенерувати тестові дані
    for (int i = 0; i < dataSize; ++i) {
        sensorData[i] = static_cast<float>(rand() % 100);
    }

    // Затрати по часу і пам'яті для різних частот процесора
    for (int freq = 240; freq >= 40; freq /= 2) {
        Serial.print("CPU Frequency: ");
        Serial.println(freq);

        // Встановлення частоти процесора
        setCpuFrequencyMhz(freq);

        // Вимірювання часу та пам'яті для фільтрації даних
        unsigned long startTime = millis();

        // Використання фільтра
        float filteredData[dataSize];
        filteredData[0] = sensorData[0];  // Початкове значення

        for (int i = 1; i < dataSize; ++i) {
            filteredData[i] = exponentialMovingAverage(sensorData[i], filteredData[i - 1], 0.2);
        }

        unsigned long endTime = millis();

        // Вивід результатів
        Serial.print("Time taken: ");
        Serial.println(endTime - startTime);
        Serial.print("Memory usage: ");
        Serial.println(ESP.getFreeHeap());

        Serial.println();
    }
}

void loop() {
    // Залишити пустим
}