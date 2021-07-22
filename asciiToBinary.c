#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define maxBits 256 // is the maximum amount of bits the decmial to binary converter can output
#define maxLetters 256 // is the maximum amount of letters the fgets function will accept

// function and integer declerations
void decimalToBinary();
void resetAscii();
static char ascii[maxLetters]; // ascii is a char array to store the user input

void main(){
    resetAscii();
    printf("Enter a word: ");
    fgets(ascii, maxLetters, stdin); // gets user input, use this instead of scanf, it has buffer overflow protection
    printf("The output binary is: ");
    
    for (int i = 0; i < maxLetters; i++){
        if (ascii[i] != '@' && ascii[i] != 0 && ascii[i] != 10){ // checks if the current char is valid
            decimalToBinary(ascii[i]);
        }
    }

    printf("\n");
    resetAscii();
    main();
}

// ressets the ascii char array to a value never used in words (@) for ease of filtering
void resetAscii(){
    for (int i = 0; i < maxLetters; i++){
        ascii[i] = '@';
    }
}

// converts a decimal value to a binary one and prints it
void decimalToBinary(int dec){
    bool numStart = false; // says if the number has started in order to avoid printing a lot of 0's
    int first = 0; // stores the value of the first bit, the one that's the same in binary and decimal

    if (dec % 2 != 0){ // checks the first bit's value and assigns it to the correct variable
        first = 1;
        dec = dec - 1;
    }

    // the printf commands print out the current bit
    for (int i = maxBits; i > 0; i = i - 1){
        if (dec - pow(2, i) >= 0){ // checks if the current power of 2 (2^i) is bigger or equal to the decimal number
            numStart = true; // if it's true, it means the number has started, so numStart's value is changed to true
            dec = dec - pow(2, i); // because it added the value of 2^i to the binary number that value needs to be removed from the decimal one
            printf("1");
        }

        else if (numStart) // if the number has already started a 0 is needed, to avoid printing a lot of 0's before the number appears
        {
            printf("0");
        }
        
    }

    printf("%d ", first);
}