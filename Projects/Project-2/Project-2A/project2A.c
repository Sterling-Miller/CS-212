// Program that finds the odd, composite numbers between 10 and 500
#include <stdio.h>

int main() {
    for (int i = 10; i <= 500; i++) {
        for (int j = i - 1; j > 1; j--) {
            if (i % j == 0 && i % 2 != 0) {
                printf("%d is a composite number.\n", i);
                break;
            }
        }
    }
    return 0;
}
