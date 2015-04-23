/* Hecho con recursividad */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool divideA(unsigned long long num1, unsigned long long num2) {
	return (num1 % num2 == 0);
}

bool esPrimo(unsigned long long numero) {
	unsigned long long i;

	for (i = 2; (unsigned long long)(sqrt(numero)) >= i; ++i) {
		if (divideA(numero, i)) {
			return false;
		}
	}

	return true;
}

unsigned long long maximo(unsigned long long num1, unsigned long long num2) {
	if (num1 > num2) {
		return num1;
	} else {
		return num2;
	}	
}

unsigned long long funcion(unsigned long long numero, unsigned long long factor) {
	unsigned long long segFactor;

	++factor;
	if ((unsigned long long)(sqrt(numero)) >= factor) {
		if (divideA(numero, factor)) {
			segFactor = (unsigned long long)(numero / factor);
			if (esPrimo(segFactor)) {
				return segFactor;
			} else if (esPrimo(factor)) {
				return maximo(factor, funcion(numero, factor));
			}
		}

		return funcion(numero, factor);
	} else {
		return 0;
	}
}


void main() {
	unsigned long long numero;

	printf("Numero: ");
	scanf("%llu", &numero);

	printf("Mayor factor primo: %llu\n", funcion(numero, 0));
}
