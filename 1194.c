#include <stdio.h>
#include <stdlib.h>


typedef struct Arv{

	char info;
	struct Arv *dir;
	struct Arv *esq;

} Arv;

Arv* novoNo(char info);

void showposfixa(Arv *arvore);

int src(char *str, int inicio, int fim, char info);

Arv* tree(char *ord, char *pre, int inInicio, int inFim);

short indice;

int main()
{
	short qtsCasos;
	short qtsNodes, i;
	char pre[1000], ord[1000];

	scanf("%hu", &qtsCasos);

	while (qtsCasos--)
	{

		scanf("%hu %s %s%*c", &qtsNodes, pre, ord);
		indice = 0;
		Arv *raiz = tree(ord, pre, 0, qtsNodes - 1);
		showposfixa(raiz);
		printf("\n");

	}

    return 0;
}


Arv* novoNo(char info){
	Arv *no = (Arv *) malloc(sizeof(Arv));
	no->info = info;
	no->esq = no->dir = NULL;

	return no;
}

int src(char *str, int inicio, int fim, char info){
	short i;
	for (i = inicio; i <= fim; ++i)
		if (str[i] == info)
			return i;

	return -1;

}

Arv* tree(char *ord, char *pre, int inInicio, int inFim){
	int infixaIndice;

	if (inInicio > inFim)
		return NULL;

	Arv *no = novoNo(pre[indice++]);
	if (inInicio == inFim)
		return no;

	infixaIndice = src(ord, inInicio, inFim, no->info);
	no->esq = tree(ord, pre, inInicio, infixaIndice - 1);
	no->dir = tree(ord, pre, infixaIndice + 1, inFim);

	return no;

}

void showposfixa(Arv *no){
	if (no == NULL)
		return;

	showposfixa(no->esq);
	showposfixa(no->dir);
	printf("%c", no->info);

}
