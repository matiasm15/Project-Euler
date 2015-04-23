/*
	Find S(100 000 000, 100 000).

	Compilar como gcc PE485.c -o PE485 -O2 -march=native && PE485 1000000 10000

	Nota: cada tanto da error al compilar y ejecutar. No se porque.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void main(int argc, char *argv[]) {
	unsigned int xNumIngU, xNumIngK;
	unsigned int nRaiz, mDiv; 
	unsigned int cNumJ, cNumN;
	unsigned int *tabla;
	unsigned long long aRes;

	if (argc == 1) {
		printf("Ingrese u: ");
		scanf("%d", &xNumIngU);
		printf("Ingrese k: ");
		scanf("%d", &xNumIngK);
	} else {
		xNumIngU = atoi(argv[1]);
		xNumIngK = atoi(argv[2]);
	}

	int nTiempo = clock();

	tabla = (unsigned int *) malloc(xNumIngU * sizeof(unsigned int));
 	if (tabla == NULL) {
		printf("\nError en la asignacion de memoria.\n");
		exit(1);
	}

	// Registro la cantidad de divisores de cada numero.
	for (cNumN = 1; xNumIngU >= cNumN; ++cNumN) {
		tabla[cNumN] = 0;
		nRaiz = (unsigned int) sqrt(cNumN);
		for (cNumJ = 1; nRaiz >= cNumJ; ++cNumJ) {
			if (cNumN % cNumJ == 0) {
				tabla[cNumN] += 2;
			}
		}
		if (nRaiz * nRaiz == cNumN) {
			--tabla[cNumN];
		}
	}
	printf("\nTabla de divisores creada.\n");

	// Fuerzo que se calcule el mayor la primera vez que entra al ciclo.
	mDiv = xNumIngU;
	tabla[0] = xNumIngU;

	aRes = 0;
	xNumIngU = xNumIngU - xNumIngK + 1;
	for (cNumN = 1; xNumIngU >= cNumN; ++cNumN) {
		if (tabla[xNumIngK] >= mDiv) {
			mDiv = tabla[xNumIngK];
		} else if (tabla[cNumN - 1] == mDiv) {
			mDiv = 0;
			for (cNumJ = cNumN; xNumIngK >= cNumJ; ++cNumJ) {
				if (tabla[cNumJ] > mDiv) {
					mDiv = tabla[cNumJ];
				}
			}
		}

		++xNumIngK;
		aRes += mDiv;
	}

	nTiempo = clock() - nTiempo;
	printf("\nEl resultado es: %lld\n", aRes);
	printf("Tiempo de ejecucion: %.3f\n", (double)nTiempo/CLOCKS_PER_SEC);
}
