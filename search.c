#include "search.h"

void L_search(LinkedList *head, char **Search, int search_num)
{
    for (int i = 0; i < search_num; i++)
    {
        LinkedList *start = head;
        while (start)
        {
            if (strcmp(Search[i], start->string) == 0)      break;
            else    start = start->next;
        }
    }
}

void binary_search(char **Data, char **Search, int build_num, int search_num)
{
    for (int i = 0; i < search_num; i++)
    {
        int low = 0; 
        int upper = build_num - 1;

        while (low <= upper)
        {
            int mid = (low + upper) / 2;

            if (strcmp(Data[mid], Search[i]) < 0)   low = mid + 1;
            else if(strcmp(Data[mid], Search[i]) > 0)   upper = mid - 1; 
            else    break;
        }
    }
}

void array_search(char **Data, char **Search, int build_num, int search_num)
{
    for (int i = 0; i < search_num; i++)
    {
        for (int j = 0; j < build_num; j++)
        {
            if (strcmp(Search[i], Data[j]) == 0)    break;
        }
    }
}

void BST_search(BST *head, char **Search, int search_num)
{
    BST *start = NULL;
    for (int i = 0; i < search_num; i++)
    {
        start = head;
        while (start)
        {
            if (strcmp(Search[i], start->string) > 0)
                start = start->right;
            else if (strcmp(Search[i], start->string) < 0)
                start = start->left;
            else
                break;
        }    
    }
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

void hash_search(Hash **HashTable, char **Search,int build_num, int search_num)
{
    Hash *start = NULL;
    for (int i = 0; i < search_num; i++)
    {
        int hv = hash65(Search[i]) % (build_num - 1);
        start = HashTable[hv];
        while (start)
        {
            if (strcmp(Search[i], start->string) == 0)
                break;
            start = start->next;
        }
    }
}