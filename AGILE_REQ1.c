


#include "DIO.h"
#include "UART.h"
#include "TIMER.h"
#include <avr/interrupt.h>
#include "stdlib.h"
#include "LCD.h"
#include"keypad.h"

static uint8 counter=0;
static uint8 sec=0;
static uint8 speed;
static uint8 recieve=0;
int main(void)
{
	//DDRC &= ~(1<<PIN4);
	LCD_init();

	Timer_Init(TIMER_1);
	Timer_SetPrescaler(TIMER_1);
	Timer_Start(TIMER_1);


	UART_Init();

	LCD_gotoRawCol(0,0);

	LCD_gotoRawCol(0,10);


	LCD_displayStrRowCol(1,0,"Time: ");
	LCD_displayStrRowCol(0,0,"Speed: ");
	speed=KeyPad_getPressedKey();
	_delay_ms(250);
	speed= (speed *10) +KeyPad_getPressedKey();
	LCD_gotoRawCol(0,6);
	LCD_IntToStr(speed);
	DIO_init(2);
	sei();
	while(1)
	{
		LCD_gotoRawCol(1,6);
		LCD_IntToStr(sec);
		LCD_displayString("    ");


		if(DIO_read(PORT_B,PIN2))
		{
			_delay_ms(250);
				speed++;
		}
		LCD_gotoRawCol(0,6);
		LCD_IntToStr(speed);
		LCD_displayString("    ");

		if(recieve == 'g')
		{
			UART_Send(speed);
			_delay_ms(1);
			UART_Send(sec);
			recieve=0;

		}
	}
}

ISR(TIMER1_OVF_vect)
{
	counter++;

	if(counter == 2)
	{
		sec++;

		counter=0;
	}

}


ISR(USART_RXC_vect)
{
	recieve =UDR;
}

