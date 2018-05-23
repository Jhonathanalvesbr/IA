#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define T 5 // Tamanho em Binario
#define P 5 // Tamanho da população

struct individuo
{
	int cromossomo[T]; //Em binario Tamanho 5
	int fitness; //Aptdao
	int decimal; //Numero decimal
	int posicaoMultacao; //Posicao da multacao
	int antesDaMultacao[T]; //Antes da multacao em binario
};

typedef struct individuo Individuo;

double FuncaoAptdao (double x) //Funcao de Aptdao
{
	
	x = 100 + (fabs (x * sin ( sqrt( fabs(x) ) ) ) );
	
	return x;
}

int random (int ateOndeGerar)
{
	return (rand() % ateOndeGerar);
}

Individuo multar (Individuo individuo) //Funcao para multar BIT, Multar individuo
{
	int r = random(T);
	
	individuo.posicaoMultacao = r;
		
	for(int x = 0; x < T; x++)
	{
		individuo.antesDaMultacao[x] = individuo.cromossomo[x];
	}
	
	if(individuo.cromossomo[r] == 0)
	{
		individuo.cromossomo[r] = 1;
	}
	else
	{
		individuo.cromossomo[r] = 0;
	}
	
	return individuo;
}

int converterParaDecimal( const int * bin ) //Conversao para decimal
{
    int n = 0;
    int i = 0;
    int nbits = 5;

    for( i = 0; i < nbits; i++ )
        n += ( bin[ nbits - i - 1 ] == 1 ) ? (1 << i) : 0;
    return n;
}


int main ()
{
	srand(time(NULL));
	
	Individuo individuo[T];
	int r = 0;
	
	for(int i = 0; i < P; i++) // Inicia Populacao
	{
		for(int x = 0; x < T; x++) // Criar individuo
		{
			individuo[i].cromossomo[x] = random(2); // Gerar numeros em binario;
		}
		
		r = random(T);
		
		individuo[i].posicaoMultacao = NULL;
		
		if(r == 1) //Multar individuo
		{
			individuo[i] = multar(individuo[i]); 
		}
		
		individuo[i].decimal = converterParaDecimal(individuo[i].cromossomo);
		
	}
	
	for(int i = 0; i < P; i++)
	{
		for(int x = 0; x < T; x++) // Printar individuos
		{
			printf("%i", individuo[i].cromossomo[x]); 
		}
		
		printf(" Decimal: %i ", individuo[i].decimal);
		
		if(individuo[i].posicaoMultacao != NULL) // Verifica se foi multado
		{
			printf("|Multacao| Posicao->%i ", individuo[i].posicaoMultacao);
			for(int x = 0; x < T; x++)
			{
				printf("%i", individuo[i].antesDaMultacao[x]);
			}
			printf("<-Anterior Decimal: %i", converterParaDecimal(individuo[i].antesDaMultacao));
		}
		puts("");
	}
	
	
	return 0;
}
