#include <stdio.h>
#include <stdlib.h>
#define TAM 5 //el tam adquiere el valor de la derecha

//una funcion que sea mostrar vector y te o muestre void mostrarvector (int x[],int tam) --abajo--

void mostrarVector (int x[],int tam);//no puedo hacer x[5], tiene que ser vector y aparte el tamaño
// []notacion vectorial
//lo mismo que (int* x, int tam)


/*pedir 5 datos l usuario. mostrar como fue ingresado y despues mostrar del ultimo al primero*/ //--abajo--
int main()
{
    int ingreso[TAM];
    int maximo;
    float promedio;
    int contadorPromedio=0;
    int acumuladorPromedio=0;
    int numeroBuscado;
    int flag;
    int contadorBuscado=0;
    //int maximoUbicacion;

    for(int i=0;i<TAM;i++)//siempre que lo recorro uso for
    {
        printf("Ingrese un numero: ");
        scanf("%d",&ingreso[i]);
    }

    printf("::::funcion::::\n");
    mostrarVector(ingreso,TAM);//paso nombre de vector declarado en main
    //aca si se pasa TAM en la funcion NO
    printf("\n::::fin de funcion:::\n");
    printf("\nResultado derecho\n");
    for(int i=0;i<TAM;i++)//ASI SE MUESTRAN LO RESULTADOS
    {
        printf("%d ",ingreso[i]);
    }
    printf("\nOrden inverso\n");
    for(int i=TAM-1;i>=0;i--)
    {
        printf("%d ",ingreso[i]);
    }

    for(int i=0;i<TAM;i++)//siempre que lo recorro uso for
    {
        if(i==0||ingreso[i]>maximo)
        {
            maximo=ingreso[i];
            //maximoUbicacion= i + 1;//e i solo es la posicion, y como usamos la posicion HUMANA 0 no existe porque /0 no existe.
        }
    }

    printf("\nEl mayor numero ingresado es: %d y esta en las posiciones: ",maximo);/*maximoUbicacion*/
    //si en for de mayor se repite el mayor queda el primero si pongo mayor o igual queda el ultimo
    //lo correcto si se ingresa 2 veces es mostrar las 2 veces
    //inicializar int en el for

   for(int i=0; i<TAM;i++)
    {
       if(ingreso[i]==maximo)//vuelve a ver es vector y ya sabiendo el maximo, busco todos los que hay
       {
           printf("%d ",i+1);//posicion humana
       }
    }

    for(int i=0;i<TAM;i++)
    {
        acumuladorPromedio+=ingreso[i];
        contadorPromedio++;//en vez de esto puedo poner directo 5
    }

    promedio=(float)acumuladorPromedio/contadorPromedio;
    printf("\nEl promedio de los numeros ingresados es: %.2f\n",promedio);

    printf("Ingrese el numero que desea buscar: ");
    scanf("%d",&numeroBuscado);

    for(int i=0;i<TAM;i++)
    {
        flag=0;
        if(numeroBuscado==ingreso[i])
           {
                flag=1;//no usar bandera a menos que sea bandera. esto no es bandera
                break;
           }
    }

    for (int i=0;i<TAM;i++)
    {
        if(numeroBuscado==ingreso[i])
        {
            contadorBuscado++;
        }
    }

    if(flag==1)//redundante puedo poner solo flag
    {
        printf("El numero esta en el array y esta %d veces\n",contadorBuscado);
    }
    else
    {
        printf("El numero no esta en el array\n");
    }




    printf("\n\n");
    return 0;
}

void mostrarVector (int x[],int tam)//tam distinto a TAM, tam es nombre de parametro formal y TAM es directiva de preprocesador.TAM SOLO MAIN
{
    for(int i=0;i<tam;i++)
    {
        printf("%d ",x[i]);
    }
}
