# Implementación del juego ¿Quién es quién?

## Miembros del grupo

* Javier Galvez Obispo
* Yábir García Benchakhtir

## Métodos implementados

Se han implementado los métodos propuestos en el guión:

* `crear_arbol`
* `iniciar_juego`
* `información_jugada`
* `profundidad_promedio`


y los tres métodos adicionales que se pedían:

* `preguntas_formuladas`
* `aniade_personaje`
* `elimina_personaje`

## Mejoras realizadas

Se entregan además los métodos:

* `eliminar_nodos_redundantes()` - Dado un arbol elimina las preguntas
  que no hacen ninguna discriminación entre los personajes
  posibles. Este método modifica la estructura del arbol sin volver a
  crearlo.

* `crear_arbol_Optimizado()` - Implementa la contrucción del arbol
eligiendo las pregunta más adecuada en cada caso, siguiendo el
criterio que se propone en el guión, de elegir en cada momento la
pregunta que tienda a dividir el conjunto de personajes en dos partes
de tamaño proximo.  Con esta función vemos resultados que superan
claramente a la función `crear_arbol` en termino de preguntas promedio
necesarias para alcanzar un personaje. En la mayoría de casos las
mejoras superan al arbol resultado de limpiar las preguntas
redundantes.

* `elegirPreguntasOptimizado()` - Metodo que se usa para elegir la
  mejor pregunta en cada situación y que permite implementar el método
  anterior.

## Prueba del juego

En el archivo `main.cpp` se ha implementado un ejemplo para poder
mostrar el funcionamiento del programa. Durante la partida se puede
mostrar la información que se conoce del personaje usando la tecla `i`
y pulsando `enter`.





