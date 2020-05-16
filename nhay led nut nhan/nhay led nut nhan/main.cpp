/*
 *  Nhay led dung nut nhan
 *  Created: 5/1/2020 3:41:30 PM
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

int main(void)
{
    DDRA = 0b10000000;   // output o chân A7
	while (1)
	{
		PORTA = 0b10000001; // A7 xuat 5V, A0 là tro treo
		if(bit_is_clear(PINA,PA0))   // bit_is_clear: kiem tra 1 bit nao do la muc logic 0 hay ko
		{
			_delay_ms(20);  // Chong doi phim
			
			if(bit_is_clear(PINA,PA0)) 
			{
				 tbi(PORTA,PA7);
				 while( bit_is_clear(PINA,PA0) );  // Dung tai day kho muc logic la 0 
			}
		}
	}
	
}

