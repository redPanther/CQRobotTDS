#include "CQRobotTDS.h"

/*
 * TDS sensor is connected to analog port A0
 * 
 */

CQRobotTDS tds(A0);
unsigned long timeout = 0;

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	float temp = 20.0; // read temprature from a real sensor
	float tdsValue = tds.update(temp);

	if (timeout<millis())
	{
		Serial.print("TDS value: ");
		Serial.print(tdsValue, 0);
		Serial.println(" ppm");
		timeout=millis() + 1000;
	}
}

