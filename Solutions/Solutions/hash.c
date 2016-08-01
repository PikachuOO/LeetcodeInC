#include "hash.h"
#include <malloc.h>
#include <string.h>
void hash_init(hash_table *pHashTable, size_t size)
{
	pHashTable->size = size;
	pHashTable->table = (hash_entry *)calloc(size, sizeof(hash_entry));
	pHashTable->hash_v_pool = (unsigned int *)calloc(size, sizeof(unsigned int));
	pHashTable->hash_v_cnt = 0;
}

unsigned int hash_v(hash_table *pHashTable, char *str)
{
	unsigned int hash_val = 0;
	int i = 0;

	while (hash_val < (unsigned int)(ULONG_MAX) && i < (unsigned int)strlen(str))
	{
		hash_val += str[i++];
		hash_val <<= 8;
	}
	return hash_val % pHashTable->size;
}
unsigned int hash_nv(hash_table *pHashTable, int n)
{
	return n % pHashTable->size;
}
void hash_nset(hash_table *pHashTable, int n, int key)
{
	unsigned int hash_val = hash_nv(pHashTable, n);
	hash_entry *p = &pHashTable->table[hash_val];

	if (p->n == 0 && p->key == 0)
	{
		pHashTable->hash_v_pool[pHashTable->hash_v_cnt++] = hash_val;
	}
	p->n = n;
	p->key = key;
}
int hash_n_contain(hash_table *pHashTable, int n)
{
	unsigned int hash_val = hash_nv(pHashTable, n);
	hash_entry *p = &pHashTable->table[hash_val];

	if (p->n == 0 && p->key == 0)
		return 0;
	else
		return 1;
}
int hash_n_get(hash_table *pHashTable, int n)
{
	unsigned int hash_val = hash_nv(pHashTable, n);
	hash_entry *p = &pHashTable->table[hash_val];

	return p->key;
}
int hash_n_traverse(hash_table *pHashTable, int i, int *n, int *key)
{
	hash_entry *p;

	if (i < pHashTable->hash_v_cnt)
	{
		p = &pHashTable->table[pHashTable->hash_v_pool[i]];
		*n = p->n;
		*key = p->key;
		return i;
	}
	else
	{
		return -1;
	}
}
void hash_set(hash_table *pHashTable, char *str, int key)
{
	unsigned int hash_val = hash_v(pHashTable, str);
	hash_entry *p = &pHashTable->table[hash_val];

	if (p->next == NULL && p->str == NULL)
	{
		p->str = _strdup(str);
		p->key = key;
	}
	else
	{
		hash_entry *n = calloc(1, sizeof(hash_entry));
		n->str = _strdup(str);
		n->key = key;

		while (p->next)
		{
			if (p->key == key)
			{
				free(p->str);
				p->str = _strdup(str);
				break;
			}
			p = p->next;
		}
		if (p)
		{
			p->next = n;
		}
	}
}

int hash_get(hash_table *pHashTable, char *str, int key)
{
	unsigned int hash_val = hash_v(pHashTable, str);
	hash_entry *p = &pHashTable->table[hash_val];
	if (p->str)
	{
		while (p)
		{
			if (p->key == key)
				return p->key;
			p = p->next;
		}
		return -1;
	}
	else
		return -1;
}



int *hash_getrange(hash_table *pHashTable, char *str, int *size)
{
	int i = 0;
	int *range = 0;
	unsigned int hash_val = hash_v(pHashTable, str);
	hash_entry *p = &pHashTable->table[hash_val];
	hash_entry *pp = p;
	if (pp->str)
	{
		while (pp)
		{
			i++;
			pp = pp->next;
		}
	}
	*size = i;


	if (*size)
	{
		range = calloc(i, sizeof(int));
		pp = p;
		i = 0;
		while (pp)
		{
			range[i++] = pp->key;
			pp = pp->next;
		}
	}
	return range;
}

void hash_freerange(hash_table *pHashTable, void *p)
{
	free(p);
}

