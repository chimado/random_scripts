#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

long binToDec();

int main(){
    long bin;
    int dec;

    printf("Enter a binary number: ");
    scanf("%ld", &bin);

    dec = binToDec(bin, 0);

    if (bin % 10 == 0){
        dec--;
    }
    printf("%d\n", dec);
    
    return 0;
}

long binToDec(long bin, int count){
    if (bin > 0){
        return pow(2 * (bin % 10), count) + binToDec(bin / 10, count + 1);
    }

    return 0;
}