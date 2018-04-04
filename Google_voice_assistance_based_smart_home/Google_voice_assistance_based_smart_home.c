/////////////////////////////////////////////////////////////////////////////////////////////////////
///  Project Name : Google_voice_assistance_based_smart_home
//
//  Target Board : atmega32
//
//  Date Created : 04-Apr-18 5:18:38 AM
// 
//  Online Resource  : www.electronicsforstudents.com
//
//  Libraries Included : -->wifiadvanced 
/////////////////////////////////////////////////////////////////////////////////////////////////////


#include<avr/io.h>
#include<util/delay.h>
#include "setup.h"
#include "serial.h"
#include "clobous.h"
#include "lcd.h"



int main()
{
	
	complete_setup();
	wifi_connect("Hari","Hari_Yogesh");
	lcd_string("wifi cntd");
	_delay_ms(1000);
	while (1)
	{
		data_retrieve("vr",data);
		lcd_clear();
		lcd_string(data);
		
		if(compare(data,"hall_on"))
		{
			
			hall_light_on;
		}
		else  if(compare(data,"hall_off"))
		{
			
			hall_light_off;
			
		}
		else if(compare(data,"kit_on"))
		{
			kitchen_light_on;
		
		}
		else if(compare(data,"kit_off"))
		{
			kitchen_light_off;
			
		}
		 
		else if(compare(data,"room_on"))
		{
			
			room_light_on;
		}
		 else if(compare(data,"room_off"))
		{
			
			room_light_off;
			
		}
		else if(compare(data,"dine_on"))
		{
			
			dinning_light_on;
		}
		else  if(compare(data,"dine_off"))
		{
			
			dinning_light_off;
			
		}
	    else	if(compare(data,"on"))
		{
		   
		   all_lights_on();
			
		}
		else  if(compare(data,"off"))
		{
			all_lights_off();
			
		}
		else
		{
			lcd_string("TRY CONTROLING");
		}

	}

}