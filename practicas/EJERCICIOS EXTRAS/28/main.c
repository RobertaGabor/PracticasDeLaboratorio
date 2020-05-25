#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int j;
    int flag;

    for(i=100;i>-1;i--)
    {
        flag=0;
        for(j=i-1;j>1;j--)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
         if(flag==0)
        {
            printf("%d\n",i);
        }
    }

    return 0;
}
