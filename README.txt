Discusión sobre el uso de herencia y polimorfismo
Use herencia para poder crear el tablero, tengo una clase que se llama Tile que tiene el tipo de casilla que es, 
y un método virtual para poder calcular la casilla a la que se va a avanzar, findSpot. Después tengo las clases de SnakeTile y de LadderTile 
que heredan de la clase Tile. Estas clases derivadas implementan la función findSpot diferente, regresando si se avanza la recompensa 
en el caso de LadderTile o si se retrocede el penalty, en el caso de SnakeTile. Para aplicar el polimorfismo en la clase Board, tengo un arreglo
de apuntadores a Tiles, y se llama de manera polimorfica las funciones de findSpot y el getter de el tipo de casilla que son. 

Use la sobrecarga de operadores dentro de la clase Board, cambie la función de calcluar spot por una sobrecarga del operador +, de manera que cuando 
a un objeto de la clase Board se le sume un int regresa la suma del penalty o reward al lugar donde estaba el jugador.

Use el manejo de execpciones para validad la entrada del tamaño del tablero, si el usuario ingresa un tamaño mayor a 50, el porgrama lanza una 
excepción y le asigna al tablero el tamaño default de 30 casillas, si se ingresa una cantidad adecuada el programa continua normal. 