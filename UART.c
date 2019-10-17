/*
 * UART.c
 *
 *  Created on: Oct 11, 2019
 *      Author: Rafaat
 */
#include "UART.h"

void UART_Init()
{
UCSRB |=1<<RXEN|1<<TXEN|1<<RXCIE;
UCSRC |=1<<UCSZ1|1<<UCSZ0|1<<URSEL;
UBRRL = 0x33 ;
}

void UART_Send(uint8 Char)
{
	while(!(UCSRA&(1<<UDRE)));
	UDR=Char;
}

uint8 UART_Recieve()
{
	while(!(UCSRA&(1<<RXC)));
	return UDR;
}

