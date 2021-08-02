#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define len 9

int play();
int winner();
void printBoard();

int main(){
    int win, board[len];

    win = play(board, 1);
    
    return 0;
}

int play(int board[len], int player){
    int cell;

    printf("Player %d's turn\n", player);

    printf("Enter cell to change: ");
    scanf("%d", &cell);

    if (cell < 0 || cell > len - 1 || board[cell] != 0){
        printf("Invalid input\n");
        return play(board, player);
    }

    else{
        printf("Enter cell value: ");
        scanf("%d", &board[cell]);
        return play(board, 2 / player);
    }
    
    int win = winner(board, 0);

    if (win != 0){
        printf("Player %d won\n", win);
        printBoard(board);
        return win;
    }
}

int winner(int board[len], int place){
    if (board[place] != 0){
        if (place < 3){
            
        }
    }
}

void printBoard(int board[len]){
    printf("\n");

    for (int i = 0; i < len; i++){
        switch (board[i])
        {
        case 1:
            printf("X");
            break;

        case 2:
            printf("O");
            break;
        
        default:
            printf(" ");
            break;
        }
            
        if ((i + 1) % 3 == 0 && i < len - 1){
            printf("\n");
            
            for (int z = 0; z < len / 2; z++){
                if (z % 2 == 0){
                    printf("-");
                }

                else{
                    printf("|");
                }
            }
            
            printf("\n");
        }

        else if (i < len - 1){
            printf("|");
        }
    }
    printf("\n\n");
}