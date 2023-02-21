#include "lista.h"

struct listanode
{
	Item info;
	struct listanode *ant;
	struct listanode *prox;
	double area;
};

struct lista
{
	struct listanode *l;
	int capacidade;
};

Lista createLista(int capacidade)
{
	struct lista *L = malloc(sizeof(struct lista));
	struct listanode *l = malloc(sizeof(struct listanode));
	L->l = l;
	l->prox = NIL;
	l->info = NIL;
	l->ant = NIL;
	if (capacidade < 0)
	{
		L->capacidade = CAPAC_ILIMITADA;
	}
	else
	{
		L->capacidade = capacidade;
	}
	return L;
}

int length(Lista L)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	int i = 0;
	if (pointernode != NIL)
	{
		if (pointernode->info != NIL)
		{
			i++;
		}
		while (pointernode->prox != NIL)
		{
			pointernode = pointernode->prox;
			i++;
		}
	}
	return i;
}

int maxLength(Lista L)
{
	struct lista *pointer = L;
	return pointer->capacidade;
}

bool isEmpty(Lista L)
{
	if (length(L) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull(Lista L)
{
	struct lista *pointer = L;
	if (pointer->capacidade != CAPAC_ILIMITADA && length(pointer) >= maxLength(pointer))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Posic insert(Lista L, Item info, double area)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	if (isFull(L))
	{
		return NIL;
	}
	else
	{
		while (pointernode->prox != NIL)
		{
			pointernode = pointernode->prox;
		}
		if (!isEmpty(L))
		{
			struct listanode *elemento = malloc(sizeof(struct listanode));
			pointernode->prox = elemento;
			elemento->prox = NIL;
			elemento->info = info;
			elemento->ant = pointernode;
			elemento->area = area;
			return elemento;
		}
		else
		{
			pointernode->info = info;
			return pointernode;
		}
	}
}

Item pop(Lista L, removerItem removedor)
{
	Item valor;
	struct listanode *elemento = getFirst(L);
	if (elemento == NIL)
	{
		return NIL;
	}
	else
	{
		valor = elemento->info;
		remover(L, elemento, removedor);
		return valor;
	}
}

void remover(Lista L, Posic p, removerItem removedor)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	if (!isEmpty(L))
	{
		if (p == getFirst(L))
		{
			pointer->l = pointernode->prox;
			if (pointernode->prox != NIL)
			{
				pointernode->prox->ant = NIL;
			}
			if (pointernode->info != NIL)
			{
				if (removedor != NIL)
				{
					removedor(pointernode->info);
				}
				else
				{
					pointernode->info = NIL;
				}
			}
			pointernode->prox = NIL;
			free(pointernode);
		}
		else
		{
			while (pointernode->prox != p)
			{
				pointernode = pointernode->prox;
			}
			if (pointernode->prox->info != NIL)
			{
				if (removedor != NIL)
				{
					removedor(pointernode->prox->info);
				}
				else
				{
					pointernode->prox->info = NIL;
				}
			}
			pointernode->prox = pointernode->prox->prox;
			if (pointernode->prox != NIL)
			{
				pointernode->prox->ant = pointernode;
			}
			free(p);
		}
	}
}

Item get(Lista L, Posic p)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	if (!isEmpty(L))
	{
		pointernode = p;
		return pointernode->info;
	}
	else
	{
		return NIL;
	}
}

Posic insertBefore(Lista L, Posic p, Item info)
{
	struct lista *pointer = L;
	struct listanode *pointernode = p;
	if (isFull(L))
	{
		return NIL;
	}
	else
	{
		if (p == getFirst(L))
		{
			struct listanode *elemento = malloc(sizeof(struct listanode));
			elemento->prox = p;
			elemento->info = info;
			elemento->ant = NIL;
			pointer->l = elemento;
			return elemento;
		}
		else
		{
			struct listanode *elemento = malloc(sizeof(struct listanode));
			elemento->prox = p;
			elemento->info = info;
			elemento->ant = pointernode->ant;
			pointernode->ant->prox = elemento;
			pointernode->ant = elemento;
			return elemento;
		}
	}
}

