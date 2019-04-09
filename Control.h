//
//  Control.h
//  CS 201
//
//  Created by Trapper Ross on 2/27/19.
//  Copyright © 2019 Trapper Ross. All rights reserved.
//

#ifndef Control_h
#define Control_h

#include <stdio.h>
#include "MovieStack.h"

int createUserC(char[]);
int deleteUserC(char username [50]);
void printUsersC(void);
int logInC(char[]);
void logOutC(void);
void displayCatalogC(void);
int addToCatalogC(Stack S, int mediaType, char date [9], unsigned long int choice);
int deleteFromCatalogC(Stack S, unsigned long int choice);
int editCatalogC(Stack S, int mediaType, char date [9], unsigned long int choice);
int printStackM(Stack S);
int printStackC(Stack S);
Stack searchMoviesC(char name [201]);
Stack searchCatalogC(char name [201]);




#endif /* Control_h */
