//
//  Interface201.c
//  CS 201
//
//  Created by Trapper Ross on 2/27/19.
//  Copyright © 2019 Trapper Ross. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interface201.h"
#include "Control.h"

/*
 *
 * User Functions
 * A username can be 50 characters long. Any extra characters will not be considered.
 *
 */

//TO_DO figure out how to make search function work, how to prevent blank input for file.

// I firmly believe the fact that I had to spend an hour implimenting this means 1 of 2 things.
// 1.) I got hit with the stupid stick when I was a child.
// 2.) C is just the worst.
// Long story short, fgets input, then checks to see if there was overflow. If there was, clear the input buffer.
// Also, prints a new line to keep things looking nice. 
void getInput(char * str, int size)
{
    fgets(str, size, stdin);
    if(strchr(str, '\n') == NULL)
    {
        while ((getchar())!= '\n');
    }
    printf("\n");
}

void trimNewLine(char *str)
{
    unsigned long len= strlen(str);
    if(str[len-1]=='\n')
        str[len-1]='\0';
}
void createUserI()
{
    char *username = malloc(sizeof(char)*51);
    int success =0;
    while (success!= 1)
    {
        printf("Please type the desired username for the new user.  It may not contain /'s and may not start with .'s. Please note that it may only be 50 characters long. Any overflow characters will not be considered.\n");
        getInput(username, 51);
        trimNewLine(username);
        if(strlen(username)== 0)
        {
            
        } else {
            success = createUserC(username);
            if (success == 0)
            {
                printf("The username was taken. Please try another name.\n");
            } else if (success == 2)
            {
                printf("You used a forbidden character. Please don't.\n");
            }
        }
    }
    printf("Creation Successful. \n");
    free(username);
}

int logInI()
{
    char *username = malloc(sizeof(char)*51);
    printf("Printing user files...\n");
    printUsersI();
    printf("Choose the .log file you wish to load. Please type in the name of the user file you wish to access (Just the name, not the .log).\n");
    getInput(username, 51);
    trimNewLine(username);
    if (logInC(username)==0)
    {
        printf("Incorrect log in information. Please try again later.\n");
        return 0;
    }
    free(username);
    return 1;
}

//Logs out a current user.
void logOutI()
{
    logOutC();
    printf("Logout successful.\n");
}

void deleteUserI()
{
    char *username = malloc(sizeof(char)*51);
    int success =0;
    printf("Printing user files...\n");
    printUsersI();
    printf("Please type the username for the user you wish to delete. Please note that it may only be 50 characters long. Any overflow characters will not be considered.\n");
    getInput(username, 51);
    trimNewLine(username);
    success = deleteUserC(username);
    //For some reason the remove() function for C returns 0 on success.
    if (success == 0)
    {
        printf("Delete successful.\n");
    } else {
        printf("Username not found. Please try again later.\n");
    }
    free(username);
}

//Wrapper for control print users.
void printUsersI(){
    printUsersC();
}


/*
 *
 * Catalog Functions
 *
 */
void addToCatalogI()
{
    char *title = malloc(201*sizeof(char));
    printf("Please type the name of the movie you wish to add. Please note that the title may only be 200 characters long. Any overflow characters will not be considered.\n");
    getInput(title, 201);
    trimNewLine(title);
    if(strlen(title)== 0)
    {
        printf("No input detected.\n" );
    } else {
        printf("Printing out results...\n");
        Stack results = searchMoviesC(title);
        if (Peek(results)==NULL)
        {
            printf("No results found. Please try again with a different query.\n");
            return;
        }
        int numElements = printStackM(results);
        char *digits = malloc(sizeof(char)*8);
        unsigned long int choice = 0;
        while (choice == 0){
            printf("Type the number of the result you wish to add. Any digits beyond the 7th will not be considered.\n");
            
            getInput(digits, 8);
            trimNewLine(digits);
            choice =  strtoul(digits, (char **)NULL, 10);
            if (choice == 0)
            {
                printf("Please type in a greater than zero number\n");
            } else if (choice >numElements)
            {
                choice =0;
                printf("Please choose a listed option.\n");
            }
        }
        int readMedia =0;
        unsigned long int input =0;
        char *mediaString = malloc(sizeof(char)*2);
        while (input == 0){
            printf("Please type in a the format of your addition. Type 1 for digital, 2 for DVD, and 3 for Blu-Ray.\n");
            getInput(mediaString, 2);
            trimNewLine(mediaString);
            input =  strtoul(mediaString, (char **)NULL, 10);
            if (input == 0)
            {
                printf("Please type in a greater than zero number\n");
            } else if (input >3 )
            {
                input =0;
                printf("Please choose a listed option\n");
            } else {
                //We can safely cast now that we know the input is within our cases.
                readMedia = (int) input;
            }
        }
        // If I was coding in a different langugue and had libraries available to me I might actually bother forcing a date format on the user.
        // However, there really doesn't seem to be a way to do this from scratch in C without it being a LOT more effort than it's worth.
        // So I won't.
        char *date = malloc(sizeof(char)*18);
        printf("Please type in the date acquired. Use any format you want, but you're cut off at 17 characters.\n");
        getInput(date, 18);
        trimNewLine(date);
        if (addToCatalogC(results, readMedia, date, choice) == -1){
            printf("Add failed. Identical entry already in catalog.\n");
        } else {
            printf("Add Successful.\n");
        }
        
        free(mediaString);
        free(date);
        free(digits);
    }
    free(title);
}