Posic insertAfter(Lista L, Posic p, Item info)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	if (isFull(L))
	{
		return NIL;
	}
	else
	{
		pointernode = p;
		struct listanode *elemento = malloc(sizeof(struct listanode));
		elemento->prox = pointernode->prox;
		pointernode->prox = elemento;
		elemento->info = info;
		elemento->ant = pointernode;
		return elemento;
	}
}

Posic getFirst(Lista L)
{
	struct lista *pointer = L;
	return pointer->l;
}

Posic getNext(Lista L, Posic p)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	if (!isEmpty(L))
	{
		pointernode = p;
		return pointernode->prox;
	}
	else
	{
		return NIL;
	}
}

Posic getLast(Lista L)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	if (!isEmpty(L))
	{
		while (pointernode->prox != NIL)
		{
			pointernode = pointernode->prox;
		}
		return pointernode;
	}
	else
	{
		return NIL;
	}
}

Posic getPrevious(Lista L, Posic p)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	if (!isEmpty(L))
	{
		pointernode = p;
		return pointernode->ant;
	}
	else
	{
		return NIL;
	}
}

void killLista(Lista L, removerItem removedor)
{
	while (!isEmpty(L))
	{
		remover(L, getFirst(L), removedor);
	}
	free(L);
}

void removerInt(void *x)
{
	free(x);
}

// Função auxiliar para imprimir uma lista de inteiros
void imprimirLista(Lista L)
{
	printf("Lista: ");
	Posic p = getFirst(L);
	while (p != NIL)
	{
		int *info = (int *)get(L, p);
		printf("%d ", *info);
		p = getNext(L, p);
	}
	printf("\n");
}

int main()
{
	Lista L = createLista(5);
	printf("Lista criada com capacidade %d\n", maxLength(L));

	printf("A lista esta vazia? %d\n", isEmpty(L));
	printf("A lista esta cheia? %d\n", isFull(L));

	Item i1 = malloc(sizeof(int));
	*((int *)i1) = 1;
	Item i2 = malloc(sizeof(int));
	*((int *)i2) = 2;
	Item i3 = malloc(sizeof(int));
	*((int *)i3) = 3;
	Item i4 = malloc(sizeof(int));
	*((int *)i4) = 4;
	Item i5 = malloc(sizeof(int));
	*((int *)i5) = 5;
	// Teste de inserção
	insert(L, i1, 1.5);
	insert(L, i2, 2.0);
	insert(L, i3, 3.5);
	insert(L, i4, 2.5);
	insert(L, i5, 1.0);
	imprimirLista(L);

	// Teste de pop
	Item i = pop(L, removerInt);
	printf("Item removido: %d\n", *((int *)i));
	imprimirLista(L);

	// Teste de remover
	Posic p = getLast(L);
	remover(L, p, removerInt);
	imprimirLista(L);

	// Teste de insertBefore e insertAfter
	p = getLast(L);
	insertBefore(L, p, (Item)(&(int){6}));
	p = getFirst(L);
	insertAfter(L, p, (Item)(&(int){0}));
	imprimirLista(L);

	// Teste de getFirst, getNext, getLast e getPrevious
	printf("Primeiro item: %d\n", *((int *)get(L, getFirst(L))));
	printf("Ultimo item: %d\n", *((int *)get(L, getLast(L))));
	p = getFirst(L);
	while (p != NIL)
	{
		printf("Item atual: %d\n", *((int *)get(L, p)));
		p = getNext(L, p);
	}
	p = getLast(L);
	while (p != NIL)
	{
		printf("Item atual: %d\n", *((int *)get(L, p)));
		p = getPrevious(L, p);
	}

	// Teste de killLista
	killLista(L, removerInt);
	printf("Lista destruida\n");

	printf("hahahaha");
	return 0;
}