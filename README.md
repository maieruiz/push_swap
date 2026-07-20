*Este proyecto ha sido creado como parte del currículo de 42 por mairuiz y amarlasc.*

# Descripción

El objetivo del proyecto de `push_swap` es ordenar una pila de números enteros utilizando un conjunto limitado de operaciones
y generando la menor cantidad de movimientos posibles. En el caso de que no se seleccione un algoritmo para la ordenación, el programa
lo seleccionará automaticamente atendiendo al grado de desorden:
- **Simple (O(n2))**: Si el desorden es < 0,2, el algoritmo utilizado es el de la extracción del mímino.
- **Medium (O(n√n))**: Si el desorden es mayor o igual que 0,2 y menor que 0,5, el algoritmo utilizado es el del orden basado en chunks diviendo en √n chunks.
- **Complex (O(nlogn))**: Si el desorden es mayor que 0,5, el algortimo utilizado es la adaptación del orden mediante radix.

# Instrucciones

## Compilación
Clona el repositorio y compila el proyecto ejecutando:
```
git clone <URL_DEL_REPOSITORIO>
cd push_swap
make
```
Se generará el ejecutable `push_swap`

## Limpieza de archivos
Para limpiar archivos objeto:
```bash
make clean
```
Para eliminar la librería compilada:
```bash
make fclean
```
Para recompilar el proyecto desde cero:
```bash
make re
```

## Uso

Ejecuta el programa pasando como argumentos la secuencia de números enteros que deseas ordenar:
```
./push_swap 3 2 5 1 4
```
El programa imprimirá por pantalla la secuencia de operaciones necesarias para ordenar la pila.

## Comandos posibles

### Selección de algoritmmo

Puedes forzar la ejecución de un algoritmo concreto utilizando uno de los siguientes parámetros:

- `./push_swap --simple 3 2 5 1 4`: utiliza el algoritmo de extracción sucesiva del mínimo, es la más óptima para conjuntos pequeños.
- `./push_swap --medium 3 2 5 1 4`: utiliza el algoritmo basado en chunks, optimizado para tamaños intermedios.
- `./push_swap --complex 3 2 5 1 4`: utiliza una adaptación de Radix Sort basada en la indexación de los elementos, pensada para conjuntos grandes.
- `./push_swap --adaptive  3 2 5 1 4`: elige el algoritmo a utilizar dependiendo del grado de desorden del conjunto.

Si no se especifica ninguno de estos parámetros, el programa ejecutará automáticamente el modo adaptative.

### Verificación del checker
Para comprobar que las operaciones generadas son correctas, puedes utilizar el programa checker proporcionado por 42:

`ARG="3 2 5 1 4" ./push_swap $ARG | ./checker_linux $ARG`

Si la secuencia de operaciones ordena correctamente la pila, el resultado será: `OK`

En caso contrario, el programa mostrará: `KO`

### Modo benchmark

El parámetro `--bench` activa el modo benchmark, que muestra información adicional sobre la ejecución del algoritmo. Además de imprimir las operaciones realizadas, proporciona estadísticas útiles para evaluar su rendimiento.

Ejemplo:
```
./push_swap --bench --medium 3 2 5 1 4
```
Este modo resulta especialmente útil para comparar algoritmos, analizar el número de movimientos realizados.

### Operaciones disponibles

- `sa`: Intercambia los dos primeros elementos de la pila **A**.
- `sb`: Intercambia los dos primeros elementos de la pila **B**.
- `ss`: Ejecuta simultáneamente `sa` y `sb`, intercambiando los dos primeros elementos de ambas pilas.
- `pb`: Mueve el primer elemento de la pila **A** a la parte superior de la pila **B**.
- `pa`: Mueve el primer elemento de la pila **B** a la parte superior de la pila **A**.
- `ra`: Rota la pila **A** hacia arriba, desplazando el primer elemento al final.
- `rb`: Rota la pila **B** hacia arriba, desplazando el primer elemento al final.
- `rr`: Ejecuta simultáneamente `ra` y `rb`, rotando ambas pilas hacia arriba.
- `rra`: Rota la pila **A** hacia abajo, desplazando el último elemento al principio.
- `rrb`: Rota la pila **B** hacia abajo, desplazando el último elemento al principio.
- `rrr`: Ejecuta simultáneamente `rra` y `rrb`, rotando ambas pilas hacia abajo.


