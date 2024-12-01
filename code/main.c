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

void SetData(List** node, int value)
{
    (*node)->data = value;
}

void PrintData(List* node)
{
    printf("Node value is: %d\n", node->data);
}

void PrintLink(List* node)
{
    printf("Link value is: %x\n", node->next);
}

int main()
{
    List* node;
    AllocNode(&node);

    SetData(&node, 3);
    PrintData(node);
    PrintLink(node);

    FreeNode(&node);
    return 0;
}
