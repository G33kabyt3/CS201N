//
//  main.c
//  CS 201
//
//  Created by Trapper Ross on 2/27/19.
//  Copyright © 2019 Trapper Ross. All rights reserved.
//

#include <stdio.h>
#include "Interface201.h"
#include "Database.h"
#include <string.h>

int main(int argc, const char * argv[]){
    if ( bootDatabase() == 1)
    {
        bootInterface();
        closeDatabase();
    }
    return 0;
}
