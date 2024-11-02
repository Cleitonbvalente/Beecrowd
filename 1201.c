#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

typedef struct Arv{

	unsigned data;
	struct Arv *left;
	struct Arv *right;

} Arv;

_Bool flag;
void infixa(Arv *);
void prefixa(Arv *);
void posfixa(Arv *);
Arv * pop(Arv *, int);
_Bool busca(Arv *, int);
Arv * push(Arv *, int);
Arv * findMax(Arv *root);
Arv * findMin(Arv *root);

int main()
{
	int num;
	char comando[10];
	Arv *root = NULL;

	while (scanf("%s%*c", comando) != EOF)
	{

		if (strcmp(comando, "I") == 0)
			scanf("%d%*c", &num), root = push(root, num);
		else if (strcmp(comando, "P") == 0)
		{

			scanf("%d%*c", &num);

			if (busca(root, num))
				printf("%d existe\n", num);
			else
				printf("%d nao existe\n", num);

		}
		else if (strcmp(comando, "R") == 0)
			scanf("%d%*c", &num), root = pop(root, num);
		else
		{
			
			flag = true;
			if (strcmp(comando, "INFIXA") == 0)
				infixa(root), printf("\n");
			else if (strcmp(comando, "PREFIXA") == 0)
				prefixa(root), printf("\n");
			else if (strcmp(comando, "POSFIXA") == 0)
				posfixa(root), printf("\n");

		}
		
	}

    return 0;
}



Arv* push(Arv *root, int data)
{

	if (!root)
	{

		root = (Arv *) malloc(sizeof(Arv));
		root->data = data;
		root->right = root->left = NULL;

	}
	else if (root->data < data)
		root->right = push(root->right, data);
	else
		root->left = push(root->left, data);
	
	return root;

}

_Bool busca(Arv *root, int chave)
{

	_Bool right, left;

	if (!root)
		return false;

	if (root->data == chave)
		return true;

	if (root->data < chave)
		right = busca(root->right, chave);
	else
		left = busca(root->left, chave);

}

void infixa(Arv *root)
{

	if (root)
	{

		infixa(root->left);
		if (!flag)
			printf(" %d", root->data);
		else
			printf("%d", root->data), flag = false;

		infixa(root->right);

	}

}

void prefixa(Arv *root)
{


	if (root)
	{

		if (!flag)
			printf(" %d", root->data);
		else
			printf("%d", root->data), flag = false;

		prefixa(root->left);
		prefixa(root->right);

	}
}

void posfixa(Arv *root)
{

	if (root)
	{

		posfixa(root->left);
		posfixa(root->right);

		if (!flag)
			printf(" %d", root->data);
		else
			printf("%d", root->data), flag = false;
	}

}

Arv * findMin(Arv *root)
{

	if (!root)
		return NULL;
	else if (!root->left)
		return root;
	else
		return findMin(root->left);

}

Arv * findMax(Arv *root)
{

	if(!root)
		return NULL;
	else if (!root->right)
		return root;
	else
		return findMax(root->right);

}

Arv * pop(Arv *root, int x)
{

	Arv *tmp;
	if (!root)
		return NULL;
	else if (root->data > x)
		root->left = pop(root->left, x);
	else if (root->data < x)
		root->right = pop(root->right, x);
	else if (root->left && root->right)
	{

		tmp = findMax(root->left);
		root->data = tmp->data;
		root->left = pop(root->left, root->data);

	}
	else
	{

		tmp = root;
		if (!root->left)
			root = root->right;
		else if (!root->right)
			root = root->left;

		free(tmp);

	}

	return root;

}
