#include<stdio.h>
#include<stdlib.h>



double fitness = 0; //Nota de aptidao do individuo
double fitnessPercentual = 0; //Porcentagem quão aptto para evoluir
double faixaRoleta = 0; //Faixa da pizza em que seja selecionavel


int* individuo(int TamanhoCromossomo)
{
	int *Cromossomo = (int*) malloc (sizeof(int)); //Vetor de bits 0 ou 1

	for(int i = 0; i < TamanhoCromossomo; i++)
	{
		int z = rand() % 100;
		if(z > 50)
		{
			z = 1;
		}
		else
		{
			z = 0;
		}
		Cromossomo[i] = z;
		printf("%i", Cromossomo[i]);
	}
	puts("");

	
	return Cromossomo;
}

int setGene(int posicao, int gene, int *Cromossomo)
{
	Cromossomo[posicao] = gene;
}

int getGene(int posicao)
{
	
}
