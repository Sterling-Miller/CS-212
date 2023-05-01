#include <stdio.h>
#include <stdlib.h>

int main() {

/*-----Pointers-----*/
    // char x = 'A';
    // char *ptr = &x;

    // printf("Value of x: %c\n", x);
    // printf("Value of x using pointer: %c\n", *ptr);
    // printf("Memory address of x: %p\n", &x);
    // printf("Memory address stored in ptr: %p\n", ptr);
    // printf("Memory address of ptr: %p\n", &ptr);

    // return 0;


/*--Pointers & Arrays--*/
    // char c = 'A';
    // char *ptr = &c;
    // printf("Value of c: %c\n", c);            // 'A' : Value
    // printf("Value of c: %c\n", *ptr);         // 'A' : Dereference pointer
    // printf("Value of c: %c\n", ptr[0]);       // 'A' : Array notation index 0
    // printf("Value after c: %c\n", ptr[1]);    // Unknown : Array notation index 1

    // return 0;


/*--Pointer Arithmetic--*/
    // char *str = "Hello, World";
    // printf("%c\n", str[2]);


/*--Array of Integers--*/
    // int *arr = (int *)malloc(3 * sizeof(int));
    // for (int i = 0; i < 3; i++) {
    //     arr[i] = i;
    // }
    // for (int i = 0; i < 3; i++) {
    //     printf("%d", arr[i]);
    // }
    // printf("\n");


// Dynamic Array
    int size = 3;
    int *arr = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < 3; i++) {
        arr[i] = i;
    }

    size = 5;
    arr = (int *)realloc(arr, size * sizeof(int));

    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");


// 2D Array
    // int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
    // OR
    // int **arr = (int **)malloc(2 * sizeof(int *));
    // for (int i = 0; 1 < 2; i++)
    //     arr[i] = (int *)malloc(3 * sizeof(int));

}