/***********************************************************************
 * Project      :     Example_ENenergic_Frequency
 * Description  :     get Frequency (Hz)
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

float freq;
uint8_t id = 1; // Modbus Address of ENenergic Power Meter

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** Example_ENenergic_Frequency ****\r\n");
  mcu.library_version();
  mcu.ENenergic_begin(RXD2, TXD2);
  mcu.buzzer_beep(2); // buzzer 2 beeps
}

void loop()
{

  freq = mcu.ENenergic_Freq(id);
  if (freq != -1)
  {
    Serial.printf("Frequency = %.4f Hz\r\n", freq);
  }
  else
  {
    Serial.println("Error: can't get data");
  }

  vTaskDelay(1000);
}