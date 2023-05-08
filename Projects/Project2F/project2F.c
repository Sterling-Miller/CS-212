#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(char *s)
{
    int len = 0;
    while (*s != '\0') {
        len++;
        s++;
    }
    // for (int i = 0; s[i] != "\0"; i++)
    //     len++;
    return len;
}

void str_reverse(char *str)
{
    int len = my_strlen(str);
    for (int i = 0; i < (len / 2); i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

int main()
{
    char *str = malloc(strlen("hello world")+1);
    strcpy(str, "hello world");
    str_reverse(str);
    if (strcmp(str, "dlrow olleh") == 0)
    {
        printf("Congrats!  You have successfully reversed \"hello world\" to \"%s\"\n", str);
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Project does not work yet.  You reversed \"hello world\" to \"%s\"\n", str);
        exit(EXIT_FAILURE);
    }
}
