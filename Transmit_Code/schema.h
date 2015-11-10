/*
	File: schema.h

	Description: This file contains the structure for our packet schema.
	The packet schema keeps all of the variables for the functions which
	we'll send to the XBee API to be transmitted.
	
	Notes: When a new packet schema is made, create a new structure.
	BINARY packet is position dependent on where everything is placed
	and sent.
*/

#include <stdint.h>

typedef struct {
    
    uint16_t schema;
    uint16_t address;		//Address of Arduino
    
    uint8_t overflow_num;	//Number of times function millis() overflowed
    				//Happens every ~49 days

    uint32_t uptime_ms;		//Time since the start of program
    uint8_t n;			//Number of data points in packet (0...30)
    uint16_t batt_mv[6];	//Battery voltage (millivolts)
    uint16_t panel_mv[6];	//Panel voltage (millivolts)
    uint32_t bmp085_press_pa;	//Pressure value (pascals)
    int16_t bmp085_temp_decic;	//Temperature value (celsius)
    uint16_t humidity_centi_pct;
    uint16_t apogee_w_m2[20];

} schema_3;



