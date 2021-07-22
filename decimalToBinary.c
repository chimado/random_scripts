#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const int maxBits = 256;

void main(){
    bool numStart = false;
    int dec;
    int bin[maxBits];
    bin[0] = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &dec);
    printf("The output binary number is: ");

    if (dec % 2 != 0){
        bin[0] = 1;
        dec = dec - 1;
    }

    for (int i = maxBits; i > 0; i = i - 1){
        if (dec - pow(2, i) >= 0){
            numStart = true;
            bin[i] = 1;
            dec = dec - pow(2, i);
            printf("%d", bin[i]);
        }

        else if (numStart)
        {
            bin[i] = 0;
            printf("%d", bin[i]);
        }
        
    }

    printf("%d\n", bin[0]);
    numStart = false;

    main();
}