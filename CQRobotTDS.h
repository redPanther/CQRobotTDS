 
/***************************************************
 DFRobot Gravity: Analog TDS Sensor/Meter
 <https://www.dfrobot.com/wiki/index.php/Gravity:_Analog_TDS_Sensor_/_Meter_For_Arduino_SKU:_SEN0244>
 
 ***************************************************
 This sample code shows how to read the tds value and calibrate it with the standard buffer solution.
 707ppm(1413us/cm)@25^c standard buffer solution is recommended.
 
 Created 2018-1-3
 By Jason <jason.ling@dfrobot.com@dfrobot.com>
 
 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution.
 ****************************************************/

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
