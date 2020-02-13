#include "DELAY.h"
#include "MKL27Z644.h"

extern void vfnDelay(void){

	for (uint_16 dwCuenta=0; dwCuenta < SECONDS; dwCuenta++)
			dwCuenta += 1;
}
