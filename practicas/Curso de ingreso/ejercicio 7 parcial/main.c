#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota;
    char sexo;
    char i;
    int acumuladorNotas;
    int contadorNotas;
    float promedioNotas;
    int notaMinima;
    char notaMinimaSexo;
    int contadorVaronAprobado;


    acumuladorNotas=0;
    contadorNotas=0;
    contadorVaronAprobado=0;

    for(i=0;i<5;i++)
    {
        do
        {
            printf("Ingrese una nota del 1 al 10\n");
            scanf("%d",&nota);
        }while(nota<1||nota>10);

        do
        {
            printf("\nIngrese sexo, f o m: \n");
            fflush(stdin);
            scanf("%c",&sexo);
        }while(sexo!='f'&&sexo!='m');

        acumuladorNotas+=nota;
        contadorNotas++;

        if(i==0||nota<notaMinima)
        {
            notaMinima=nota;
            notaMinimaSexo=sexo;
        }

        if(sexo=='m'&&nota>5)
        {
            contadorVaronAprobado++;
        }

    }
    system("cls");//lleva comillas
    promedioNotas=(float)acumuladorNotas/contadorNotas;
    printf("\nEl promedio de notas totales es %.2f",promedioNotas);
    printf("\nLa nota minima es %d y es del sexo %c",notaMinima,notaMinimaSexo);
    printf("\nLa cantidad de varones aprobados son %d\n",contadorVaronAprobado);

    return 0;
}
