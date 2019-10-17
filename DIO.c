/*
 * DIO.c
 *
 * Created on: Sep 20, 2019
 *      Author: Mina Raouf
 */ 

#include "DIO.h"
#include "Reg.h"
#include "Std_Types.h"
#include "DIO_cnfg.h"

Std_Func_t DIO_init (PINS_t input)
{
	Std_Func_t retval = OK;
	if (input <= MAX_NUM_OF_PINS)
	{
		DIO_cnfg_arr[input].IS_init_arr = INITIALIZED;
		switch(DIO_cnfg_arr[input].PORT)
		{
		case PORT_A:
			if(DIO_cnfg_arr[input].DIR == OUTPUT)
			{
				DDRA |=(1u<<DIO_cnfg_arr[input].PIN);
				if (DIO_cnfg_arr[input].OUT == HIGH)
				{
					PORTA |=(1u<<DIO_cnfg_arr[input].PIN);
				}
				else if (DIO_cnfg_arr[input].OUT == LOW)
				{
					 PORTA &=~(1u<<DIO_cnfg_arr[input].PIN);
				}
				else
				{
					DIO_cnfg_arr[input].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
			}
			else if(DIO_cnfg_arr[input].DIR == INPUT)
			{
				 DDRA &=~(1u<<DIO_cnfg_arr[input].PIN);
				if (DIO_cnfg_arr[input].RES == PULLUP)
				{
					 PORTA |=(1u<<DIO_cnfg_arr[input].PIN);
				}
				else if (DIO_cnfg_arr[input].RES == EXTRES)
				{
					 PORTA &=~(1u<<DIO_cnfg_arr[input].PIN);
				}
				else
				{
					DIO_cnfg_arr[input].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
			}
			else
			{
				DIO_cnfg_arr[input].IS_init_arr = NOT_INITIALIZED;
				retval = NOK;
			}
			break;
		case PORT_B:
			if(DIO_cnfg_arr[input].DIR == OUTPUT)
			{
				 DDRB |=(1u<<DIO_cnfg_arr[input].PIN);
				if (DIO_cnfg_arr[input].OUT == HIGH)
				{
					 PORTB |=(1u<<DIO_cnfg_arr[input].PIN);
				}
				else if (DIO_cnfg_arr[input].OUT == LOW)
				{
					 PORTB &=~(1u<<DIO_cnfg_arr[input].PIN);
				}
				else
				{
					DIO_cnfg_arr[input].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
			}
			else if(DIO_cnfg_arr[input].DIR == INPUT)
			{
				 DDRB &=~(1u<<DIO_cnfg_arr[input].PIN);
				if (DIO_cnfg_arr[input].RES == PULLUP)
				{
					 PORTB |=(1u<<DIO_cnfg_arr[input].PIN);
				}
				else if (DIO_cnfg_arr[input].RES == EXTRES)
				{
					 PORTB &=~(1u<<DIO_cnfg_arr[input].PIN);
				}
				else
				{
					DIO_cnfg_arr[input].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
			}
			else
			{
				DIO_cnfg_arr[input].IS_init_arr = NOT_INITIALIZED;
				retval = NOK;
			}
			break;
		case PORT_C:
			if(DIO_cnfg_arr[input].DIR == OUTPUT)
			{
				 DDRC |=(1u<<DIO_cnfg_arr[input].PIN);
				if (DIO_cnfg_arr[input].OUT == HIGH)
				{
					 PORTC |=(1u<<DIO_cnfg_arr[input].PIN);
				}
				else if (DIO_cnfg_arr[input].OUT == LOW)
				{
					 PORTC &=~(1u<<DIO_cnfg_arr[input].PIN);
				}
				else
				{
					DIO_cnfg_arr[input].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
			}
			else if(DIO_cnfg_arr[input].DIR == INPUT)
			{
				 DDRC &=~(1u<<DIO_cnfg_arr[input].PIN);
				if (DIO_cnfg_arr[input].RES == PULLUP)
				{
					 PORTC |=(1u<<DIO_cnfg_arr[input].PIN);
				}
				else if (DIO_cnfg_arr[input].RES == EXTRES)
				{
					 PORTC &=~(1u<<DIO_cnfg_arr[input].PIN);
				}
				else
				{
					DIO_cnfg_arr[input].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
			}
			else
			{
				DIO_cnfg_arr[input].IS_init_arr = NOT_INITIALIZED;
				retval = NOK;
			}
			break;
		case PORT_D:
			if(DIO_cnfg_arr[input].DIR == OUTPUT)
			{
				 DDRD |=(1u<<DIO_cnfg_arr[input].PIN);
				if (DIO_cnfg_arr[input].OUT == HIGH)
				{
					 PORTD |=(1u<<DIO_cnfg_arr[input].PIN);
				}
				else if (DIO_cnfg_arr[input].OUT == LOW)
				{
					 PORTD &=~(1u<<DIO_cnfg_arr[input].PIN);
				}
				else
				{
					DIO_cnfg_arr[input].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
			}
			else if(DIO_cnfg_arr[input].DIR == INPUT)
			{
				 DDRD &=~(1u<<DIO_cnfg_arr[input].PIN);
				if (DIO_cnfg_arr[input].RES == PULLUP)
				{
					 PORTD |=(1u<<DIO_cnfg_arr[input].PIN);
				}
				else if (DIO_cnfg_arr[input].RES == EXTRES)
				{
					 PORTD &=~(1u<<DIO_cnfg_arr[input].PIN);
				}
				else
				{
					DIO_cnfg_arr[input].IS_init_arr = NOT_INITIALIZED;
					retval = NOK;
				}
			}
			else
			{
				DIO_cnfg_arr[input].IS_init_arr = NOT_INITIALIZED;
				retval = NOK;
			}
			break;
		default:
			DIO_cnfg_arr[input].IS_init_arr = NOT_INITIALIZED;
			retval = NOK;
		}
	}
	else
	{
		DIO_cnfg_arr[input].IS_init_arr = NOT_INITIALIZED;
	}
	retval = NOK;
	return retval;
}

Std_Func_t DIO_read (uint8 port,uint8 pin)
{
	Std_Func_t retval = OK;

	switch (port)
	{
	case PORT_A:
		if(( PINA) & (1<<(pin)))
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
	case PORT_B:
		if(( PINB) & (1<<(pin)))
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
	case PORT_C:
		if(( PINC) & (1<<(pin)))
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
	case PORT_D:
		if(( PIND) & (1<<(pin)))
						{
							return 1;
						}
						else
						{
							return 0;
						}
		break;
	}

	return retval;
}

Std_Func_t DIO_write (uint8 port,uint8 pin,uint8 val, PINS_t input)
{
	Std_Func_t retval = OK;
	if ((DIO_cnfg_arr[input].PORT == port)&&(DIO_cnfg_arr[input].PIN == pin))
	{
		if(((DIO_cnfg_arr[input].IS_init_arr == INITIALIZED))
				&&(DIO_cnfg_arr[input].DIR == OUTPUT)
				&&((val == HIGH)||(val == LOW)))
		{
			switch (port)
			{
			case PORT_A:
				if (val == HIGH)
				{
					 PORTA |=(1u<<pin);
				}
				else
				{
					 PORTA &=~(1u<<pin);
				}
				break;
			case PORT_B:
				if (val == HIGH)
				{
					 PORTB |=(1u<<pin);
				}
				else
				{
					 PORTB &=~(1u<<pin);
				}
				break;
			case PORT_C:
				if (val == HIGH)
				{
					 PORTC |=(1u<<pin);
				}
				else
				{
					 PORTC &=~(1u<<pin);
				}
				break;
			case PORT_D:
				if (val == HIGH)
				{
					 PORTD |=(1u<<pin);
				}
				else
				{
					 PORTD &=~(1u<<pin);
				}
				break;
			}
		}
		else
		{
			retval = NOK;
		}
	}
	else
	{
		retval = NOK;
	}
	return retval;
}
