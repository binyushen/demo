// shenbinyu 2018-03-20

#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

struct kv {
    struct kv *next;
    char *key;
    void *value;
    void (*free_value)(void *);
};

typedef struct HashTable {
    struct kv **table;
} HashTable;

#define TABLE_SIZE (1024*1024)

HashTable *hash_table_new();
void hash_table_delete(HashTable *ht);

#define hash_table_put(ht, key, value) hash_table_put2(ht, key, value, NULL);
int hash_table_put2(HashTable *ht, char *key, void *value, void(*free_value)(void*));

void *hash_table_get(HashTable *ht, char *key);

void hash_table_rm(HashTable *ht, char *key);

#endif
