#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>

#define DIM_NOTAS 100

int cargaArregloNotas(int a[], int v, int dim);
int sumaArreglo (int a[], int v);
float promedioNotas (int a[], int v);
void muestraArreglo (int a[], int v);
void dividirEnPilas (int a[], int v, Pila* aprobados, Pila* desaprobados);
void mostrarPila (Pila p);

int main()
{
    int notas [DIM_NOTAS];
    int validosNotas = 0;
    Pila aprobados;
    Pila desaprobados;
    inicpila(&aprobados);
    inicpila(&desaprobados);
    float promedio;

    //printf("\n Notas cargadas: \n");
    validosNotas = cargaArregloNotas(notas, validosNotas, DIM_NOTAS);

    printf("\n Listado cargadas: \n");
    muestraArreglo(notas, validosNotas);

    promedio = promedioNotas(notas, validosNotas);
    printf("\n El promedio de las notas es: %.2f \n", promedio);

    dividirEnPilas(notas, validosNotas, &aprobados, &desaprobados);
    printf("\n Alumnos aprobados: \n");
    mostrarPila(aprobados);
    printf("\n Alumnos desaprobados: \n");
    mostrarPila(desaprobados);

    return 0;
}
int cargaArregloNotas(int a[], int v, int dim) // Inciso 1.
{
    char opcion = 0;
    int notas;

    while ( v < dim && opcion != 27){
        printf("\n Ingrese una nota: \n");
        scanf("%d", &notas);
        if (notas > 0 && notas < 11){
            a[v] = notas;
            v++;
        } else {
            printf("\n La nota ingresada no es valida. \n");
            getch();
        }
        printf("\n Presione ESC para salir o cualquier tecla para continuar. \n");
        opcion = getch();
        system("cls");
    }

    return v;
}
int sumaArreglo (int a[], int v) // Inciso 2.
{
    int total = 0;
    for ( int i = 0; i < v; i++){
        total += a[i];
    }
    return total;
}
float promedioNotas (int a[], int v) // Inciso 3.
{
    float promedio = 0;

    if ( v > 0){
        promedio = (float) sumaArreglo(a, v) / v;
    }

    return promedio;
}
void muestraArreglo (int a[], int v) // Inciso 4.
{
    for (int i = 0; i < v; i++){
        if (i%10 == 0){
            printf("\n");
        }
        printf(" %d |", a[i]);
    }
}
void dividirEnPilas (int a[], int v, Pila* aprobados, Pila* desaprobados) //Inciso 5.
{
    for (int i = 0; i < v; i++){
        if(a[i] > 5){
            apilar(aprobados, a[i]);
        }else {
            apilar(desaprobados, a[i]);
        }
    }
}
void mostrarPila (Pila p) // Inciso 6.
{
    Pila aux;
    inicpila (&aux);
    int contador;

    while (!pilavacia(&p)){
        if (contador%15 == 0){
            printf("\n");
        }
        printf(" %d ", tope(&p));
        apilar(&aux, desapilar(&p));

        contador++;
    }
}
