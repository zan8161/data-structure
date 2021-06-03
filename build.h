#include "basic.h"
#include "structure.h"
#include "quicksort.h"

void swap(char **data_1, char **data_2);
LinkedList *NewNode(char *string);
BST *NewRoot(char *string);
LinkedList *build_linkedlist(char **Data, int build_num);
BST *build_BST(char **Data, int build_num);
int hash65(char *key);
Hash *NewTable(char *string);
void build_hash(Hash **HashTable, char **Data, int build_num);