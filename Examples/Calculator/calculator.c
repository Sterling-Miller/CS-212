#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    float valueOne;
    float valueTwo;
    char operator;
    float answer;

    printf("Enter Calculaton:\n\n");
    scanf("%f %c %f", &valueOne, &operator, &valueTwo);

    switch(operator) {
        case '+': answer = valueOne + valueTwo;
            break;
        case '-': answer = valueOne - valueTwo;
            break;
        case '*': answer = valueOne * valueTwo;
            break;
        case '/': answer = valueOne / valueTwo;
            break;
        case '^': answer = pow(valueOne, valueTwo);
            break;
        default: goto fail;
        }
    
    printf("%g %c %g = %g", valueOne, operator, valueTwo, answer);
    goto exit;

    fail:
        printf("Failed.\n");
    exit:
        return 0;
}