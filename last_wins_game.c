#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define getName(var) #var

void printRows();
void changeRows();
bool verifyChange();

static int oprow, oprange[2], row[4][7];

int main(){

    while (true)
    {
        printf("Select the row you want to change: ");
        scanf("%d", &oprow);
        if (oprow == -1){
            break;
        }
        printf("Select the starting position of the range you want to change: ");
        scanf("%d", &oprange[0]);
        printf("Select the ending position of the range you want to change: ");
        scanf("%d", &oprange[1]);

        if (verifyChange()){
            changeRows();
            printRows();
        }
    }

    printf("\nFinal output:\n");
    printRows();

    return 0;
}
bool verifyChange(){
    if (oprange[0] > oprange[1]){
        printf("Error: Invalid range\n");
        return false;
    }

    for (int i = oprange[0]; i < oprange[1] - oprange[0] + 1; i++){
        if (row[oprow - 1][i] == 1){
            printf("Error: Not all cells in range are empty\n");
            return false;
        }
    }

    return true;
}

void changeRows(){
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
        
        default:
            printf("Please enter a valid input");
            break;
    }
}

void printRows(){
    printf("\n");

    for (int z = 0; z < 4; z++){
        for (int x = 0; x < 6 - z * 2; x++){
            printf(" ");
        }

        for (int i = 0; i < z * 2 + 1; i++){
            printf("%d ", row[z][i]);
        }

        printf("\n");
    }

    printf("\n");
}