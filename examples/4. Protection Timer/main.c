#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "uMicroLibrary/inc/uGlobal.h"
#include "uMicroLibrary/inc/uTime.h"

int main(int argc, char const *argv[]){
	// Add protector timer structure
	uProtectorTimer protect;

	// Init hysteresis data with +10 degree disable value, and +15 degree enable value
	uLogica_TimeProtectorInit(&protect, 300, 90, 35);

	// Add state ( for example: Some device is disable at start )
	uState connection = uDisabled;

	// Run test loops with changing the device state in some cases and add pause in action 
	for (int i = 0; i < 2000; i++)
	{
		printf( "Protect: %d, 0x%02x\n", i, uLogica_TimeProtectorCompare(&protect, i, connection) );
		printf( "First time:, %d; Was activated: 0x%02x; Last time: %d\n", protect.firstTime, protect.wasActivated, protect._lastTimeForReset );
		if(i == 150)
			connection = uEnabled;
		if(i == 600)
			connection = uDisabled;
		if(i == 650)
			connection = uEnabled;
		if(i == 700)
			uLogica_TimeProtectorSetStage(&protect, uProtector_Reset, i);
		if(i > 1000 && i < 1100)
			uLogica_TimeProtectorPause(&protect, uDisabled);
	}
	return 0;
}