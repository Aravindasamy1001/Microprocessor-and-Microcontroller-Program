#include<reg52.h>

sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;
sbit SW = P3^3;

#define lcd P2
sbit led1 = P1^0;
sbit led2 = P1^1;

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
	lcd = c;
  EN = 1;
  delay();
  EN = 0;
}

void datt(unsigned char d){
	
	RS = 1;
	RW = 0;
	lcd = d;
  EN = 1;
  delay();
  EN = 0;
}

void lcd_data(char *s){
	while(*s){
		datt(*s++);
	}
}
void main(){
	
cmd(0x38);
cmd(0x0C);
cmd(0x06);
cmd(0x01);
cmd(0x80);

while(1){
		if(SW == 0){
			
			led1 = 0;
			led2 = 1;
			cmd(0x01);
			cmd(0x80);
			lcd_data("LED1 in ON.");
		}
		else
		{
			led1 = 1;
			led2 = 0;
			cmd(0x01);
			cmd(0x80);
			lcd_data("LED2 is ON.");
		}
		delay();
	}
}