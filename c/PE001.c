#include <stdio.h>
#include <stdlib.h>

void main() {
	int cNum,xNumIng;
	unsigned long long nRes = 0;

	printf( "Ingrese el numero: " );
	scanf( "%d", &xNumIng);	

	for (cNum = 1; xNumIng > cNum; ++cNum) {
		if ((cNum % 3 == 0) || (cNum % 5 == 0)) {
			nRes += cNum;
		}
	}

	printf( "\nEl resultado es: %llu\n", nRes);
}
