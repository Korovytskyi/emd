#include <Arduino.h>

// Функція для генерації масиву
template<typename T>
void generateArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = static_cast<T>(rand() % 100);
    }
}

// Функція для виводу масиву на екран
template<typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        Serial.print(arr[i]);
        Serial.print(" ");
    }
    Serial.println();
}

// Функція сортування бульбашкою
template<typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Обмін елементів
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void setup() {
    Serial.begin(115200);

    const int arraySize = 100;

    // Типи для масивів
    double doubleArray[arraySize];
    float floatArray[arraySize];
    int intArray[arraySize];
    char charArray[arraySize];

    // Генерування масивів
    generateArray(doubleArray, arraySize);
    generateArray(floatArray, arraySize);
    generateArray(intArray, arraySize);
    generateArray(charArray, arraySize);

    // Сортування та вимірювання часу та пам'яті
    unsigned long startTime;
    unsigned long endTime;

    // Сортування масивів double
    startTime = millis();
    bubbleSort(doubleArray, arraySize);
    endTime = millis();
    Serial.print("Double Sort Time: ");
    Serial.println(endTime - startTime);

    // Сортування масивів float
    startTime = millis();
    bubbleSort(floatArray, arraySize);
    endTime = millis();
    Serial.print("Float Sort Time: ");
    Serial.println(endTime - startTime);

    // Сортування масивів int
    startTime = millis();
    bubbleSort(intArray, arraySize);
    endTime = millis();
    Serial.print("Int Sort Time: ");
    Serial.println(endTime - startTime);

    // Сортування масивів char
    startTime = millis();
    bubbleSort(charArray, arraySize);
    endTime = millis();
    Serial.print("Char Sort Time: ");
    Serial.println(endTime - startTime);

    // Для частоти процесора
    Serial.print("CPU Frequency: ");
    Serial.println(ESP.getCpuFreqMHz());
}

void loop() {
  // Залишити пустим
}