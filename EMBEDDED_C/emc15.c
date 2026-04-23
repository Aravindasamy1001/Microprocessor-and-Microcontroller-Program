#include<reg52.h>

sbit RS =P3^0;
sbit RW =P3^1;
sbit SW =P3^3;
sbit EN =P3^2;

#define LCD P2

void delay(){
	int i,j;
	for(i=0;i<200;i++){
		for(j=0;j<200;j++){
		}
	}
}

void cmd(unsigned char c){
	
	RS = 0;
	RW = 0;
	LCD = c;
	EN = 1;
	delay();
	EN = 0;
}

void datt(unsigned char d){
	
	RS = 1;
	RW = 0;
	LCD = d;
	EN = 1;
	delay();
	EN = 0;
}

void lcd_data(char *str){
	while(*str){
		datt(*str++);
	}
}
void main(){
  
	cmd(0x38);
	cmd(0x0C);
	cmd(0x06);
	cmd(0x01);
	
while(1){
	if(SW == 0){
		cmd(0x01);
		
		cmd(0xC0);
		lcd_data("switch is ON");
	}
	else
	{
		cmd(0xC0);
	lcd_data("switch is OFF");
	}
cmd(0x18);
	
 }
	
}
