#ifndef util_h
#define util_h
// To put (1) in a specific Bit. We use SET_BIT Macro Function.
#define SET_BIT(var,bitposition) var = var | (1<<bitposition) 	
// To Put (0) In a specific Bit. We use CLEAR_BIT Macro Function.
#define CLEAR_BIT(var,bitposition) var = var & (~(1<<bitposition))
// To reverse a specific bit [Put 0 if 1, Put 1 if 0]. We use TOGGLE_BIT Macro Function.
#define TOGGLE_BIT(var,bitposition) var = var ^ (1<<bitposition)		
// To Put 0 in all the other bits and keep the bit constant. We use GET_BIT Macro Function.
#define GET_BIT(var,bitposition) (var & (1<<bitposition))>>bitposition		
// To Put (1) in the register "8 bits". We use SET_REGISTER Macro Function.
#define SET_REGISTER(var) var = 0xff
// To Put (0) in the register "8 bits". We use CLEAR_REGISTER Macro Function.
#define CLEAR_REGISTER(var) var = 0x00
// To call The Register "8 bits". We use GET_REGISTER Macro Function.
#define GET_REGISTER(var) var
//  To put a value in the register "8 bits". We use WRITE_REGISTER Macro Function.
#define WRITE_REGISTER(var,value) var = value
#endif