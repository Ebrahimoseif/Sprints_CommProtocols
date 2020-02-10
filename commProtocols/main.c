/*
 * commProtocols.c
 *
 * Created: 2/8/2020 9:09:20 PM
 * Author : EbrahimOseif
 */ 


#include "USART.h"
#include "SPI.h"
#include "std_types.h"
#include "registers.h"
#include "util/delay.h"


int main(void)
{
    /* Replace with your application code */
 
	
		 
		 
	
	USART_Init();
	USART_Transmit('k');
	PORTC_DIR = 0xff;
	PORTC_DATA = 0 ; 
	
	
	uint16_t data;
	
	 PORTC_DIR = 0xff;
	 PORTC_DATA = 0;
	 PORTB_DIR = (1<<4)|(1<<5)|(1<<7);
	 

	SPI_Init();
	uint8_t DATA = 170 ;
	SPI_Send_And_receive(DATA);
	PORTC_DATA = 32;
    while (1) 
    {	
		DATA++;
		if(SPI_Send_And_receive(DATA)){
			USART_Transmit('k');
			PORTC_DATA = DATA;
    }
	}
	
	
	
}

