/*
 *  Led 7 doan anode chung 
 *  Created: 5/1/2020 10:23:09 PM
 *  Author : Ngo Minh Khanh
 */ 

#include <avr/io.h>
#include <util/delay.h>

// Set tan so
#define F_CPU 16000000UL

// Set 1 bit nao do trong register len muc 1 (Set Bit in Register)
#define sbi(port,bit) { port |= (1<<bit); }

// Clear 1 bit nào do trong register xuong muc 0(Clear Bit in Register)
#define cbi(port,bit) { port &= ~(1<<bit); }

// Dao 1 bit nao do trong register (Toggle Bit in Register)
#define tbi(port,bit) { port ^= (1<<bit); }
           
 // 7seg LED bit pattern -  Dgfe dcba
 const int n0 = 0xC0;    // 1100 0000
 const int n1 = 0xF9;    // 1111 1001
 const int n2 = 0xA4;    // 1010 0100
 const int n3 = 0xB0;    // 1011 0000
 const int n4 = 0x99;    // 1001 1001
 const int n5 = 0x92;    // 1001 0010 
 const int n6 = 0x82;    // 1000 0010
 const int n7 = 0xF8;    // 1111 1000
 const int n8 = 0x80;    // 1000 0000
 const int n9 = 0x90;    // 1001 0000
 // Pin               -     7654 3210
int main(void)
{
	const int led7Seg[] = {n0, n1, n2, n3, n4, n5, n6, n7, n8, n9};
	int count = 0;
	
    DDRA = 0b11111111;  // A7 -> A0 la output 
	PORTA = 0x11111111; // Xuat 5v cho A7 -> A0
	
    while (1) 
    {
		PORTA = led7Seg[count];
		count++;
		if(count==10) count=0;
		_delay_ms(10000);
    }
}

