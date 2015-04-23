// Compilar como gcc PE448.c -o PE448 -O2 -march=native && PE448 20000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LONG_TABLA 5000

unsigned short tabla[LONG_TABLA][LONG_TABLA];

unsigned long long mcd(unsigned long long a, unsigned long long b) {
	if (LONG_TABLA > a) {
		if (LONG_TABLA > b) {
			return tabla[a][b];
		}
	}

	return (b == 0) ? a : mcd(b, a % b);
}

void main(int argc, char *argv[]) {
	unsigned long long cNum, cNumS, aRes;
	unsigned long long xNumIng;
	unsigned long long longSerie, longSerieMax;

	if (argc == 1) {
		printf("Ingrese el numero: ");
		scanf("%llu", &xNumIng);
	} else {
		xNumIng = atoi(argv[1]);
	}

	int nTiempo = clock();

	for (cNumS = 1; LONG_TABLA > cNumS; ++cNumS) {
		tabla[cNumS][0] = cNumS;
		for (cNum = 1; cNumS > cNum; ++cNum) {
			tabla[cNumS][cNum] = tabla[cNum][cNumS % cNum];
		}
	}

	aRes = xNumIng + 1;
	longSerieMax = (unsigned long long)(xNumIng / 2) + xNumIng % 2;
	for (cNumS = 2; xNumIng > cNumS; ++cNumS) {
		longSerie = (longSerieMax >= cNumS) ? cNumS : longSerieMax--;

		for (cNum = 0; longSerie > cNum; ++cNum) {
			aRes += cNumS * (unsigned long long)((xNumIng - cNum) / cNumS) / mcd(cNumS, cNum);
			aRes %= 999999017;
		}
	}

	nTiempo = clock() - nTiempo;
	printf("\nEl resultado es: %llu\n", aRes);
	printf("Tiempo de ejecucion: %.3f\n", (double)nTiempo/CLOCKS_PER_SEC);
}
