#include <stdio.h>
#include <stdlib.h>
int mosttrarMenu ();//int porque switch hice co numeros
void saludar ();
void brindar ();
void hacerBrindis (char conQue []);//no va en h. ya que es auxiliar.
//si compilas con esa en h te va aseguir apareciendo
void resetFlag (int* p);
int main()
{
    char seguir = 's';//ya tiene un valor y si va a salir en la opcion salir le cambiamos el valor
    //si en salir pongo if seguir es !=s, hay que inicializarla.
    //si la primera vez no sale, se va a cargar en while, pero sino explotaria.
    int flagSaludo = 0;//las reseteo cuando termina, en despedirse
    int flagBrindis = 0;//se pueden resetear con una funcion que agarre la direccion de memoria y lo vuelva a poner en 0
    do
    {
        switch(mostrarMenu)//llama a la funcion menu
        {
        case 1:
            saludar();//llama a la funcion saludar
            flagSaludo=1;
            break;
        case 2:
            if(flagSaludo)
            {
                brindar();
            }
            else
            {
                printf("PRimero salude choto");
            }
            break;
        default:
            printf("no valido compra");
        }
    }while(seguir=='s');

    return 0;
}
int mostrarMenu()
{
    int opcion;
    system ("cls");
    printf("****menu de opciones****")//adornar jeje
    printf("1-saludar\n");
    printf("2-brindar\n");
    printf("Indique opcion woo\n");
    scanf();
    return opcion;
}
void brindar()
{
    char bebida [20];
    printf("escriba con que va a brindar")
    fflush();
    gets(bebida);

    hacerBrindis(bebida);
}
void hacerBrindis(char conQue [])//funcion auxiliar ed otra funcion
{//elimino el prototipo y lo pongo en el c donde esta main. para wue ndie lo vea.
    printf("chin chin estamos brindando con %s",conQue);
}
void resetFlag (int* p)
{
    *p=0;
}
