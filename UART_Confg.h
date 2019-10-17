/*
 * UART_Confg.h
 *
 *  Created on: Oct 11, 2019
 *      Author: Rafaat
 */

#ifndef UART_CONFG_H_
#define UART_CONFG_H_

#include "Std_Types.h"
typedef enum{DISABLED,REVERSED,EVEN_PARITY,ODD_PARITY}Parity_Mode;
typedef enum{ONE_STOP_BIT,TWO_STOP_BITS}Stop_Bits;
typedef enum{_5_BITS,_6_BITS,_7_BITS,_8_BITS,RESERVED_0,RESERVED_1,RESERVED_2,_9_BITS}Bits_Number;
typedef enum{RISING_EDGE,FALLING_EDGE}CLCK_Edge;
typedef enum{RX_EN,RX_DS}RX;
typedef enum{TX_EN,TX_DS}TX;
typedef enum{RXI_EN,RXI_DS}RX_INT;
typedef enum{TXI_EN,TXI_DS}TX_INT;

#define BAUD	9600
#define UBRR_LOAD	(8000000/(16*(BAUD)))-1
#define NA	0xFFb


typedef struct
{
	uint8 TxEN;
	uint8 RxEn;
	uint8 Baud;
	uint8 TxINT;
	uint8 RxINT;
	uint8 Parity;
	uint8 StopBits;
	uint8 BitNumber;
	uint8 ClkPolarity;
}UART_cnfg_t;

extern UART_cnfg_t UART_cnfg;

#endif /* UART_CONFG_H_ */