## Funciones utilizadas

### Realizadas por *amarlasc*

- `validate_format`: Comprueba que todos los argumentos tengan un formato numérico válido.
- `is_valid_number`: Verifica que una cadena represente un número entero válido.
- `convert_to_long`: Convierte los argumentos de entrada en un array de valores long.
- `compute_disorder`: Calcula el grado de desorden de la pila mediante el porcentaje de inversiones.
- `correct_stack`: Valida que la entrada sea correcta y pueda convertirse en una pila válida.
- `check_args`: Ejecuta todas las comprobaciones necesarias sobre los argumentos de entrada.
- `check_int_limits`: Comprueba que todos los valores estén dentro del rango de un int.
- `check_duplicates`: Verifica que no existan valores duplicados en la entrada.
- `count_args`: Cuenta el número total de argumentos recibidos.
- `ft_atol`: Convierte una cadena de caracteres en un valor de tipo long.
- `simple_algorithm`: Ordena la pila utilizando el algoritmo basado en la extracción sucesiva del elemento mínimo.


### Realizadas por *mairuiz*

- `choose_strategy`: Selecciona la estrategia de ordenación más adecuada según la configuración del programa.
- `create_program`: Reserva memoria e inicializa la estructura principal del programa.
- `create_new_stack`: Crea e inicializa una pila vacía.
- `create_stack`: Construye la pila a partir de los argumentos de entrada.
- `create_node`: Crea e inicializa un nuevo nodo con el valor indicado.
- `add_back_node`: Inserta un nodo al final de una pila.
- `create_benchmark`: Crea e inicializa la estructura utilizada para recopilar estadísticas de ejecución.
- `print_benchmark`: Muestra por pantalla las estadísticas recopiladas durante la ejecución.
- `set_program`: Configura los parámetros del programa a partir de los argumentos recibidos.
- `medium_algorithm`: Ordena la pila utilizando el algoritmo basado en chunks.
- `rotate_to_min`: Rota la pila hasta situar el elemento mínimo en la parte superior.
- `set_stack_index`: Asigna un índice ordenado a cada elemento de la pila.
- `next_chunk`: Actualiza el rango del siguiente chunk que debe procesarse.
- `set_chunk`: Configura los límites y parámetros de un chunk.
- `create_chunk`: Reserva memoria e inicializa una estructura `t_chunk`.


### Realizadas conjuntamente
- `adaptive_algorithm`: Selecciona y ejecuta automáticamente el algoritmo de ordenación más adecuado según el tamaño de la entrada.
- `complex_algorithm`: Ordena la pila utilizando una adaptación del algoritmo **Radix Sort** basada en la indexación de los elementos.
- `is_sorted`: Comprueba si la pila se encuentra ordenada.
- `superfree`: Libera toda la memoria reservada por el programa antes de finalizar su ejecución.
- `call_algorithm`: Ejecuta el algoritmo de ordenación seleccionado.

# Recursos

- La web de [42-cursus.gitbook.io](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)
- Vídeos de YouTube sobre el método de ordenación con Chunks
    - https://www.youtube.com/watch?v=OaG81sDEpVk
- Vídeos de YouTube sobre Radix Sort:
    - https://www.youtube.com/watch?v=XiuSW_mEn7g
    - https://www.youtube.com/watch?v=Y95a-8oNqps
- En este proyecto se ha utilizado inteligencia artificial como herramienta de apoyo para la explicación de funciones y conceptos de C. Además para la mejora de estilo en descripciones técnicas. La IA no ha sido utilizada para la implementación del código, sino únicamente como soporte de aprendizaje y documentación [ChatGPT](https://chatgpt.com/) y [Claude](https://claude.ai/new/)