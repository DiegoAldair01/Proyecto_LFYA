#include <stdio.h>
#include <string.h>

int main(){
    int a;
    int b;
    

    //Solicitar números a multiplicar a usuario
    printf("Ingrese el primer número: ");
    scanf("%d", &a);
    printf("Ingrese el segundo número: ");
    scanf("%d", &b);


    //Crear cintas del automata
    int tamano1 = (a+b)+2;
    int tamano2 = (a*b);
    int cinta1[tamano1];
    int cinta2[tamano2];


    //Mostrar resultado
    printf("El resultado de la multiplicación es: %d\n", a*b);

    return 0;
}


