//
//  Control.c
//  CS 201
//
//  Created by Trapper Ross on 2/27/19.
//  Copyright © 2019 Trapper Ross. All rights reserved.
//
// Kinda just merged the database and control classes together
#include "Control.h"
#include "Database.h"
#include <stdio.h>
#include <stdlib.h>


int createUserC(char username [51])
{
    return createUser(username);
}

//Wrapper Function for Database PrintUser().
void printUsersC()
{
    printUsers();
}
//Wrapper for Database deleteUser().
int deleteUserC(char username [51])
{
    return deleteUser(username);
    
}

//Wrapper function for Database chooseUser().
int logInC(char username [])
{
    return chooseUser(username);
}

//Wrapper for Database logOutUser().
void logOutC()
{
    logOutUser();
}

int addToCatalogC(Stack S, int mediaType, char date [9], unsigned long int choice)
{
    for(int i = 0; i< choice-1; i++)
    {
        Pop(S);
    }
    
    Node N = Pop(S);
    free(S);
    return addMovieToCatalog(N, mediaType, date);
}

int deleteFromCatalogC(Stack S, unsigned long int choice)
{
    for(int i = 0; i< choice-1; i++)
    {
        Pop(S);
    }
    Node N = Pop(S);
    free(S);
    return deleteC(N);
}

Stack searchMoviesC(char name [201])
{
    return searchMovies(name);
}


Stack searchCatalogC(char name [201])
{
    return searchCatalog(name);
}

int editCatalogC(Stack S, int mediaType, char date [9], unsigned long int choice)
{
    for(int i = 0; i< choice-1; i++)
    {
        Pop(S);
    }
    
    Node N = Pop(S);
    free(S);
    return editEntryInCatalog(N, mediaType, date);
}

//Prints the stack and returns how many elements are in the stack.
int printStackM(Stack S)
{
    Stack temp = Stack_New();
    Node n = Pop (S);
    int i = 0;
    while (n != NULL)
    {
        i++;
        printf("#%i: ", i);
        Push(temp, n);
        printM(n->data);
        n = Pop(S);
    }
    n = Pop(temp);
    //Restore the stack
    while (n!= NULL)
    {
        Push(S, n);
        n= Pop(temp);
    }
    free(temp);
    return i;
}

// Prints the stack and returns a copy for Catalog Nodes.
int printStackC(Stack S)
{
    Stack temp = Stack_New();
    Node n = Pop (S);
    int i = 0;
    while (n != NULL)
    {
        i++;
        printf("#%i: ", i);
        Push(temp, n);
        printC(n->data);
        n = Pop(S);
    }
    n = Pop(temp);
    //Restore the stack
    while (n!= NULL)
    {
        Push(S, n);
        n= Pop(temp);
    }
    free(temp);
    return i;
}
void displayCatalogC()
{
    printCTree();
}
