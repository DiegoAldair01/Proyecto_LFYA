#include <stdio.h>
#include <string.h>

int main() {
    int n, m;

    // Solicitar números a multiplicar al usuario
    printf("Ingrese el primer número: ");
    scanf("%d", &n);
    printf("Ingrese el segundo número: ");
    scanf("%d", &m);

    // Crear cintas del automata
    int tamano1 = (n + m) + 1; // +1 para 'B'
    int tamano2 = (n * m);
    char cinta1[tamano1];
    char cinta2[tamano2];

    // Llenar cinta 1 con la secuencia
    memset(cinta1, 'a', n);
    memset(cinta1 + n, 'b', m);
    cinta1[n + m] = 'C';

    // Imprimir contenido de la cinta 1
    printf("Cinta 1: %s\n", cinta1);

    int apuntador = 0;
    int counter = 0;
    int i = 0;

    // Recorrer cinta 1 y llenar cinta 2
    while(counter != n){
        // Verificar primer 'a'
        if (cinta1[i] == 'a') {
            cinta1[i] = 'x';
            
            i++;
            while (cinta1[i] == 'a') {
                i++;
            }
        } else if (cinta1[i] == 'b') {
            // 'b' en cinta 1, primera 'y' en cinta 2
            cinta2[apuntador] = 'y';
            i++;
            apuntador++;
            // al encontrar segunda y siguientes 'b', agregar 'y' a cinta 2 por cada 'b'
            while (cinta1[i] == 'b') {
                cinta2[apuntador] = 'y';
                i++;
                apuntador++;
            }
        } else if (cinta1[i] == 'C') {
            // 'C' en cinta 1, movimiento a la izquierda
            i--; // Retroceder un paso
            while (i >= 0 && cinta1[i] != 'x') {
                i--;
            }
            // Encontrar 'x' y moverse a la derecha
            i++;
            counter++;
            printf("Cinta 1: %s\n", cinta1);

        }
    }

    // Mostrar resultado
    printf("Cinta 2: %s\n", cinta2);

    // Calcular el número de elementos en el arreglo
    size_t numeroElementos = sizeof(cinta2) / sizeof(cinta2[0]);

    // Imprimir el número de elementos
    printf("El resultado de la multiplicación es: %zu\n", numeroElementos);

    return 0;
}

