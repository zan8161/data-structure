#define StringLen 6

typedef struct LinkedList{
    char string[StringLen];
    struct LinkedList *next;
} LinkedList;

typedef struct BST{
    char string[StringLen];
    struct BST *left;
    struct BST *right;
} BST;

typedef struct Hash{
    char string[StringLen];
    int cnt;
    struct Hash *next;
} Hash;