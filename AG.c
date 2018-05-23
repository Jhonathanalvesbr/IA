#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include "Individuo.cpp"
#include<time.h>

double function1(double x) //Funcao de Aptdao
{
	
	x = 100 + (fabs (x * sin ( sqrt( fabs(x) ) ) ) );
	
	return x;
}

/*void calcularFit(int TamanhoCromossomo, int * Cromossomo)
{
	for(int i = 0; i < TamanhoCromossomo; i++)
		{
			function1()
		}
}*/

struct individuo{
	int individuo[5];
	double fitness;
	int decimal;
};

int main()
{
	srand(time(NULL));
	int TamanhoCromossomo = 5; // Tamanho Individuo
	int TamanhoPopulacao = 500; // Tamanho População
	int X = pow(2,TamanhoCromossomo); // Funcao de 0 ate 2 exponencial cormossomo
	int Random; //Gera numeros
	
	int vet[500][5];
	
	
	for(int x = 0; x < 10; x++)
	{
		int *p = individuo(TamanhoCromossomo);
		printf("Binario: ");
		for(int i = 0; i < TamanhoCromossomo; i++)
		{
			vet[x][i] = *(p+i);
			printf("%i", vet[x][i]);
		}
		printf(" | Decimal: %i\n", getInt(vet[x]));
		free(p);
		
		int r = rand()%5;
		if(r == 1)
		{
			printf("\tMultacao\n");
			printf("Binario: ");
			for(int i = 0; i < TamanhoCromossomo; i++)
			{
				printf("%i", vet[x][i]);
			}
			printf(" | Decimal: %i\n", getInt(vet[x]));
			printf("Binario: ");
			multarBit(vet[x],TamanhoCromossomo);
			for(int i = 0; i < TamanhoCromossomo; i++)
			{
				printf("%i", vet[x][i]);
			}
			printf(" | Decimal: %i\n", getInt(vet[x]));
			printf("\tMultacao\n");
		}
		
	}
	
	
	return 0;
}
