#include <stdio.h>
#include <stdlib.h>

typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
   DIV,
   UNSUPPORTED
} MathOperation;

void IssueBadNumberError()
{
    printf("The string does not represent a floating point number.\n");
    exit(EXIT_FAILURE);
}

void IssueBadOperationError()
{
    printf("The string does not represent a valid operation.\n");
    exit(EXIT_FAILURE);
}

MathOperation GetOperation(char *op)
{
    if (op[1] != '\0') {
        return UNSUPPORTED;
    }
    if (*op == '+') {
        return ADD;
    }
    else if (*op == '-') {
        return SUBTRACT;
    }
    else if (*op == 'x') {
        return MULT;
    }
    else if (*op == '/') {
        return DIV;
    }
    else {
        return UNSUPPORTED;
    }
}

double StringToDouble(char *str)
{
    char *endptr;
    double result = strtod(str, &endptr);
    if (str == endptr) {
        IssueBadNumberError();
        return 0.0;
    }
    else if (*endptr != '\0') {
        IssueBadNumberError();
        return 0.0;
    }
    else {
        return result;
    }
}

int main(int argc, char *argv[])
{
    double v = StringToDouble(argv[1]);
    MathOperation op = GetOperation(argv[2]);
    double v2 = StringToDouble(argv[3]);
    double result = 0.;
    switch (op)
    {
       case UNSUPPORTED:
         IssueBadOperationError();
         break;
       case ADD:
         result = v + v2;
         break;
       case MULT:
         result = v * v2;
         break;
       case SUBTRACT:
         result = v - v2;
         break;
       case DIV:
         result = v / v2;
         break;
    }
    printf("%d\n", (int) result);
 
    return 0;
}
