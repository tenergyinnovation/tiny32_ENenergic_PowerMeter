/***********************************************************************
 * Project      :     Example_ENenergic_PowerMeter_Volt_L-N
 * Description  :     get Voltage L1-N, Voltage L2-N, Voltage L3-N
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

float L1_N, L2_N, L3_N;
uint8_t id = 1; // Modbus Address of ENenergic Power Meter

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** Example_ENenergic_PowerMeter_Volt_L-N ****\r\n");
  mcu.library_version();
  mcu.ENenergic_begin(RXD2, TXD2);
  mcu.buzzer_beep(2); // buzzer 2 beeps
}

void loop()
{

  if (mcu.ENenergic_Volt_L_N(id, L1_N, L2_N, L3_N))
  {
    Serial.printf("Voltage L1-N = %.4f V\r\n", L1_N);
    Serial.printf("Voltage L2-N = %.4f V\r\n", L2_N);
    Serial.printf("Voltage L3-N = %.4f V\r\n", L3_N);
  }
  else
  {
    Serial.println("Error: can't get value");
  }
  Serial.println("------------------");
  vTaskDelay(1000);
}