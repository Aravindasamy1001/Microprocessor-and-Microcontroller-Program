#include<reg52.h>

#define led P1
volatile bit crossover = 0;

void delay(){
	int i,j;
	for(i=0;i<300;i++){
		for(j=0;j<300;j++){
		}
	}
}

void interp(void) interrupt 2{
	
	crossover = !crossover;
}

void main(){
	
	EA = 1;
	EX1 = 1;
	IT1 = 1;
	
	while(1){
		
		if(crossover){
    led = 0x55;
		}
else{
led = 0xAA;
}	
		}
	}
