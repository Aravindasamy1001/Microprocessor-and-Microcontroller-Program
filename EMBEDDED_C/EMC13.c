#include<reg52.h>

sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;

#define lcd P2

void delay(){
	int i,j;
	for(i=0;i<200;i++){
		for(j=0;j<200;j++){
		}
	}
}

void com(unsigned char c){
	RS = 0;
	RW = 0;
	lcd = c; 
	EN = 1;
	delay();
	EN = 0;
}
void dataa(unsigned char d){
	RS = 1;
	RW = 0;
	lcd = d;
	EN = 1;
	delay();
	EN = 0;
}

void sen(char *b){
	while(*b){
		dataa(*b++);
	}
}

void main(){
	
	com(0x38);
	com(0x0C);
	com(0x06);
	com(0x01);
	com(0x80);
	sen("Aravind samy");
	
	while(1){
		com(0x18);
		delay();
	}
}
