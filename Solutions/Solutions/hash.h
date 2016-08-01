#ifndef __HASH_H__
#define __HASH_H__

#include <stddef.h>
#include <limits.h>

typedef struct _hash_entry
{
	struct _hash_entry *next;
	int key;
	char *str;
	int n;

} hash_entry;

typedef struct _hash_table
{
	size_t size;
	hash_entry *table;
	unsigned int *hash_v_pool;
	int hash_v_cnt;

} hash_table;

void hash_init(hash_table *pHashTable, size_t size);
void hash_set(hash_table *pHashTable, char *str, int key);
int hash_get(hash_table *pHashTable, char *str, int key);
int *hash_getrange(hash_table *pHashTable, char *str, int *size);
void hash_freerange(hash_table *pHashTable, void *p);

unsigned int hash_nv(hash_table *pHashTable, int n);
void hash_nset(hash_table *pHashTable, int n, int key);
int hash_n_traverse(hash_table *pHashTable, int i, int *n, int *key);
int hash_n_contain(hash_table *pHashTable, int n);
int hash_n_get(hash_table *pHashTable, int n);
#endif