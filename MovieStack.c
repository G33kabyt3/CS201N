//
//  MovieStack.c
//  CS 201
//
//  Created by Trapper Ross on 3/28/19.
//  Copyright © 2019 Trapper Ross. All rights reserved.
//


//A lot of this is based on the AVL tree code I took then modified.
#include "MovieStack.h"
#include<stdio.h>
#include<stdlib.h>

Stack Stack_New () {
    Stack t;
    
    t = malloc (sizeof (*t));
    t->first = NULL;
    return t;
}

void* Pop(Stack T)
{
    stackNode n = T->first;
    if( n != NULL)
    {
        T->first = T->first->nxt;
        void *data =n->data;
        free(n);
        return data;
    }
    return NULL;
}

void Push(Stack T, void * s)
{
    stackNode n;
    n = malloc (sizeof (*n));
    n->nxt = T->first;
    T->first = n;
    n->data = s;
    
}
void * Peek(Stack T)
{
    return T->first;
}
