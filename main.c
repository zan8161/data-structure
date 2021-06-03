#include "basic.h"
#include "build.h"
#include "search.h"
#define MaxDataNum 1000000
#define True 1
#define False 0

void err()
{
    printf("Error!\n");
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        err();
        exit(1);
    }

    int build_num = atoi(argv[1] + 1);
    int search_num = atoi(argv[2] + 1);
    int bstMode = False;
    int bsMode = False;
    int arrMode = False;
    int llMode = False;
    int hashMode = False;

    if(build_num > MaxDataNum)
    {
        err();
        exit(1);
    }

    if (strcmp(argv[3], "-bst") == 0)
        bstMode = True;
    else if (strcmp(argv[3], "-bs") == 0)
        bsMode = True;
    else if (strcmp(argv[3], "-arr") == 0)
        arrMode = True;
    else if (strcmp(argv[3], "-ll") == 0)
        llMode = True;
    else if (strcmp(argv[3], "-hash") == 0)
        hashMode = True;
    else {
        err();
        exit(1);
    }


    struct timeval start;
    struct timeval end;
    
    gettimeofday(&start, NULL);
    //random letter basic
    char charater[52];
    for (int i = 0; i < 26; i++)
    {
        charater[i] = 65 + i;
        charater[i + 26] = 97 + i;
    }
    //malloc
    char *Data[build_num];
    for (int i = 0; i < build_num; i++)
        Data[i] = malloc(StringLen * sizeof(char));
    //basic data of build&search
    srand(69);
    for (int i = 0; i < build_num; i++)
    {
        for (int j = 0; j < StringLen - 1; j++)
            Data[i][j] = charater[rand() % 51];
        Data[i][StringLen - 1] = '\0';
    }
    //build structure declare
    BST *B_head = NULL;

    char *Strings[build_num];
    
    LinkedList *L_head = NULL;
    
    Hash *New[build_num];
    for (int i = 0; i < build_num;i++)
    {
        New[i] = (Hash *)malloc(sizeof(Hash));
        New[i]->next = NULL;
        New[i]->cnt = 0;
    }

    //build start
    if (bstMode == True)
        B_head = build_BST(Data, build_num);

    else if (bsMode == True)
    {
        for (int i = 0; i < build_num; i++)
        {
            Strings[i] = Data[i];
        }
        quickSortforStrings(Strings, 0, build_num - 1);
    }

    else if (arrMode == True)
    {
        for (int i = 0; i < build_num; i++)
        {
            Strings[i] = Data[i];
        }
    }

    else if (llMode == True)
        L_head = build_linkedlist(Data, build_num);

    else if (hashMode == True)
    {
        build_hash(New, Data, build_num);
    }

    //build complete
    gettimeofday(&end, NULL);
    double diff = 0;
    diff = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
    printf("Time of the Build : %f\n", diff / 1000000.0);
    //time of build finished

    gettimeofday(&start, NULL);
    //search data
    char *Search[search_num];
    for (int i = 0; i < search_num; i++)
    {
        Search[i] = Data[rand() % build_num - 1];
    }
    //search start
    if (bstMode == True)
        BST_search(B_head, Search, search_num);
    
    if (bsMode == True)
        binary_search(Strings, Search, build_num, search_num);
    
    if (arrMode == True)
        array_search(Strings, Search, build_num, search_num);
    
    if (llMode == True)
        L_search(L_head, Search, search_num);
    
    if (hashMode == True)
        hash_search(New, Search, build_num, search_num);
    //search complete
    gettimeofday(&end, NULL);
    diff = 0;
    diff = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
    printf("Time of the Search : %f\n", diff / 1000000.0);
    //time of search finished

    //free
    for (int i = 0; i < build_num; i++)
        if (Data[i])
            free(Data[i]);

    if (bstMode == True)
    {
        BST *record[build_num];
        for (int i = 0; i < build_num; i++)
            record[i] = NULL;

        int start = 0, tail = 0;
        record[tail++] = B_head;
        while(start != tail)
        {
            if(record[start]->left)    record[tail++] = record[start]->left;
            if(record[start]->right)    record[tail++] = record[start]->right;
            start++;
        }
        for (int i = 0; i < build_num; i++)
            if (record[i])
                free(record[i]);
    }

    if (llMode == True)
    {
        LinkedList *L_FREE = NULL;
        for (int i = 0; i < build_num; i++)
        {
            L_FREE = L_head;
            L_head = L_head->next;
            if(L_FREE)
                free(L_FREE);
        }
    }

    if (hashMode == True)
    {
        Hash *H_FREE = NULL;
        Hash *previous = NULL;
        for (int i = 0; i < build_num; i++)
        {
            if (New[i])
            {
                H_FREE = New[i];
                while (H_FREE)
                {
                    previous = H_FREE;
                    H_FREE = H_FREE->next;
                    free(previous);
                }
            }
        }
    }
    //ALL finished
}