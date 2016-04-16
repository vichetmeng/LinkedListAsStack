//
//  Stack.h
//  Linked List as Stack
//
//  Created by Vichet Meng on 4/14/16.
//  Copyright © 2016 ViMApps. All rights reserved.
//

#ifndef Stack_H
#define Stack_H

#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    Node():data(0), next(NULL){};
    Node(T data, Node* next):data(data), next(next){};
    
    Node *getNext() { return next; }
    T getData() { return data; }
    
    ~Node(){};
private:
    Node<T> *next;
    T data;
};

template <typename T>
class Stack
{
public:
    Stack();
    Stack(const Stack& otherStack);
    
    void push(T data);
    T peek() const;
    void pop();
    void popPointer();
    int size() const;
    bool isEmpty() const;
    
    Stack& operator=(const Stack& otherStack);
    
    void emptyStack();
    ~Stack();
    
private:
    Node<T> *top;
    int count;
};

#endif /* Stack_H */
