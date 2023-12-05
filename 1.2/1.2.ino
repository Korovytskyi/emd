const int LIGHT_SENSOR_PIN = 35;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  int analog_value = analogRead(LIGHT_SENSOR_PIN);

  Serial.print("Analog Value = ");
  Serial.print(analog_value);
  delay(1000);
}

