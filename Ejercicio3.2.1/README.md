# Ejercicio 3.2.1 - Creación y ejecución de un proceso hijo con `execl()`

## Descripción
Este ejercicio muestra cómo crear un **proceso hijo** utilizando **`fork()`** y luego ejecutar un **programa externo** dentro del hijo mediante la llamada al sistema **`execl()`**.  
El padre espera a que el hijo termine su ejecución y luego imprime un mensaje indicando que el hijo ha finalizado.

Se utiliza `execl()` para reemplazar la imagen del proceso hijo con un nuevo programa, en este caso, el programa **`ejercicio3_1_1`** previamente compilado.

## Funcionamiento del código
1. La función `ejecutarNuevoProc()` realiza las siguientes acciones:
   - Llama a **`fork()`** para crear un proceso hijo.
   - En el **hijo** (`pid == 0`):
     - Llama a **`execl()`** para ejecutar el programa externo `./ejercicio3_1_1`.
     - Si `execl()` falla, imprime un mensaje de error y termina con `exit(1)`.
   - En el **padre** (`pid > 0`):
     - Devuelve el **PID del hijo**.
   - Si ocurre un error al crear el hijo (`pid == -1`), se imprime un mensaje de error y el programa termina.
2. En `main()`:
   - Se llama a `ejecutarNuevoProc()` para crear y ejecutar el proceso hijo.
   - El padre llama a **`wait(0)`** para esperar a que el hijo termine.
   - Después de que el hijo finaliza, el padre imprime un mensaje indicando que el proceso hijo con su PID ha finalizado.
