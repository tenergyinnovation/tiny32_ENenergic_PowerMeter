/***********************************************************************
 * Project      :     Example_ENenergic_PhaseCurrent_Angle
 * Description  :     get ActivePower L1-N, ActivePower L2-N, ActivePower L3-N
 * Hardware     :     tiny32
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14/07/2022
 * Revision     :     1.0
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-308-3299
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32_v3.h>

tiny32_v3 mcu; // define object

float L1, L2, L3;
uint8_t id = 1; // Modbus Address of ENenergic Power Meter

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** Example_ENenergic_PhaseCurrent_Angle ****\r\n");
  mcu.library_version();
  mcu.ENenergic_begin(RXD2, TXD2);
  mcu.buzzer_beep(2); // buzzer 2 beeps
}

void loop()
{

  if (mcu.ENenergic_PhaseCurrent_Angle(id, L1, L2, L3))
  {
    Serial.printf("Phase Current L1 = %.4f Degree\r\n", L1);
    Serial.printf("Phase Current L2 = %.4f Degree\r\n", L2);
    Serial.printf("Phase Current L3 = %.4f Degree\r\n", L3);
  }
  else
  {
    Serial.println("Error: can't get value");
  }

  Serial.println("------------------");
  vTaskDelay(1000);
}