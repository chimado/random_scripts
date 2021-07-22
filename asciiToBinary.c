#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define maxBits 256
#define maxLetters 256

void decimalToBinary();
void resetAscii();
static char ascii[maxLetters];

void main(){
    resetAscii();
    printf("Enter a word: ");
    fgets(ascii, maxLetters, stdin);
    printf("The output binary is: ");
    
    for (int i = 0; i < maxLetters; i++){
        if (ascii[i] != '@' && ascii[i] != 0 && ascii[i] != 10){
            decimalToBinary(ascii[i]);
        }
    }

    printf("\n");
    resetAscii();
    main();
}

void resetAscii(){
    for (int i = 0; i < maxLetters; i++){
        ascii[i] = '@';
    }
}

void decimalToBinary(int dec){
    bool numStart = false;
    int last = 0;

    if (dec % 2 != 0){
        last = 1;
        dec = dec - 1;
    }

    for (int i = maxBits; i > 0; i = i - 1){
        if (dec - pow(2, i) >= 0){
            numStart = true;
            dec = dec - pow(2, i);
            printf("1");
        }

        else if (numStart)
        {
            printf("0");
        }
        
    }

    printf("%d ", last); 
}