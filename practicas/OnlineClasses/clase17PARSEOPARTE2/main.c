#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[12]={12,15,32,76,87,89,98,23,54,67,11,22};
    int cant=1;
    FILE* f;

    f=fopen("misNumeros.csv","w");

    if(f==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<12;i++)
    {
        if(cant%4!=0)
        {
            fprintf(f,"%d,",vec[i]);
        }
        else
        {
            fprintf(f,"%d\n",vec[i]);
        }
        cant++;
    }

    fclose(f);
    return 0;
}
