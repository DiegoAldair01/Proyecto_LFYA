int main(){
    int n;
    int m;
    

    //Solicitar números a multiplicar a usuario
    printf("Ingrese el primer número: ");
    scanf("%d", &n);
    printf("Ingrese el segundo número: ");
    scanf("%d", &m);


    //Crear cintas del automata
    int tamano1 = (n+m)+1;
    int tamano2 = (n*m);
    char cinta1[tamano1];
    char cinta2[tamano2];

    //Llenar cinta 1 con la secuencia
    memset(cinta1, 'a', n);
    memset(cinta1+n, 'b', m);
    cinta1[n+m] = 'c';
    cinta1[n+m+1] = 'B';

    // Imprimir contenido de la cinta 1
    printf("Cinta 1: %s\n", cinta1);

    int flag = 0;
    int apuntador = 0;
    //Recorrer cinta 1 y llenar cinta 2
    for(int i = 0; i < tamano1; i++){
        printf("Posición %d: %c\n", i, cinta1[i]);

        //Verificar primer a
        if(cinta1[i] == 'a' && flag == 0){
            cinta2[i] = 'x';
            flag = 1;
            i++;
        }
        else if(cinta1[i] == 'a')
        {
            cinta1[i] = 'a';
            i++;
            while (cinta1[i] == 'a')
            {
                cinta1[i] = 'a';
                i++;
            }
            
        } 
        else if(cinta1[i] == 'b'){
            cinta1[i] = 'b';
            cinta2[apuntador] = 'y';
            i++;
            apuntador++;
            while (cinta1[i] == 'b')
            {
                cinta1[i] = 'b';
                cinta2[apuntador] = 'y';
                i++;
                apuntador++;
            }
        }
        else if(cinta1[i] == 'c'){
            cinta1[i] = 'c';
            //Debemos hacer algo para que vaya a la izquierda
        }
            
        


    }


    //Mostrar resultado
    printf("El resultado de la multiplicación es: %d\n", n*m);

    return 0;
}
