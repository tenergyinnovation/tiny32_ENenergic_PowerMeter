/***********************************************************************
 * Project      :     Example_tiny32_ENenergic_PowerMeter_Current_L
 * Description  :     get Current L1,Current L2,Current L3
 * Hardware     :     tiny32
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     14/07/2022
 * Revision     :     1.0
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-380-3299
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32_v3.h>

tiny32_v3 mcu; // define object

float L1, L2, L3;
uint8_t id = 1; // Modbus Address of ENenergic Power Meter

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** Example_tiny32_ENenergic_PowerMeter_Current_L ****\r\n");
  mcu.library_version();
  mcu.tiny32_ENenergic_begin(RXD2, TXD2);
  mcu.buzzer_beep(2); // buzzer 2 beeps
}

void loop()
{

  if (mcu.tiny32_ENenergic_Current_L(id, L1, L2, L3))
  {
    Serial.printf("Current L1 = %.4f A\r\n", L1);
    Serial.printf("Current L2 = %.4f A\r\n", L2);
    Serial.printf("Current L3 = %.4f A\r\n", L3);
  }
  else
  {
    Serial.println("Error: can't get value");
  }
  Serial.println("------------------");
  vTaskDelay(1000);
}