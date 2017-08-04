/*******************************
 *
 * File: ga_dev_apogee_BM180_temperature.cpp
 *
 * This module is a driver for the pressure and
 * temperature sensor.
 *
 * Product Page: https://www.adafruit.com/product/1603
 * Datasheet: https://cdn-shop.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf
 *
 ******************************/

#include "ga_dev_apogee_BMP180_temperature.h"
static Adafruit_BMP085 bmp180;

/******************************
 *
 * Name:        ga_dev_apogee_BM180_temperature_open
 * Returns:     Nothing
 * Parameter:   Nothing
 * Description: Initialize BMP180 sensor
 *
 ******************************/

void ga_dev_apogee_BMP180_temperature_open(void){
    bmp180.begin();
}

/******************************
 *
 * Name:        ga_dev_apogee_BMP180_temperature_read
 * Returns:     Temperature in Celsius (C)
 * Parameter:   Nothing
 * Description: Read the temperature from the BMP180 sensor
 *
 ******************************/

int16_t ga_dev_apogee_BMP180_temperature_read(void){
    int16_t value = 1000;

    #ifndef SEN_STUB
    value = bmp180.readTemperature();
    //value = value_f * 10;
    #endif

    return value;
}

void ga_dev_apogee_BMP180_temperature_test(void){
  uint16_t bmp085_temp = ga_dev_apogee_BMP180_temperature_read();
  Serial.print(F("[P] BMP180 temp: "));
  Serial.print(bmp085_temp/10);
  Serial.print(".");
  Serial.print((bmp085_temp-bmp085_temp/10)/10);
  Serial.println(F(" celsius"));

  if(bmp085_temp < 0){
      Serial.println(F("[P] \tError: BMP180 temperature out of range"));
  }
}
