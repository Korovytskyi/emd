const int LED_PIN = 25;
const int LEDC_CHANNEL = 0; 
const int LEDC_RESOLUTION = 8; 

void setup()
{
  ledcSetup(LEDC_CHANNEL, 5000, LEDC_RESOLUTION); 
  ledcAttachPin(LED_PIN, LEDC_CHANNEL); 
  Serial.begin(115200);
}

void loop()
{
  for (int i = 0; i <= 255; ++i)
  {
    ledcWrite(LEDC_CHANNEL, i); 
    delay(10);
  }

  for (int i = 255; i >= 0; --i)
  {
    ledcWrite(LEDC_CHANNEL, i); 
    delay(10);
  }
}