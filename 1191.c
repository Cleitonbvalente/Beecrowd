#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Arv{

	char info;
	struct Arv *direita;
	struct Arv *esquerda;

} Arv;


Arv* novoNo(char info);

void showposfixa(Arv *arvore);

int src(char *str, int inicio, int fim, char info);

Arv* tree(char *infixa, char *prefixa, int inInicio, int inFim);

short indice;


int main()
{
	short qtsCasos;
	char prefixa[1000], infixa[1000];
	while (scanf("%s %s", prefixa, infixa) != EOF)
	{
		int tam = strlen(prefixa);
		indice = 0;
		Arv *raiz = tree(infixa, prefixa, 0, tam - 1);
		showposfixa(raiz);
		printf("\n");
	}

    return 0;
}


Arv* novoNo(char info)
{
	Arv *no = (Arv *) malloc(sizeof(Arv));
	no->info = info;
	no->esquerda = no->direita = NULL;
	return no;
}

int src(char *str, int inicio, int fim, char info)
{
	short i;
	for (i = inicio; i <= fim; ++i)
		if (str[i] == info)
			return i;
	return -1;
}

Arv* tree(char *infixa, char *prefixa, int inInicio, int inFim)
{
	int infixaIndice;
	if (inInicio > inFim)
		return NULL;
	Arv *no = novoNo(prefixa[indice++]);
	if (inInicio == inFim)
		return no;
	infixaIndice = src(infixa, inInicio, inFim, no->info);
	no->esquerda = tree(infixa, prefixa, inInicio, infixaIndice - 1);
	no->direita = tree(infixa, prefixa, infixaIndice + 1, inFim);
	return no;
}

void showposfixa(Arv *no)
{
	if (no == NULL)
		return;
	showposfixa(no->esquerda);
	showposfixa(no->direita);
	printf("%c", no->info);

}
