#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "uMicroLibrary/inc/uGlobal.h"
#include "uMicroLibrary/inc/uLogica.h"

int main(int argc, char const *argv[]){
	// Add range range hysteresis structure
	uRangeHysteresis range;

	// Init range hysteresis data with +10 degree disable value, and +15 degree enable value
	uLogica_RangeHysteresisInit(&range, 10, 15);
	
	// Run test loops
	for (int i = -25; i < 25; i++)
	{
		printf("First: \t %d, 0x%02x\n", i, uLogica_RangeHysteresisCompare(&range, i) );
	}

	for (int i = 25; i > -25; i--)
	{
		printf("Second: \t %d, 0x%02x\n", i, uLogica_RangeHysteresisCompare(&range, i) );
	}

	return 0;
}