#include <LiquidCrystal.h>
// TRENDLINE_SLOPE and TRENDLINE_INTERCEPT are values determined through real-world calculations.
#define TRENDLINE_SLOPE 20.918
#define TRENDLINE_INTERCEPT -24.116
#define ADC_RANGE 1024.0
#define ADC_REFERENCE 5.0

//ADXL345 Accelerometer Code from https://learn.adafruit.com/adxl345-digital-accelerometer/programming

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  lcd.begin(16,2); //starts LCD with 16 columns and 2 rows
}

void loop() {
  // put your main code here, to run repeatedly:
  int ADCVALUE = analogRead(A0);           //fetches value of ADC pin 0 (0-1023)
  float VOLTAGE = (ADCVALUE * ADC_REFERENCE) / ADC_RANGE;   //convert ADC value to Volts
    //Now, using a trendline from real-world measurements, we convert the voltage
    // to pressure. Details of this calculation can be found in documentation.
  float PRESSURE = (VOLTAGE * TRENDLINE_SLOPE);
  PRESSURE += TRENDLINE_INTERCEPT;
  String pstring = String(PRESSURE);
  lcd.clear();
  lcd.print(pstring);
  delay(100);
  //TODO: convert pressure to string and print
  //TODO: add accelerometer calcs.
}
