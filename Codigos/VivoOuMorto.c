#include <stdio.h>
#include <stdlib.h>
#define Item int

char resulta = 1;

typedef struct listaa 
{
	Item item;
	struct listaa *next;
	struct listaa *previous;
} listaa;

typedef struct listaa2
{
	listaa *first;
	listaa *last;
    listaa *current;
	int size;
} listaa2;

int listaa3(listaa2 *x)
{
	x->first = NULL;
	x->last = NULL;
    x->current = NULL;
	x->size = 0;
	return 1;
}
void movee(listaa2 *x)
{
    x->current = x->current->next;
}



void primeirin(listaa2 *x)
{
    x->current = x->first;
}

void ultimin(listaa2 *x)
{
    x->current = x->last;
}


void tira(listaa2 *x)
{
    listaa *t = x->current;

    if(x->current->previous == NULL && x->current->next == NULL) 
    {
        x->first = NULL;
        x->last = NULL;
    }
    else if(x->current->previous == NULL) 
    {
        x->first = x->current->next;
        x->first->previous = NULL;
    }
    else if(x->current->next == NULL) 
    {
        x->last = x->current->previous;
        x->last->next = NULL;
    }
    else 
    {
        x->current->next->previous = x->current->previous;
        x->current->previous->next = x->current->next;
    }

    x->size--;

    x->current = x->current->next; 
    
    free(t); 
}
void moveantes(listaa2 *x)
{
    x->current = x->current->previous;
}

Item ltras(listaa2 *x)
{
	return x->first->item;
}

int vaziaLista(listaa2 *x)
{
	return x->first == NULL;
}


Item lfrente(listaa2 *x)
{
	return x->first->item;
}
int ljogafrente(listaa2 *x, Item i)
{
	listaa *new_node = malloc(sizeof(listaa));
	if(new_node == NULL) return 0;
	new_node->previous = NULL; 
	new_node->item = i;

	if(x->size == 0)
	{
		new_node->next = NULL;
		x->first = new_node;
		x->last = new_node;
	}
	else
	{
		x->first->previous = new_node;
		new_node->next = x->first;
		x->first = new_node;
	}

	x->size++;
	return 1;
}

int ltirafrente(listaa2 *x)
{

	listaa *t = x->first;

	x->first == x->first->next;

	x->size--;

	free(t);
	return 1;
}

void lmostra(listaa2 *r)
{
	listaa *current = r->first;	
    printf("[");
	while(current != NULL)
	{
		printf("%d ", current->item);
		current = current->next;
	}
    printf("]");
}


int lpegatras(listaa2 *x, Item i)
{

	listaa *new_node = malloc(sizeof(listaa));
	if(new_node == NULL) return 0;
	new_node->next = NULL;
	new_node->item = i;

	if(x->size == 0)
	{
		x->first = new_node;
		x->last = new_node;
		new_node->previous = NULL;
	}
	else
	{
		x->last->next = new_node;
		new_node->previous = x->last;
		x->last = new_node;
	}

	x->size++;
	return 1;
}

int ltraseira(listaa2 *x)
{
	listaa *t = x->last;

	x->last = x->last->previous;

	x->last->next = NULL;

	// :)
	x->size--;
	free(t);
}



int main()
{
    int p, r;
    int t = 1;
    do
    {
        scanf("%d %d", &p, &r); if(p == 0 && r == 0) break;

        listaa2 f; listaa3(&f);
        for(int i = 0; i < p; ++i)
        {
            int pp; scanf("%d", &pp);
            lpegatras(&f, pp);
        }

        while(r--)
        {
            int n; scanf("%d", &n);
            int c; scanf("%d", &c);
            
            primeirin(&f);
            while(n--)
            {
                int cc; scanf("%d", &cc);
                if(cc != c) tira(&f);
                else movee(&f);
            }
        }
        printf("Teste %d\n%d\n", t++, lfrente(&f));
    } while (resulta);
    
	return 0;
}