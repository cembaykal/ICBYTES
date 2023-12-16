#include <stdio.h>
#include <conio.h>
#include "icbytes.h"

int main()
{
	ICBYTES matB,matA = { { 1,2 },{3,4} };
	CreateMatrix(matB, 2, 2, ICB_FLOAT);
	DisplayMatrix(matA);
	double det = determinant(matA);
	printf("Determinant(matA): %0.3f\n\n", det);
	matB = 0.5;
	DisplayMatrix(matB);
	matB += matA;
	printf("\n");
	DisplayMatrix(matB);
	_getch();
	exit(0);
}