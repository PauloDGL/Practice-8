#include "MKL27Z644.h"
#include "LP_UART.h"

void UART_vfnDriverInit (void)
{
	MCG->C1 |= MCG_C1_IRCLKEN(LIRC_On);		/* Low frec. internal reference clock set on 8Mh */
	MCG->C1 |= MCG_C1_CLKS(LIRC_Clock);    /*Selects LIRC as the main clock source*/
	MCG->C2 |= MCG_C2_IRCS(EightMHz_Mode);

	SIM->SOPT2 |= SIM_SOPT2_LPUART0SRC(MCGIRCLK_Clock); /*Selects the clock source for the LPUART0 transmit and receive clock*/
	SIM->SCGC5 |= SIM_SCGC5_LPUART0(ON); /*LPUART CLOCK*/

	PORTA->PCR[1] |= PORT_PCR_MUX(Alt_2); /*Selects the Alternative for the Pin A1 and A2 as LPUART*/
	PORTA->PCR[2] |= PORT_PCR_MUX(Alt_2);

	LPUART0->BAUD = ((LPUART_BAUD_OSR(7)) | (LPUART_BAUD_SBR(26)));// BAUD RATE = 8M(CLOCK)/SBR[12:0]*(OSR+1)
	LPUART0->CTRL |=  LPUART_CTRL_RE(ON); /*Declares PTA1 RX*/
	LPUART0->CTRL |= LPUART_CTRL_TE(ON); /*Declares PTA2 TX*/

return;

}

uint_8 LPUART_bfnSend (uint_8 bT_Data)
{
	uint_8 bStatus=0;

	if((LPUART0->STAT=LPUART_STAT_TDRE_MASK))
	{
		LPUART0 -> DATA = bT_Data;
		bStatus = SUCCESS;
	}
	else
	{
		bStatus = ERROR;
	}
	return bStatus;
}

uint_8 LPUART_bfnRead (uint_8 *bpR_Data)
{
	uint_8 bStatus = 0;

	if((LPUART0->STAT = LPUART_STAT_RDRF_MASK))
	{
		*bpR_Data = LPUART0-> DATA;
		bStatus = SUCCESS;
	}
	else
	{
		bStatus = ERROR;
	}
	return bStatus;
}
