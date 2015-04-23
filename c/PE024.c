#include <stdio.h>
#include <time.h>

long factorial(long pnNum) {
	long cNum;
	long aRes = 1;
	
	for (cNum = 2; cNum <= pnNum; ++cNum) {
		aRes *= cNum;
	}

	return aRes;
}

void main() {
	int nTiempo;
	int vNum[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	long cElem,cPas;
	long aRes;
	long nPas,nFac,nAux,nPrm;
	long xNumIng = 1000000;

	printf( "Ingrese el numero: " );
	scanf( "%d", &xNumIng);

	nTiempo = clock();
	--xNumIng;
	aRes = xNumIng % factorial(10);
	
	for (cElem = 9; 0 <= cElem; --cElem) {
		nFac = factorial(cElem);
		nPas = (long)(aRes / nFac);
		aRes %= nFac;
		for (cPas = nPas; 1 <= cPas; --cPas) {
			nPrm = 9 - cElem + cPas;
			nAux = vNum[nPrm - 1];
			vNum[nPrm - 1] = vNum[nPrm];
			vNum[nPrm] = nAux;
		}
	}

	nTiempo = clock() - nTiempo;
	printf("\nEl resultado es ");
	for (cElem = 0; cElem < 10; ++cElem) {
		printf("%d", vNum[cElem]);
	}
	
	printf("\nTiempo de ejecucion: %.3f\n", (double)(nTiempo/CLOCKS_PER_SEC));
}
