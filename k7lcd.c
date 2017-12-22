#include <reg51.h>
sbit R0=P1^0;
sbit R1=P1^1;
sbit R2=P1^2;
sbit R3=P1^3;
sbit C0=P1^4;
sbit C1=P1^5;
sbit C2=P1^6;
sbit rs=P3^4;
sbit rw=P3^5;
sbit e= P3^6;
void delay();
void cmd(unsigned int);
void dat(unsigned char);

void main(void)
{
	
	cmd(0x38);
	cmd(0x01);
	cmd(0x0c);
	cmd(0x80);
	cmd(0x06);
while(1)
{	
	R0=R1=R2=R3=1;
	R0=0;
	if(C0==0)
	{	
  dat('1');
	while(C0==0);
	}
		R0=R1=R2=R3=1;
	R0=0;
	if(C1==0)
	{	
	 dat('2');
	while(C1==0);
  }
		R0=R1=R2=R3=1;
	R0=0;
	if(C2==0)
	{
	  dat('3');
	while(C2==0);
	}
  
		R0=R1=R2=R3=1;
	R1=0;
	if(C0==0)
	{	
	dat('4');
		while(C0==0);
  }
	
		R0=R1=R2=R3=1;
	R1=0;
	if(C1==0)
	{	
	dat('5');
	while(C1==0);
  }
	R0=R1=R2=R3=1;
	R1=0;
	if(C2==0)
		
{
	dat('6');
	while(C2==0);
}
		R0=R1=R2=R3=1;
	R2=0;
	if(C0==0)
		
	{
	dat('7');
	while(C0==0);
  }
		R0=R1=R2=R3=1;
	R2=0;
	if(C1==0)
	{	
	dat('8');
	while(C1==0);
	}
		R0=R1=R2=R3=1;
	R2=0;
	if(C2==0)
	{	
    dat('9');
		while(C2==0);
	}
	R0=R1=R2=R3=1;
	R3=0;
	if(C1==0)
		{
	    dat('0');
			while(C1==0);
}
}	
}
void delay()
{
	int i;
	e=1;
	for(i=0;i<30000;i++);
	e=0;
}

void cmd(unsigned int ch)
{
	rs=0;
	rw=0;
	P2=0x00;
	P2=ch;
	delay();
}
void dat(unsigned char ch)
{
	rs=1;
	rw=0;
	P2=0x00;
	P2=ch;
	delay();
}	

		
