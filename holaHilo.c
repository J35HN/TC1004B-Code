#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 20
int saldo;

void * suma100(void *arg){
    //char *c = (char *)arg; // regresarlo a su original, en caso de querer usar un argumento.
    //printf("hola desde un hilo %s \n",c);
    int lsaldo = saldo;
    lsaldo += 100;
    saldo = lsaldo;
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS]; // Guardar los id's de cada hilos creados
    saldo = 0;
    char *s = "soy un argumento";
    for(int i=0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, suma100, NULL); // Donde guardar (&porque modifica), [], función a ejecutar, parámetro en la función.
    }
    for(int i=0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL); // 
    }
    printf("Saldo final es de %d\n", saldo);
    pthread_exit(NULL); // Que el hilo anterior termine. Pero el codigo después no se ejecuta, porque termina el hilo principal. 
    return 0;
}