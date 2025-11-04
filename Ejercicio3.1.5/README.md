# Ejercicio 3.1.5 - Creación de un proceso **zombie**

## Descripción
Este ejercicio demuestra cómo se crea un **proceso zombie** en un sistema operativo tipo UNIX cuando un **proceso hijo termina** pero su **proceso padre aún no ha leído su estado de salida** mediante una llamada a **`wait()`**.  

Un proceso zombie es aquel que **ya ha finalizado su ejecución**, pero **aún mantiene una entrada en la tabla de procesos** del sistema hasta que el padre recoja su estado. Esto ocurre porque el sistema debe conservar cierta información del hijo (como su código de salida) para que el padre pueda obtenerla.

## Funcionamiento del código
1. El proceso padre ejecuta una llamada a **`fork()`** para crear un proceso hijo.  
2. En función del valor devuelto por `fork()`:
   - Si **`pid > 0`**, el proceso actual es el **padre**:
     - Imprime un mensaje indicando que esperará **60 segundos** antes de terminar.
     - Llama a `sleep(60)` para mantenerse vivo, tiempo durante el cual el hijo ya habrá terminado.
     - Durante este tiempo, el hijo se convierte en **zombie**, ya que el padre no ejecuta `wait()`.
   - Si **`pid == 0`**, el proceso actual es el **hijo**:
     - Imprime un mensaje indicando que termina inmediatamente.
     - Llama a `exit(0)` para finalizar su ejecución.
   - Si **`pid < 0`**, significa que ocurrió un **error al crear el proceso** y se muestra un mensaje de error.
3. Mientras el padre está dormido, se puede usar el comando:  **`top`** para observar que el proceso hijo aparece con el estado **Z (zombie)**.
