#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];       // pipefd[0] para leer, pipefd[1] para escribir
    pid_t pid;
    int i, valor;

    // Creamos la tubería
    if (pipe(pipefd) == -1) {
        perror("Error al crear la pipe");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Error al crear el proceso hijo");
        exit(1);
    }

    if (pid == 0) {  // Código del hijo
        FILE *archivo = fopen("valores.txt", "w");
        if (archivo == NULL) {
            perror("Error al abrir el archivo");
            exit(1);
        }

        close(pipefd[1]); // Cierra el lado de escritura en el hijo

        while (read(pipefd[0], &valor, sizeof(int)) > 0) {
            fprintf(archivo, "Valor recibido: %d\n", valor);
        }

        fclose(archivo);
        close(pipefd[0]);
        printf("Hijo: se han registrado los valores en valores.txt\n");
        exit(0);
    } else {  // Código del padre
        close(pipefd[0]); // Cierra el lado de lectura en el padre

        valor = 0;
        for (i = 1; i <= 10; i++) {
            valor += 10;
            printf("Padre: valor actual = %d\n", valor);
            write(pipefd[1], &valor, sizeof(int)); // Envía el valor al hijo
            usleep(100000); // Pequeña pausa para simular tiempo de ejecución
        }

        close(pipefd[1]); // Cierra el pipe para que el hijo termine
        wait(0);          // Espera a que el hijo termine
        printf("Padre: el hijo ha terminado\n");
    }

    return 0;
}