void deleteFromCatalogI()
{
    char *title = malloc(sizeof(char)*201);
    printf("Please type the name of the movie you wish to delete. Please note that the title may only be 200 characters long. Any overflow characters will not be considered.\n");
    getInput(title,201);
    trimNewLine(title);
    printf("Printing out results...\n");
    // searchCatalog
    Stack results =searchCatalogC(title);
    if (Peek(results)==NULL)
    {
        printf("No results found. Please try again with a different query.\n");
        return;
    }
    int numElements = printStackM(results);
    unsigned long int choice = 0;
    char *digits = malloc(sizeof(char)*8);
    while (choice == 0){
        printf("Type the number of the result you wish to add. Any digits beyond the 7th will not be considered.\n");
        getInput(digits,8 );
        trimNewLine(digits);
        choice =  strtoul(digits, (char **)NULL, 10);
        if (choice == 0)
        {
            printf("Please type in a greater than zero number\n");
        } else if (choice >numElements)
        {
            choice =0;
            printf("Please choose a listed option.\n");
        }
    }
    free(digits);
    
    deleteFromCatalogC(results, choice);
    printf("Delete Successful!\n");
    free(title);
}

void editCatalogI()
{
    char *title = malloc(201*sizeof(char));
    printf("Please type the name of the movie you wish to edit. Please note that the title may only be 200 characters long. Any overflow characters will not be considered.\n");
    getInput(title, 201);
    trimNewLine(title);
    printf("Printing out results...\n");
    Stack results = searchCatalogC(title);
    if (Peek(results)==NULL)
    {
        printf("No results found. Please try again with a different query.\n");
        return;
    }
    int numElements = printStackC(results);
    char *digits = malloc(sizeof(char)*8);
    unsigned long int choice = 0;
    while (choice == 0){
        printf("Type the number of the result you wish to edit. Any digits beyond the 7th will not be considered.\n");
        
        getInput(digits, 8);
        trimNewLine(digits);
        choice =  strtoul(digits, (char **)NULL, 10);
        if (choice == 0)
        {
            printf("Please type in a greater than zero number\n");
        } else if (choice >numElements)
        {
            choice =0;
            printf("Please choose a listed option.\n");
        }
    }
    int readMedia =0;
    unsigned long int input =0;
    char *mediaString = malloc(sizeof(char)*2);
    while (input == 0){
        printf("Please type in a the new format. Type 1 for digital, 2 for DVD, and 3 for Blu-Ray.\n");
        getInput(mediaString, 2);
        trimNewLine(mediaString);
        input =  strtoul(mediaString, (char **)NULL, 10);
        if (input == 0)
        {
            printf("Please type in a greater than zero number\n");
        } else if (input >3 )
        {
            input =0;
            printf("Please choose a listed option\n");
        } else {
            //We can safely cast now that we know the input is within our cases.
            readMedia = (int) input;
        }
    }
    // If I was coding in a different langugue and had libraries available to me I might actually bother forcing a date format on the user.
    // However, there really doesn't seem to be a way to do this from scratch in C without it being a LOT more effort than it's worth.
    // So I won't.
    char *date = malloc(sizeof(char)*18);
    printf("Please type in the new date acquired. Use any format you want, but you're cut off at 17 characters.\n");
    getInput(date, 18);
    trimNewLine(date);
    editCatalogC(results, readMedia, date, choice);
        printf("Edit Successful.\n");
    
    free(mediaString);
    free(date);
    free(digits);
    free(title);
}

//Displays all movies in the catalog. Must have catalog loaded into memory first.
void displayCatalogI()
{
    displayCatalogC();
}

void searchForTitleI()
{
    
}


/*
 *
 * Main Menus
 *
 */

void mainMenu()
{
    char *str = malloc(sizeof(char)*2);
    int terminate =1;
    
    while ( terminate != 0){
        printf("Hello! Type 0 to add a your catalog, 1 to delete from your catalog, 2 to edit the catalog, 3 to display your catalog, 4 to log out.\n ");
        getInput(str, 2);
        trimNewLine(str);
        if (strncmp(str, "0", 1) == 0)
        {
            printf("Add to Catalog Selected.\n");
            addToCatalogI();
            printf("Sending you back to the main menu.\n");
        } else if (strncmp(str, "1",1) ==0 ){
            printf("Delete From Catalog Selected.\n");
            deleteFromCatalogI();
        }else if (strncmp(str, "2",1)==0)
        {
            printf("Edit in Catalog Selected.\n");
            editCatalogI();
        } else if (strncmp(str, "3",1) == 0)
        {
            printf("Display Catalog Selected.\n");
            displayCatalogI();
        } else if (strncmp(str, "4", 1) == 0)
        {
            printf("Log Out Selected\n");
            logOutI();
            terminate = 0;
            free(str);
            break;
            
        } else {
            printf("Please provide valid input.\n");
        }
    }
}

void bootInterface()
{
    char *str = malloc(sizeof(char)*7);
    int exit =1;
    char exitCode[] = "$exit";
    
    while ( exit != 0)
    {
        printf("Hello! Type 0 to Log In, 1 to Create a User, 2 to Delete a User and $exit to exit. \n ");
        getInput(str, 7);
        trimNewLine(str);
        if (strncmp(str, "0", 2) == 0)
        {
            printf("Log In Selected.\n");
            if (logInI() == 1)
            {
                printf("Log in Successful! Sending to Main Menu.\n");
                mainMenu();
            }
            
        } else if (strncmp(str, "1",2) == 0)
        {
            printf("Create User Selected.\n");
            createUserI();
            
        } else if (strncmp(str, "2",2) == 0)
        {
            printf("Delete User Selected.\n");
            deleteUserI();
            
        } else if ( strncmp(str, exitCode,6) == 0)
        {
            exit = 0;
            free(str);
        } else {
            printf("Please provide valid input.\n");
        }
    }
}
