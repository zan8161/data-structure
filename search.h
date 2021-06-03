#include "basic.h"

#include "structure.h"

void L_search(LinkedList *head, char **Search, int search_num);
void binary_search(char **Data, char **Search, int build_num, int search_num);
void array_search(char **Data, char **Search, int build_num, int search_num);
void BST_search(BST *head, char **Search, int search_num);
int hash65(char *key);
void hash_search(Hash **HashTable, char **Search, int build_num, int search_num);