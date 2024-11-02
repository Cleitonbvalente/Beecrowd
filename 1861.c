#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct tipoDado{

	char nome[20];
	unsigned qtsMortes;

} Assassinos;

struct ArvHall{

	Assassinos dado;
	struct ArvHall *esq;
	struct ArvHall *dir;

};

struct ArvMortos{

	char morto[20];
	struct ArvMortos *esq;
	struct ArvMortos *dir;

};

typedef struct ArvHall Hall;

typedef struct ArvMortos Mortos;

Hall* insereAssassinos(Hall *, Assassinos);
Mortos* insereMortos(Mortos *, char *);

bool busca(Mortos *mortos, char *chave);

void show(Hall *, Mortos *);

int main()
{
	char matou[20], morreu[20];
	Hall *hall = NULL;
	Mortos *mortos = NULL;
	while (scanf(" %s %s", matou, morreu) != EOF)
	{
		Assassinos assassino = { 0 };
		strcpy(assassino.nome, matou);
		hall = insereAssassinos(hall, assassino);
		mortos = insereMortos(mortos, morreu);
	}
	printf("HALL OF MURDERERS\n");
	show(hall, mortos);

    return 0;
}


Hall* insereAssassinos(Hall *hall, Assassinos assassino)
{
	if (!hall)
	{
		hall = (Hall *) malloc(sizeof(Hall));
		hall->dado = assassino;
		hall->dado.qtsMortes++;
		hall->esq = hall->dir = NULL;
	}
	else if (strcmp(hall->dado.nome, assassino.nome) > 0)
		hall->esq = insereAssassinos(hall->esq, assassino);
	else if (strcmp(hall->dado.nome, assassino.nome) < 0)
		hall->dir = insereAssassinos(hall->dir, assassino);
	else
		hall->dado.qtsMortes++;
	return hall;
}

Mortos* insereMortos(Mortos *mortos, char *morto)
{
	if (!mortos)
	{
		mortos = (Mortos *) malloc(sizeof(Mortos));
		strcpy(mortos->morto, morto);
		mortos->esq = mortos->dir = NULL;
	}
	else if (strcmp(mortos->morto, morto) > 0)
		mortos->esq = insereMortos(mortos->esq, morto);
	else
		mortos->dir = insereMortos(mortos->dir, morto);
	return mortos;
}

void show(Hall *hall, Mortos *mortos)
{
	if (hall != NULL)
	{
		show(hall->esq, mortos);
		if (!busca(mortos, hall->dado.nome))
			printf("%s %u\n", hall->dado.nome, hall->dado.qtsMortes);
		show(hall->dir, mortos);
	}
}

bool busca(Mortos *mortos, char *chave)
{
	bool direita, esquerda;
	if (!mortos)
		return false;
	if (strcmp(mortos->morto, chave) == 0)
		return true;
	if (strcmp(mortos->morto, chave) > 0)
		esquerda = busca(mortos->esq, chave);
	else
		direita = busca(mortos->dir, chave);
}
