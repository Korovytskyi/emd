const int LED_PIN = 25;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  for(int i = 0; i < 256; ++i)
  {
    dacWrite(LED_PIN, i);
    delay(10);
  }

  for(int i = 255; i >= 0; --i)
  {
    dacWrite(LED_PIN, i);
    delay(10);
  }
}