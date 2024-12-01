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
    (*node)->data = -1;
    (*node)->next = 0;
}

void FreeNode(List** node)
{
    if (*node)
    {
        (*node)->data = -1;
        (*node)->next = 0;
        free(*node);
        *node = 0;
    }
}

void SetData(List** node, int value)
{
    List* p = *node;
    if (!p) return;
    p->data = value;
}

void PrintData(List* node)
{
    if (!node) return;
    printf("Node value is: %d\n", node->data);
}

void PrintLink(List* node)
{
    if (!node) return;
    printf("Link value is: %x\n", node->next);
}

void PushValue(List** head, int value)
{
    List* p = *head;
    if (!p) return;
    if (p->next == 0 && p->data == -1)
    {
        p->data = value;
        return;
    }

    while (p->next)
    {
        p = p->next;
    }

    List* newNode;
    AllocNode(&newNode);
    newNode->data = value;
    p->next = newNode;
}

int PopValue(List** node)
{
    List* p = *node;
    if (!p) return -1;

    List* q;
    int res;
    if (p->next == 0)
    {
        res = p->data;
        p->data = -1;
        return res;
    }

    while (p->next)
    {
        q = p;
        p = p->next;
    }

    res = p->data;
    FreeNode(&p);
    q->next = 0;
}

void PrintList(List* head)
{
    List* p = head;
    if (!p)
    {
        return;
    }
    if (p->data == -1)
    {
        return;
    }

    while (p)
    {
        PrintData(p);
        p = p->next;
    }
}

void FreeList(List** node)
{
    List* p = *node;
    List* q;
    if (!p) return;

    while (p)
    {
        q = p;
        p = p->next;
        FreeNode(&q);
        *node = p;
    }
}

int main()
{
    List* head;
    int v;
    AllocNode(&head);

    //SetData(&head, 3);
    PushValue(&head, 3);
    PushValue(&head, 8);
    PushValue(&head, 9);
    PushValue(&head, 10);
    v = PopValue(&head);
    v = PopValue(&head);
    v = PopValue(&head);
    v = PopValue(&head);
    v = PopValue(&head);

    //RemoveValue(&head, 8);
    PushValue(&head, 7);
    PushValue(&head, 8);

    PrintList(head);

    FreeList(&head);
    FreeList(&head);
    FreeList(&head);
    PrintList(head);

    return 0;
}
