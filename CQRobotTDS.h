#ifndef CQROBOT_H
#define CQROBOT_H

#include "Arduino.h"
#define CQROBOT_SCOUNT  30


class CQRobotTDS
{
public:
	CQRobotTDS(int pin, float aref=5.0);
	~CQRobotTDS();

	float update(); //read and calculate
	float update(float temp); //read and calculate
	void setTemperature(float temp);  //set the temperature and execute temperature compensation
	void setAdcRange(float range);  //1024 for 10bit ADC;4096 for 12bit ADC
	float getTdsValue();

private:
	int pin;
	float aref;  // default 5.0V on Arduino UNO
	float adcRange;
	float temperature;
 
	float tdsValue;
	int analogBuffer[CQROBOT_SCOUNT];    // store the analog value in the array, read from ADC
	int analogBufferTemp[CQROBOT_SCOUNT];
	int analogBufferIndex = 0;
	int copyIndex = 0;
	float averageVoltage = 0;

	int getMedianNum(int bArray[], int iFilterLen);
};

#endif
