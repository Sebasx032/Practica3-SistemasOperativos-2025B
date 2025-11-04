# Ejercicio 3.1.3Modificado - Creación de un proceso hijo sin que quede huérfano

## Descripción
Este ejercicio muestra cómo crear un **proceso hijo** utilizando la llamada al sistema **`fork()`** y cómo asegurarse de que **el hijo no quede huérfano**, es decir, que siempre tenga un proceso padre activo durante su ejecución.

Se imprime el **PID** del proceso hijo, su **PPID** y el **PID** del proceso padre, demostrando la relación entre ambos procesos.

## Funcionamiento del código
1. El proceso padre inicia e imprime su **PID**.  
2. Se ejecuta la llamada `fork()` para crear un proceso hijo:  
   - En el **proceso hijo**, `fork()` devuelve `0`.  
   - En el **proceso padre**, `fork()` devuelve el **PID del hijo**.  
3. El proceso hijo imprime su **PID** y el **PPID**.  
4. El proceso padre llama a `wait(0)` para **esperar a que el hijo termine**, evitando que quede huérfano.  
5. Ambos procesos imprimen un mensaje indicando el **final de su ejecución**.  
