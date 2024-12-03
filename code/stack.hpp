#pragma once

#include <main.h>
#include <util.h>
#include <iostream>

using namespace std;

class Stack
{
public:
    int data;
    Stack* next;
    Stack* top;

    void Push(int data)
    {
        Stack* newStack = new Stack();
        newStack->data = data;
        newStack->next = NULL;
        if (top == NULL)
        {
            top = newStack;
            return;
        }
        newStack->next = top;
        top = newStack;
    }

    int Pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int data = top->data;

        Stack* temp = top;
        top = top->next;
        delete temp;

        return data;
    }
};

void TestStack()
{
    Stack* stack = new Stack();
    stack->Push(1);
    stack->Push(2);
    stack->Push(3);
    stack->Push(4);
    int n = stack->Pop();
    cout << n << endl;
}
