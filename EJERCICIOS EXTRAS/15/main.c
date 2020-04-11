#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    for(i=0;i<101;i++)
    {
        if(i%6==0)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
