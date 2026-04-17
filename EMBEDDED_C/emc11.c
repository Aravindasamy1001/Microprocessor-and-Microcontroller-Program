#include<reg52.h>

sbit RS=P3^0;
sbit EN=P3^1;
sbit RW=P3^2;

#define lcd P2

delay(){
	unsigned int i,j;
	for(i=0;i<200;i++){
		for(j=0;j<200;j++){
		}
	}
}

void cmd(unsigned char c){
	
	RS = 0;
  RW=0;
	lcd = c;
	EN = 1;
	delay();
	EN = 0;
}

void dat (unsigned char d){
	
	RS = 1;
	RW=0;
	lcd = d;
	EN = 1;
	delay();
	EN = 0;
}

void main(){
	
	cmd(0x38);
	cmd(0x0C);
	cmd(0x06);
	cmd(0x01);
	cmd(0x80);
	
	dat('A');
	dat('r');
	dat('a');
	dat('v');
	dat('i');
	dat('n');
	dat('d');
	
	while(1);
}