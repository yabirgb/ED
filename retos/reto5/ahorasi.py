import random
from itertools import product, islice, repeat


# numbers = [119, 85, 43, 141, 72, 91, 109]


M = 7

# Función primaria de hash
def h(k):
    return k % M

# Coeficinte para la i-ésima función de hashing
def d(i, a, c):
    if i == 0:
        return 0
    else:
        return (a*d(i-1, a, c) + c) % M
    
# i-ésima función de hashing
def hi(k, i, a, c):
    if i == 0:
        return h(k)
    else:
        return (h(k) + d(i, a, c)) % M


# Función que comprueba si la función hash no ha rellenado
# todas las funciones antes de repetir posiciones
def has_cycled(sequence, m=M):

    if len(sequence) > m:
        return True

    return False

# Función que realiza las insercciones según el criterio de h(i)
def completa(p):

    # Creamos un vector para detectar si una posición está ocupada ya
    # y para llevar recuento de los intentos que hemos necesitado para
    # introducir el elemento
    positions = ['-']*M
    
    # Vamos a intentar insertar el mismo número todo el rato 
    for n in repeat(8, M):
        i = 0 #Indice que indica que función usamos
        pos = hi(n, i, p[0], p[1]) # Calculamos la posición que corresponde

        
        sequence = []

        # Mientras no encontremos un hueco vacio y la iteración sea menor que el tamaño
        # que introducimos

        has_cycle = False
        
        while positions[pos] != '-' and not has_cycle:
            # Incrementamos el subindice de la función
            i+= 1
            
            #Añadimos la posición que hemos intentado la última vez
            #print(positions, i, pos,p, sequence)
            has_cycle = has_cycled(sequence)
            old = pos

            # Recalculamos la posición
            pos = hi(n, i, p[0], p[1])
            sequence.append(pos)


                    
        #Si hemos iterado todas las veces y seguimos teniendo un colapso
        if positions[pos] != '-':
            # Devolvemos que la combinación es mala
            return False, 0

        # En caso contrario insertamos en la posición correspondiente
        # y almacenamos el valor. Sumamos 1 porque empezamos en 0
        positions[pos] = i+1
        

    #print(positions, iterations, p[0], p[1])
    # De volvemos una tupla que nos indica si ha funcionado bien
    # y la cantidad total de veces que hemos llamado a las funciones de inserción
    return (True, sum(filter("-".__ne__, positions)))




completados = []

# Hacemos todas las parejasde números hasta M
# No tiene sentido buscarlos más grandes porque en la función `d`
# hacemos módulo M
pairs = list(product(range(0, abs(M+1)), range(0, abs(M+1))))
#pairs.remove((0,0))

for p in pairs:

    result, cost = completa(p)
    #print(p, result, "\n=======")
    if result == False:
        completados = [j for j in completados if j != p]
    else:
        completados.append( (p,result, cost) )

verifican = islice(filter(lambda x: x[1] == True, completados), 30)

for i in sorted(list(verifican), key = lambda tup: tup[2], reverse=True):
    print(i[0][0], "*di + ", i[0][1], " mod ", M)

