//
//  MovieTree.h
//  CS 201
//
//  Created by Trapper Ross on 3/17/19.
//  Copyright © 2019 Trapper Ross. All rights reserved.
//

#ifndef MovieTree_h
#define MovieTree_h

#include <stdio.h>




typedef struct Tree *Tree;

typedef struct Node *Node;
struct Node {
    Node parent;
    Node left;
    Node right;
    void *data;
    int balance;
};
struct Tree {
    Node root;
    int (*comp) (void *, void *);
    void (*print) (void *);
};

Tree  Tree_New        (int (*comp)(void *, void *), void (*print)(void *));

int  Tree_Insert     (Tree t, void *data);
void  Tree_DeleteNode (Tree t, Node  node);
Node  Tree_SearchNode (Tree t, void *data);

Node  Tree_FirstNode  (Tree t);
Node  Tree_LastNode   (Tree t);

Node  Tree_PrevNode   (Tree t, Node n);
Node  Tree_NextNode   (Tree t, Node n);

void  Tree_Print      (Tree t);

void *Node_GetData (Node n);
#endif /* MovieTree_h */
