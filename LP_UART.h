#ifndef LP_UART_H_
#define LP_UART_H_
#define LIRC_On 1
#define LIRC_Clock 1
#define EightMHz_Mode 1
#define MCGIRCLK_Clock 3
#define ON 1
#define Alt_2 2
#define SUCCESS 1
#define ERROR 0

typedef unsigned char uint_8;

	extern void UART_vfnDriverInit (void);
	extern uint_8 LPUART_bfnRead (uint_8 *bpData);
	extern uint_8 LPUART_bfnSend (uint_8 bData);


#endif
/*Two different buffers*/
