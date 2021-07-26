#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define getName(var) #var

/*
    the game has a pyramid of 1s and 0s (they start as 0s), a player selects a row and a range
    to change its values, they can't skip any cells while doing so.
    the player who changes the last 0 to a 1 wins.
    the pyramid has four rows whos length is 1 + row_number * 2.
*/

void printRows();
void changeRows();
bool verifyChange();

/*
    oprow is short for operation row, it's the row being changed.
    oprange is an array for storing the range that's being changed.
    row is a two dimentional array for storing the playing area itself,
    the first value is the rows and the second is the collumns.
*/

static int oprow, oprange[2], row[4][7];

int main(){

    // loop for the game to run constantly
    while (true)
    {
        // input collection
        printf("Select the row you want to change: ");
        scanf("%d", &oprow);
        if (oprow == -1){ // debug option to end the game
            break;
        }
        printf("Select the starting position of the range you want to change: ");
        scanf("%d", &oprange[0]);
        printf("Select the ending position of the range you want to change: ");
        scanf("%d", &oprange[1]);

        // verifies the change the user wants to make and if it's valid it changes the arrays accordingly
        if (verifyChange()){
            changeRows();
            printRows(); // prints the play area each time for the user to see
        }
    }

    // outputs the final board, probably won't be in the final version (ironically)
    printf("\nFinal output:\n");
    printRows();

    return 0;
}

// verifies the user request to change the playing area is valid
// a valid request is only on empty (value_of_cell == 0) cells and has a valid range
// a valid range's first value is smaller than it's second one
// if the range is invalid it returns false, if it is valid it returns true
bool verifyChange(){
    // checks if the range is valid and if not prints out a corresponding error message
    if (oprange[0] > oprange[1]){
        printf("Error: Invalid range\n");
        return false;
    }

    // checks if all cells in the desired range are empty
    for (int i = oprange[0]; i < oprange[1] - oprange[0] + 1; i++){
        if (row[oprow - 1][i] == 1){
            printf("Error: Not all cells in range are empty\n");
            return false;
        }
    }

    return true;
}

// changes the playing area (row) according to a valid range (oprange]) and row (oprow)
void changeRows(){

    // checks which row the user wants to change
    // needs to be a switch for range verification-
    // -to make sure it won't try to change cells that don't exist or shouldn't be changed
    switch (oprow){
        case 1:
            row[0][0] = 1;
            break;
        
        case 2:
            if (oprange[0] > 0 && oprange[0] < 4 && oprange[1] > 0 && oprange[1] < 4){
                for (int i = oprange[0] - 1; i < oprange[1]; i++){
                    row[1][i] = 1;
                }
            }
            break;
        
        case 3:
            if (oprange[0] > 0 && oprange[0] < 6 && oprange[1] > 0 && oprange[1] < 6){
                for (int i = oprange[0] - 1; i < oprange[1]; i++){
                    row[2][i] = 1;
                }
            }
            break;
        
        case 4:
            if (oprange[0] > 0 && oprange[0] < 8 && oprange[1] > 0 && oprange[1] < 8){
                for (int i = oprange[0] - 1; i < oprange[1]; i++){
                    row[3][i] = 1;
                }
            }
            break;
        
        // checks if the user inputs a row number that doesn't exist
        default:
            printf("Error: Invalid row number");
            break;
    }
}

// prints the playing area in a readable format
void printRows(){
    printf("\n");

    // is the loop for rows
    for (int z = 0; z < 4; z++){
        // prints out spaces for formatting
        for (int x = 0; x < 6 - z * 2; x++){
            printf(" ");
        }

        // prints the actual values as well as spaces for formatting
        for (int i = 0; i < z * 2 + 1; i++){
            printf("%d ", row[z][i]);
        }

        printf("\n");
    }

    printf("\n");
}