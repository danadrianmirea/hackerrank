#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List List;

struct List
{
    int data;
    List* next;
};

void AllocNode(List** node)
{
    *node = (List*)malloc(sizeof(List));
}

void FreeNode(List** node)
{
    free(*node);
}


int main()
{
    List* node;
    AllocNode(&node);

    FreeNode(&node);
    return 0;
}
