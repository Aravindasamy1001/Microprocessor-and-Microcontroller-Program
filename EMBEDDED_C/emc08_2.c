#include<reg51.h>

sbit SW = P3^3;
sbit led1=P1^1;
sbit led2=P1^2;
sbit led3=P1^6;

int main(){
	
	while(1){
		if(SW==0){
			led1=0;
			led2=1;
			led3=0;
		}
		else
			led1=1;
		  led2=0;
		  led3=1;
	}
}