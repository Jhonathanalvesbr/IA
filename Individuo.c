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
		//printf("%i", Cromossomo[i]);
	}
	//puts("");

	
	return Cromossomo;
}

//Inserir valor em determinado local do vetor do cromossomo
int setGene(int posicao, int gene, int *Cromossomo)
{
	Cromossomo[posicao] = gene;
}

//Pegar gene do vetor
int getGene(int posicao,int *Cromossomo)
{
	int cromossomo = Cromossomo[posicao];
	
	return cromossomo;
}

int fitnes(double fitnes)
{
	fitness = fitnes;
}

double getFitness()
{
	return fitness;
}

void setFitnessPercent(double fitnessPercent)
{
	int fitnessPercen = fitnessPercent;
}

double getFitnessPercent()
{
	
}

int multarBit(int *Cromossomo, int TamanhoCromossomo)
{
	int r = rand() % TamanhoCromossomo;
	
	if(Cromossomo[r] == 0)
	{
		Cromossomo[r] = 1;
	}
	else
	{
		Cromossomo[r] = 0;
	}
	return *Cromossomo;
}

void setRandRoleta(double inicio, double fim)
{
	double faixaRoleta[1];
	faixaRoleta[0] = inicio;
	faixaRoleta[1] = fim;
}

/*double *getRangRoleta
{
	
}*/


int getInt( const int * bin )
{
    int n = 0;
    int i = 0;
    int nbits = 5;

    for( i = 0; i < nbits; i++ )
        n += ( bin[ nbits - i - 1 ] == 1 ) ? (1 << i) : 0;
    return n;
}



