void thermistor() {
  int adcValue = analogRead(PIN_THERMISTOR);
  float voltage = (adcValue * 5) / ADC_MAX;
  float resistance = SERIES_RESISTOR * (voltage / (5 - voltage));
  // 温度を計算 (Steinhart–Hart equation)
  temp = resistance / THERMISTOR_NOMINAL;
  temp = log(temp);
  temp /= B_COEFFICIENT;
  temp += 1.0 / (TEMPERATURE_NOMINAL + 273.15);
  temp = 1.0 / temp;                         
  temp += TEMPERATURE_NOMINAL;
  temp -= 273.15;
}
