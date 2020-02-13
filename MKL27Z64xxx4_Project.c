#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL27Z644.h"
#include "fsl_debug_console.h"
#include "LP_UART.h"
#include "TurnON_CLKS.h"
#include "DELAY.h"

int main(void)
{
uint_8  bFullSend;
volatile uint_8 bFullRecieve = 0;
uint_8 bData = 0;

	ClockPORTS_vfnDriverInit ();
	UART_vfnDriverInit ();

	while(1)
	{
		bFullRecieve = LPUART_bfnRead (&bData);

		vfnDelay();

		bFullSend = (bFullRecieve&1)? LPUART_bfnSend (bData+1): ERROR;

	}
    return 0 ;
}
