#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0


typedef struct Arv{

	char info;
	struct Arv*esquerda;
	struct Arv*direita;

} Arv;

void infixa(Arv *);

void prefixa(Arv *);

void posfixa(Arv *);

void printInfixa(char *);

void printPrefixa(char *);

void printPosfixa(char *);

Arv* push(Arv *, char );

_Bool busca(Arv*, char );

char letrasInfixa[100] = { 0 };
char letrasPosfixa[100] = { 0 };
char letrasPrefixa[100] = { 0 };

int i = 0;
int j = 0;
int k = 0;

void teste(Arv *no)
{
	if (no)
	{
		teste(no->esquerda);
		printf("%c ", no->info);
		teste(no->direita);
	}

}


int main()
{
	char comando[20], info;
	Arv *no = NULL;
	while (scanf("%s%*c", comando) != EOF)
	{
		if (strcmp(comando, "I") == 0)
		{
			scanf("%c", &info);
			no = push(no, info);
		}
		else if (strcmp(comando, "INFIXA") == 0)
			infixa(no), printInfixa(letrasInfixa);
		else if (strcmp(comando, "PREFIXA") == 0)
			prefixa(no), printPrefixa(letrasPrefixa);
		else if (strcmp(comando, "P") == 0)
		{
			scanf("%c", &info);
			if (busca(no, info))
				printf("%c existe\n", info);
			else
				printf("%c nao existe\n", info);
		}
		else
			posfixa(no), printPosfixa(letrasPosfixa);
	}

    return 0;
}


Arv* push(Arv *no, char info)
{
	if (!no)
	{
		no = (Arv *) malloc(sizeof(Arv));
		no->info = info;
		no->direita = no->esquerda = NULL;
	}
	else if (no->info > info)
		no->esquerda = push(no->esquerda, info);
	else
		no->direita = push(no->direita, info);

	return no;
}

_Bool busca(Arv *no, char info)
{
	_Bool direita, esquerda;
	if (!no)
		return false;
	if (no->info == info)
		return true;
	if (no->info > info)
		esquerda = busca(no->esquerda, info);
	else
		direita = busca(no->direita, info);

}

void printInfixa(char *infos)
{
	int z;
	for (z = 0; z < i; ++z)
		if (!z)
			printf("%c", letrasInfixa[z]);
		else
			printf(" %c", letrasInfixa[z]);
	i = 0;
	printf("\n");

}

void printPrefixa(char *infos)
{
	int z;
	for (z = 0; z < k; ++z)
		if (!z)
			printf("%c", letrasPrefixa[z]);
		else
			printf(" %c", letrasPrefixa[z]);
	k = 0;
	printf("\n");

}

void printPosfixa(char *infos)
{
	int z;
	for (z = 0; z < j; ++z)
		if (!z)
			printf("%c", letrasPosfixa[z]);
		else
			printf(" %c", letrasPosfixa[z]);
	j = 0;
	printf("\n");

}

void infixa(Arv *no)
{
	if (no)
	{
		infixa(no->esquerda);
		letrasInfixa[i++] = no->info;
		infixa(no->direita);
	}
}

void posfixa(Arv *no)
{
	if (no)
	{
		posfixa(no->esquerda);
		posfixa(no->direita);
		letrasPosfixa[j++] = no->info;
	}
}

void prefixa(Arv *no)
{
	if (no)
	{
		letrasPrefixa[k++] = no->info;
		prefixa(no->esquerda);
		prefixa(no->direita);
	}
}
