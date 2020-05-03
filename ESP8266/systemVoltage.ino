ADC_MODE(ADC_VCC);

void setup() {

   Serial.begin(9600);

}

void loop() {
  Serial.print("System voltage(mV): ");
  Serial.println(ESP.getVcc());
  delay(300);

}
