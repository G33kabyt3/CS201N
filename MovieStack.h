//
//  MovieStack.h
//  CS 201
//
//  Created by Trapper Ross on 3/28/19.
//  Copyright © 2019 Trapper Ross. All rights reserved.
//

#ifndef MovieStack_h
#define MovieStack_h

#include <stdio.h>
typedef struct Stack *Stack;
typedef struct stackNode *stackNode;
struct stackNode {
    stackNode nxt;
    void *data;
};

struct Stack{
    stackNode first;
};

Stack Stack_New (void);
void* Pop(Stack T);
void Push(Stack T, void * s);
void* Peek(Stack T);


#endif /* MovieStack_h */
