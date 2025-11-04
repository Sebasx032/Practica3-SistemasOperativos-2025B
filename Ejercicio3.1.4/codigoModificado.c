#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_PROC 3

void hijoHaceAlgo(int numero);

int main() {
    int i, pid;

    // El padre crea los hijos de forma secuencial
    for (i = 1; i <= NUM_PROC; i++) {
        pid = fork();

        if (pid < 0) {
            perror("Error al crear el proceso");
            exit(1);
        }

        if (pid == 0) {
            // Código del hijo
            hijoHaceAlgo(i);
            exit(0);  // El hijo termina aquí después de su tarea
        } else {
            // Código del padre (espera al hijo actual)
            wait(NULL);  // El padre espera a que el hijo termine
            printf("Mi hijo %d ha terminado.\n", i);
        }
    }

    printf("\nTodos los hijos han terminado. El padre finaliza.\n");
    return 0;
}

void hijoHaceAlgo(int numero) {
    int i;

    switch (numero) {
        case 1:
            printf("\n[Hijo 1 - PID=%d] Contando del 1 al 10:\n", getpid());
            for (i = 1; i <= 10; i++) {
                printf("%d ", i);
                usleep(200000);  // Dormir 0.2 segundos para hacer visible la ejecución
            }
            printf("\n");
            break;

        case 2:
            printf("\n[Hijo 2 - PID=%d] Mostrando pares hasta 20:\n", getpid());
            for (i = 2; i <= 20; i += 2) {
                printf("%d ", i);
                usleep(200000);  // Dormir 0.2 segundos para hacer visible la ejecución
            }
            printf("\n");
            break;

        case 3:
            printf("\n[Hijo 3 - PID=%d] Mostrando múltiplos de 3 hasta el 30:\n", getpid());
            for (i = 1; i <= 10; i++) {
                printf("%d ", i * 3);
                usleep(200000);  // Dormir 0.2 segundos para hacer visible la ejecución
            }
            printf("\n");
            break;

        default:
            printf("Número de hijo no válido.\n");
    }
}
