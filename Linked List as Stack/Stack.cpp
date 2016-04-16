//
//  Stack.cpp
//  Linked List as Stack
//
//  Created by Vichet Meng on 4/14/16.
//  Copyright © 2016 ViMApps. All rights reserved.
//

#include "Stack.h"

template <typename T>
Stack<T>::Stack()
{
    top = NULL;
    count = 0;
}

template <typename T>
Stack<T>::Stack(const Stack& otherStack)
{
    if (this == &otherStack)
    {
        cerr << "Attempted self assignment" << endl;
        exit(1);
    }
    else
    {
        if(count != 0)
            emptyStack();
        top = new Node<T>(otherStack.top->getData(), NULL);
        Node<T> *current = otherStack.top->getNext();
        while(current != NULL)
        {
            push(current->getData());
            current = current->getNext();
        }
        count = otherStack.count;
    }
}

template <typename T>
int Stack<T>::size() const
{
    return count;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return count == 0;
}

template <typename T>
void Stack<T>::push(T data)
{
    top = new Node<T>(data, top);
    count++;
}

template <typename T>
T Stack<T>::peek() const
{
    return top->getData();
}

template <typename T>
void Stack<T>::pop()
{
    if(isEmpty())
        cerr << "Cannot delete from empty stack." << endl;
    else
    {
        Node<T> *temp = top;
        top = top->getNext();
        delete temp;
        count--;
    }
}

template <typename T>
void Stack<T>::popPointer()
{
    if(isEmpty())
        cerr << "Cannot delete from empty stack." << endl;
    else
    {
        Node<T> *temp = top;
        top = top->getNext();
        delete temp->getData(); // Delete the data in the heap
        delete temp; // Delete the node itself
        count--; // Decrement count
    }
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& otherStack)
{
    if (this == &otherStack)
    {
        cerr << "Attempted self assignment" << endl;
        exit(1);
    }
    else
    {
        if(count != 0)
            emptyStack();
        top = new Node<T>(otherStack.top->getData(), NULL);
        Node<T> *current = otherStack.top->getNext();
        while(current != NULL)
        {
            push(current->getData());
            current = current->getNext();
        }
        count = otherStack.count;
    }
    
    return *this;
}

template <typename T>
void Stack<T>::emptyStack()
{
    Node<T> *temp;
    while(top != NULL)
    {
        temp = top;
        top = top->getNext();
        delete temp;
    }
    count = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    emptyStack();
}