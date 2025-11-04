# Ejercicio 3.1.1 - Creación de procesos con fork()

##  Descripción
Este ejercicio muestra el funcionamiento de la llamada al sistema **`fork()`**, la cual permite crear un nuevo proceso hijo a partir de un proceso padre.  
Ambos procesos se ejecutan de manera independiente y muestran sus identificadores de proceso (**PID**) y del proceso padre (**PPID**).

##  Funcionamiento del código
1. El proceso padre inicia e imprime su **PID**.  
2. Se ejecuta la llamada `fork()`, que crea un proceso hijo.  
   - En el **proceso hijo**, `fork()` devuelve `0`.  
   - En el **proceso padre**, `fork()` devuelve el PID del hijo.  
3. Cada proceso continúa su ejecución de forma concurrente, ejecutando su bloque de instrucciones.  
4. Se utiliza `sleep()` para introducir una pequeña pausa, facilitando la observación del orden en que los procesos imprimen sus mensajes.  
