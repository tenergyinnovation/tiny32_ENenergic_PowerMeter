/***********************************************************************
 * Project      :     Example_ENenergic_NeutralCurrent
 * Description  :     get NeuralCurrent IL1+IL2+IL3
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

float NeuralCurrent; // IL1+IL2+IL3
uint8_t id = 1;      // Modbus Address of ENenergic Power Meter

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** Example_ENenergic_NeutralCurrent ****\r\n");
  mcu.library_version();
  mcu.ENenergic_begin(RXD2, TXD2);
  mcu.buzzer_beep(2); // buzzer 2 beeps
}

void loop()
{
  NeuralCurrent = mcu.ENenergic_NeutralCurrent(id);
  if (NeuralCurrent != -1)
  {
    Serial.printf("Neural Current (IL1 + IL2 + IL3) = %.4f A\r\n", NeuralCurrent);
  }
  else
  {
    Serial.println("Error: can't get data");
  }
  vTaskDelay(1000);
}