#include<reg52.h>

unsigned int  count =0;
#define led P1

void timer(void) interrupt 1{
	
	TH0 = 0x9E;
	TL0 = 0x58;
	count++;
	
if(count>=10){

	led = ~led;
  count =0;	
 }
}

void main(){
	
		
	led = 0x44;
	
	TMOD = 0x01;
	
	TH0 = 0x9E;
	TL0 = 0x58;
	
	EA  = 1;
	ET0 = 1;
	TR0 = 1;
	
	while(1){
	}
}