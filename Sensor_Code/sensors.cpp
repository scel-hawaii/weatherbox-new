/*******************************************
 *
 *    File: sensors.cpp
 *    REIS Weatherbox Firmware
 *
 *    File containing Sensor Functions
 *
 ******************************************/

/* Necessary Libraries */
#include "sensors.h"

/* Set Pins */
OneWire oneWire1(_PIN_AMB_TEMP);
DallasTemperature dallas_amb_sen(&oneWire1);
OneWire oneWire2(_PIN_ROOF_TEMP);
DallasTemperature dallas_roof_sen(&oneWire2);

SHT1x sht1x(_PIN_HUMID_DATA, _PIN_HUMID_CLK);

Adafruit_BMP085 bmp085;
Adafruit_INA219 ina219_Solar;


/*******************************************
 *
 *    Name:        Sensors_init      
 *    Returns:     Nothing
 *    Parameter:   Nothing
 *    Description: Intializes  sensors using various 
 *                     Arduino libraries.
 *
 ******************************************/
void Sensors_init(void){
    bmp085.begin();
    ina219_Solar.begin();
}

/*******************************************
 *
 *    Name:        Sensors_sampleBatterymV     
 *    Returns:     Battery Voltage (mV)
 *    Parameter:   Nothing
 *    Description: Checks the battery voltage.
 *
 ******************************************/
int Sensors_sampleBatterymV(void){
    int value = analogRead(_PIN_BATT_V)*5000.0/1023;
    return value;
}

/*******************************************
 *
 *    Name:        Sensors_samplePanelmV 
 *    Returns:     Panel Voltage (mV)
 *    Parameter:   Nothing
 *    Description: Checks the Solar Panel voltage.
 *
 ******************************************/
int Sensors_samplePanelmV(void){
    int value = 2*analogRead(_PIN_SOLAR_V)*5000.0/1023;
    return value;
}

/*******************************************
 *
 *    Name:        Sensors_sampleSolarIrrmV 
 *    Returns:     Solar Irradiance Voltage (mV)
 *    Parameter:   Nothing
 *    Description: Checks the Solar Irradiance level.
 *
 ******************************************/
int Sensors_sampleSolarIrrmV(void){
    int value = analogRead(_PIN_APOGEE_V)*5000.0/1023;
    return value;
}

/*******************************************
 *
 *    Name:        Sensors_samplePressurepa 
 *    Returns:     Weather Pressure (pa)
 *    Parameter:   Nothing
 *    Description: Checks the current Pressure.
 *
 ******************************************/
int Sensors_samplePressurepa(void){
    int value = bmp085.readPressure();
    return value;
}

/*******************************************
 *
 *    Name:        Sensors_Humiditypct 
 *    Returns:     Humidity (pct)
 *    Parameter:   Nothing
 *    Description: Checks the current Humidity.
 *
 ******************************************/
int Sensors_sampleHumiditypct(void){
    int value =  sht1x.readHumidity();
    return value;
}

/*******************************************
 *
 *    Name:        Sensors_sampleTempdecic 
 *    Returns:     Temperature (Degrees C)
 *    Parameter:   Nothing
 *    Description: Checks the current Temperature.
 *
 ******************************************/
int Sensors_sampleTempdecic(void){
    int value =  bmp085.readTemperature()*10;
    return value ;
}
