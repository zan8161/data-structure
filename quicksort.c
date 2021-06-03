#include "quicksort.h"
#include <string.h>

int partitionforStrings(char **strings, int left, int right)
{
    int i = left - 1; 
    int j;
    for (j = left; j < right; j++)
    {
        if (strcmp(strings[j],strings[right]) <= 0)
        {
            i++;
            char *n;
            n = strings[i];
            strings[i] = strings[j];
            strings[j] = n;
        }
    }
    char *n;
    n = strings[i + 1];
    strings[i + 1] = strings[right];
    strings[right] = n;
    return i + 1;
}

void quickSortforStrings(char **strings, int left, int right)
{
    if (left < right)
    {
        int q = partitionforStrings(strings, left, right);
        quickSortforStrings(strings, left, q-1); 
        quickSortforStrings(strings, q+1, right);
    }
}