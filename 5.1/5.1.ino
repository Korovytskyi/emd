#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

const int photoResistorPin = 34; // Пін для фоторезистора
int photoResistorValue = 0;

// BLE
BLEServer *pServer = NULL;
BLECharacteristic *pCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *pServer) {
    deviceConnected = true;
  }

  void onDisconnect(BLEServer *pServer) {
    deviceConnected = false;
  }
};

void setup() {
  Serial.begin(115200);
  pinMode(photoResistorPin, INPUT);

  BLEDevice::init("Photoresistor_BLE");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(BLEUUID((uint16_t)0x180F)); // Battery Service
  pCharacteristic = pService->createCharacteristic(
      BLEUUID((uint16_t)0x2A19), BLECharacteristic::PROPERTY_READ);
  pService->start();

  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(pService->getUUID());
  pAdvertising->start();
}

void loop() {
  if (deviceConnected) {
    photoResistorValue = analogRead(photoResistorPin);
    pCharacteristic->setValue((uint8_t*)&photoResistorValue, sizeof(photoResistorValue));

    Serial.print("Photoresistor Value: ");
    Serial.println(photoResistorValue);

    delay(1000); // Передавати дані кожну секунду
  }

  if (!deviceConnected && oldDeviceConnected) {
    delay(500);
    pServer->startAdvertising();
    oldDeviceConnected = deviceConnected;
  }
  if (deviceConnected && !oldDeviceConnected) {
    oldDeviceConnected = deviceConnected;
  }
}