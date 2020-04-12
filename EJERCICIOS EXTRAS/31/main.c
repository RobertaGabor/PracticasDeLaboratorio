#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int valorXHoraEmpleado;
    char nombre[20];
    float cantidadHorasXMes;
    float precioBruto;
    int antiguedad;
    float precioNeto;

    printf("Ingrese el valor por hora:\n");
    scanf("%d",&valorXHoraEmpleado);

    printf("Ingrese el nombre del empleado:\n");
    fflush(stdin);//se usa para pedir nobre compuesto

    printf("Ingrese cantidad de horas trabajadas en el mes:\n");
    scanf("%f",&cantidadHorasXMes);

    printf("Ingrese la antiguedad del empleado:\n");
    scanf("%d",&antiguedad);

    precioBruto=(float)valorXHoraEmpleado*cantidadHorasXMes+antiguedad*30;
    precioNeto=(float)precioBruto-(0.13*precioBruto);//hacer directo la division por 100
    printf("Nombre del empleado: %s\n",nombre);
    printf("NSu antiguedad es: %d\n",antiguedad);
    printf("Valor por hora es: %d\n",valorXHoraEmpleado);
    printf("Bruto: %.2f\n",precioBruto);
    printf("Neto: %.2f\n",precioNeto);
    printf("descuento de %.2f\n",precioBruto-precioNeto);


    return 0;
}
