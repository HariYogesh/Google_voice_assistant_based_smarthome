#ifndef _setup_H_
#define _setup_H_

#define cloudid "s33915"
#define INTERNET WIFI

#define hall_light_on write(portb,0,l)
#define hall_light_off write(portb,0,h)

#define kitchen_light_on write(portb,1,l)
#define kitchen_light_off write(portb,1,h)

#define room_light_on write(portb,4,l)
#define room_light_off write(portb,4,h)

#define dinning_light_on write(portb,5,l)
#define dinning_light_off write(portb,5,h)


typedef char variable;	
typedef int count;

variable data[20];
count  i=0;

all_lights_on()
{ 
			count i=0;
			for(i=0;i<6;i++)	
			write(portb,i,l);
}
all_lights_off()
{ 
			count i=0;
			for(i=0;i<6;i++)	
			write(portb,i,h);
}
void complete_setup()
{

	lcd_init();
	lcd_string("Google_Assistance");
	_delay_ms(1000);
	serial_init(9600);
	serial_select(2);
	wifi_init();
}


#endif 