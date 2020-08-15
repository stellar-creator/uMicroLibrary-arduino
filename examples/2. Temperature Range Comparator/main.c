#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "uMicroLibrary/inc/uGlobal.h"
#include "uMicroLibrary/inc/uLogica.h"

int main(int argc, char const *argv[]){
	// Add range comparator structure
	uRangeComparator compr;

	// Init range comparator data with +10 degree lower trip level, +12 ower switching threshold, +18 maximum level of work, maximum shutdown level
	uLogica_RangeComparatorInit(&compr, 10, 12, 18, 22);
	
	// Run test loops
	for (int i = -25; i < 25; i++){
		printf("First: \t %d, 0x%02x\n", i, uLogica_RangeComparatorCompare(&compr, i) );
	}

	for (int i = 25; i > -25; i--){
		printf("Second: \t %d, 0x%02x\n", i, uLogica_RangeComparatorCompare(&compr, i) );
	}
	return 0;
}