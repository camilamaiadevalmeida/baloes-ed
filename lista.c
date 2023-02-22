#include "lista.h"
#include <assert.h>

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

Item pop(Lista L)
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
		remover(L, elemento, NULL);
		return valor;
	}
}

void remover(Lista L, Posic p, void (*removerItem)(Item))
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
				if (removerItem != NIL)
				{
					removerItem(pointernode->info);
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
				if (removerItem != NIL)
				{
					removerItem(pointernode->prox->info);
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

void killLista(Lista L, void (*removerItem)(Item))
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	struct listanode *aux;
	if (!isEmpty(L))
	{
		while (pointernode->prox != NIL)
		{
			printf("teste");
			aux = pointernode;
			pointernode = pointernode->prox;
			if (aux->info != NIL)
			{
				if (removerItem != NIL)
				{
					removerItem(aux->info);
				}
				else
				{
					aux->info = NIL;
				}
			}
			aux->prox = NIL;
			free(aux);
		}
		if (pointernode->info != NIL)
		{
			if (removerItem != NIL)
			{
				removerItem(pointernode->info);
			}
			else
			{
				pointernode->info = NIL;
			}
		}
		pointernode->prox = NIL;
		free(pointernode);
	}
	free(L);
}

struct negocio
{
	int id;
	char* nome;
};

void testCreateLista(){
    Lista L = createLista(10);
    assert(L != NULL);
}

void testLength(){
    Lista L = createLista(10);
    assert(length(L) == 0);
    insert(L, 10, 20.5);
    assert(length(L) == 1);
}

void testMaxLength(){
    Lista L = createLista(10);
    assert(maxLength(L) == 10);
}

void testIsEmpty(){
    Lista L = createLista(10);
    assert(isEmpty(L) == true);
    insert(L, 10, 20.5);
    assert(isEmpty(L) == false);
}

void testIsFull(){
    Lista L = createLista(1);
    assert(isFull(L) == false);
    insert(L, 10, 20.5);
    assert(isFull(L) == true);
}

void testInsert(){
    Lista L = createLista(10);
    Posic p = insert(L, 10, 20.5);
    assert(p != NIL);
    assert(get(L, p) == 10);
}

void testPop(){
    Lista L = createLista(10);
    insert(L, 10, 20.5);
    assert(pop(L) == 10);
    assert(length(L) == 0);
}

void testRemover(){
    Lista L = createLista(10);
    Posic p = insert(L, 10, 20.5);
    assert(length(L) == 1);
    remover(L, p, NULL);
    assert(length(L) == 0);
}

void testGet(){
    Lista L = createLista(10);
    Posic p = insert(L, 10, 20.5);
    assert(get(L, p) == 10);
}

void testInsertBefore(){
    Lista L = createLista(10);
    Posic p = insert(L, 10, 20.5);
    Posic q = insertBefore(L, p, 20);
    assert(length(L) == 2);
    assert(get(L, q) == 20);
}

int main(){
    testCreateLista();
    testLength();
    testMaxLength();
    testIsEmpty();
    testIsFull();
    testInsert();
    testPop();
    testRemover();
    testGet();
    testInsertBefore();
    printf("All tests passed!\n");
    return 0;
}