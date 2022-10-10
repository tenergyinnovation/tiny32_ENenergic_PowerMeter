/***********************************************************************
 * Project      :     ENenergic_PowerMeter_searchAddress
 * Description  :     Search Address from Nenergic PowerMeter
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     19/09/2022
 * Revision     :     1.0
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-380-3299
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32_v3.h>

tiny32_v3 mcu; //define object

uint8_t id = 1; //Address of WATER-FLOW-METER sensor module, You can change here if it differance

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** ENenergic_PowerMeter_searchAddress[1-247] ****\r\n");
  mcu.library_version();
  mcu.WATER_FLOW_METER_begin(RXD2,TXD2);
  mcu.buzzer_beep(2); //buzzer 2 beeps
}

void loop()
{
   int8_t _id;
  
  _id = mcu.ENenergic_searchAddress();

  /* check result status */
  if(_id != -1)
  {
    Serial.printf("\r\nInfo: Address => %d\r\n",_id);
  }
  else
  {
    Serial.printf("\r\nError: Can't search address\r\n");
  }

  while(1);
}