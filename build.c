#include "build.h"

void swap(char **data_1, char **data_2)
{
    char **temp = data_1;
    data_1 = data_2;
    data_2 = temp;
}

LinkedList *NewNode(char *string)
{
    LinkedList *new = (LinkedList *)malloc(sizeof(LinkedList));
    strcpy(new->string, string);
    new->next = NULL;
    return new;
}

BST *NewRoot(char *string)
{
    BST *new = (BST *)malloc(sizeof(BST));
    strcpy(new->string, string);
    new->left = NULL;
    new->right = NULL;
    return new;
}

LinkedList *build_linkedlist(char **Data, int build_num)
{
    LinkedList *head = NULL;
    LinkedList *current = NULL;
    
    head = NewNode(Data[0]);
    current = head;
    for (int i = 1; i < build_num; i++)
    {
        current->next = NewNode(Data[i]);
        current = current->next;
    }
    return head;
}

BST *build_BST(char **Data, int build_num)
{
    BST *head = NULL;

    head = NewRoot(Data[0]);
    BST *start = NULL;
    for (int i = 1; i < build_num; i++)
    {
        start = head;
        while (start)
        {
            if (strcmp(Data[i], start->string) > 0)     start = start->right;
            else if (strcmp(Data[i], start->string) < 0)     start = start->left;
            else    break;
            
            if (start == NULL)     start = NewRoot(Data[i]);
        }
    }
    return head;
}

int hash65(char *key)
{
    int hv = 0;
    int MaxLen = strlen(key) - 1;
    int i;
    char *ptr = key;
    while (*ptr)
    {
        i = 1;
        int Len = MaxLen;
        while (Len > 0)
        {
            i = i * 65;
            Len--;
        }
        hv += i * *ptr;
        ptr++;
        MaxLen--;
    }
    return hv;
}

Hash *NewTable(char *string)
{
    Hash *new = (Hash *)malloc(sizeof(Hash));
    strcpy(new->string, string);
    new->next = NULL;
    new->cnt = 1;
    return new;
}

void build_hash(Hash **HashTable, char **Data, int build_num)
{
    Hash *start = NULL;
    for (int i = 0; i < build_num; i++)
    {
        int hv = hash65(Data[i]) % (build_num - 1);
        start = HashTable[hv];
        if (start->cnt == 0)
        {
            strcpy(start->string, Data[i]);
            start->cnt = 1;
            continue;
        }
        while (start)
        {
            start = start->next;
        }
        start = NewTable(Data[i]);
    }
}