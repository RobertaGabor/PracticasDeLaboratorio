#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    /*printf("Hello world!\a\rBello\n");
    printf("\tGoodbye people\n");
    printf("Goodbye \tpeople\n");

    char nombre[20]="PEDRO";

    nombre[0]=nombre[0]+32;

    printf("%s\n",nombre);*/

    int* a;
    int b=10;
    a=&b;
    printf("%d\n",*a);

    long long int n=100001010111010100;
    char str1[] = "abcde2fghi3jk4l";
    char str2[] = "534";
    char *ret;

    ret = strpbrk(str1, str2);
    if(ret)
    {
        printf("First matching character: %c\n", *ret);
    }
    else
    {
        printf("Character not found");
    }
    printf("%d\n",n);


    return 0;
}
