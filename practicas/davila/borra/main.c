#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra='a';
    for(int i=0;i<26;i++)
    {
        printf("%c\n",letra);
        letra=letra+1;
    }
    return 0;
}
