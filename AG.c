#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include "Individuo.cpp"


double function1(double x) //Funcao de Aptdao
{
	
	x = 100 + (fabs (x * sin ( sqrt( fabs(x) ) ) ) );
	
	return x;
}


int main()
{
	int TamanhoCromossomo = 5; // Tamanho Individuo
	int TamanhoPopulacao = 500; // Tamanho População
	int X = pow(2,TamanhoCromossomo); // Funcao de 0 ate 2 exponencial cormossomo
	int Random; //Gera numeros
	
	int vet[500][5];
	
	
	for(int x = 0; x < TamanhoPopulacao; x++)
	{
		int *p = individuo(TamanhoCromossomo);
		
		for(int i = 0; i < TamanhoCromossomo; i++)
		{
			vet[x][i] = *(p+i);
			printf("%i", vet[x][i]);
		}
		free(p);
		puts("");
	}
	
	
	return 0;
}
