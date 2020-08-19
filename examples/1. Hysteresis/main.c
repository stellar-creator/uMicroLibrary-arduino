#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "../../inc/uGlobal.h"
#include "../../inc/uLogica.h"

int main(int argc, char const *argv[]){
	// Инициализируем гистерезис
	uHysteresisData hyst;
	uRangeComparator compr;
	uRangeHysteresis range;
	uProtectorTimer protect;
	// Регистрируем значение
	uLogica_HysteresisInit(&hyst, 10, 5);

	for (int i = -25; i < 25; i++)
	{
		printf("1. %d, 0x%02x\n", i, uLogica_HysteresisCompare(&hyst, i));
	}

	for (int i = 25; i > -25; i--)
	{
		printf("-1. %d, 0x%02x\n", i, uLogica_HysteresisCompare(&hyst, i));
	}

	uLogica_RangeComparatorInit(&compr, 10, 12, 18, 22);
	
	for (int i = -25; i < 25; i++)
	{
		printf("2.\t %d, 0x%02x\n", i, uLogica_RangeComparatorCompare(&compr, i));
	}

	for (int i = 25; i > -25; i--)
	{
		printf("-2.\t %d, 0x%02x\n", i, uLogica_RangeComparatorCompare(&compr, i));
	}


	uLogica_RangeHysteresisInit(&range, 10, 15);
	
	for (int i = -25; i < 25; i++)
	{
		printf("3.\t\t %d, 0x%02x\n", i, uLogica_RangeHysteresisCompare(&range, i));
	}

	for (int i = 25; i > -25; i--)
	{
		printf("-3.\t\t %d, 0x%02x\n", i, uLogica_RangeHysteresisCompare(&range, i));
	}

	uLogica_TimeProtectorInit(&protect, 300, 90, 35);

	uState connection = uDisabled;

	for (int i = 0; i < 2000; i++)
	{
		printf("Protect: %d, 0x%02x\n", i, uLogica_TimeProtectorCompare(&protect, i, connection));
		printf("First time:, %d; Was activated: 0x%02x; Last time: %d\n", protect.firstTime, protect.wasActivated, protect._lastTimeForReset);
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