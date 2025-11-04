# Ejercicio 3.1.2 - Comunicación entre procesos con **pipe()**

## Descripción
Este ejercicio muestra cómo establecer comunicación entre un **proceso padre** y un **proceso hijo** utilizando una **tubería (pipe)** en C.  
El padre genera una serie de valores y los envía al hijo a través de la pipe. El hijo recibe los valores y los registra en un archivo de texto llamado `valores.txt`.

Se demuestra el uso de **pipes anónimas**, el manejo de **lectura y escritura en la tubería**, y la **sincronización de procesos** mediante `wait()`.

## Funcionamiento del código
1. Se crea una **pipe** usando `pipe(pipefd)`, donde:
   - `pipefd[0]` es el **canal de lectura**.
   - `pipefd[1]` es el **canal de escritura**.
2. Se realiza un **fork()** para crear un proceso hijo:
   - En el **hijo** (`pid == 0`):
     - Se cierra el extremo de escritura (`pipefd[1]`) ya que solo va a **leer**.
     - Abre el archivo `valores.txt` para registrar los valores recibidos.
     - Utiliza `read()` en un bucle para recibir los enteros enviados por el padre.
     - Escribe cada valor en el archivo y cierra los recursos al terminar.
     - Imprime un mensaje indicando que los valores fueron registrados.
   - En el **padre** (`pid > 0`):
     - Se cierra el extremo de lectura (`pipefd[0]`) ya que solo va a **escribir**.
     - Genera 10 valores incrementando en 10 cada vez y los envía al hijo mediante `write()`.
     - Incluye una pequeña pausa (`usleep`) para simular tiempo de ejecución.
     - Cierra el extremo de escritura y espera a que el hijo termine con `wait()`.
     - Imprime un mensaje indicando que el hijo finalizó.
3. Si `fork()` o `pipe()` fallan, se imprime un mensaje de error y se termina el programa.

## Ejemplo de salida esperada
