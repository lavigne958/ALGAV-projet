#include <stdio.h>

int main(){
    char string[5] = "toto\0";

    char* p = string;

    printf("string: %s -- p: %s\n",string, p);
    p = &string[2];
    printf("string: %s -- p: %s\n",string, p);

    return 0;
}

