/***********************************************************************
 * Project      :     tiny32_ENenergic_getTemperature
 * Description  :     get internal temperature from ENenergic Powermeter
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

float temperature;
uint8_t id = 1; // Modbus Address of ENenergic Power Meter

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_ENenergic_getTemperature ****\r\n");
  mcu.library_version();
  mcu.tiny32_ENenergic_begin(RXD2, TXD2);
  mcu.buzzer_beep(2); // buzzer 2 beeps
}

void loop()
{

  temperature = mcu.tiny32_ENenergic_getTemperature(id);
  if (temperature != -1)
  {
    Serial.printf("ENenergic Temperature = %.4f C\r\n", temperature);
  }
  else
  {
    Serial.println("Error: can't get value");
  }
  vTaskDelay(1000);
}