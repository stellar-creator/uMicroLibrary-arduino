#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "uMicroLibrary/inc/uGlobal.h"
#include "uMicroLibrary/inc/uLogica.h"

int main(int argc, char const *argv[]){
	// Add hysteresis structure
	uHysteresisData hyst;
	
	// Init hysteresis data with +10 degree and +/- 5 degree hysteresis (for example)
	uLogica_HysteresisInit(&hyst, 10, 5);

	// Run test loops
	for (int i = -25; i < 25; i++){
		printf( "First:\t %d, 0x%02x\n", i, uLogica_HysteresisCompare(&hyst, i) );
	}

	for (int i = 25; i > -25; i--){
		printf( "Second:\t %d, 0x%02x\n", i, uLogica_HysteresisCompare(&hyst, i) );
	}

	return 0;
}