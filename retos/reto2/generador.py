import sys

from itertools import combinations
from functools import reduce
import operator


class Node(object):

    def __init__(self, value, previous1=None, previous2=None, op=None, gen=0):
        self.p1 = previous1
        self.p2 = previous2
        self.op = op
        self.val = value       
        self.gen = gen

    def __str__(self):
        return str(self.val)


    def __repr__(self):
        return str(self.val)

    def recreate(self):
        if(self.gen > 0):
            self.p1.recreate()
            self.p2.recreate()
            print(self.op[3].format(self.p1.val,self.p2.val), "=", self.val)

    
        

#n = [6,8,10,9,4,75]
base = [Node(value=1),Node(8), Node(10), Node(9), Node(4), Node(75)]

max = 999


#(operation, conmutative, restriction(optional), repr )
operations = [(operator.add, False, lambda x,y: True, "{}+{}"),
              (operator.sub, False, lambda x,y: x > y, "{}-{}"),
              (operator.mul, True, lambda x,y: True, "{}*{}"),
              (operator.truediv, True, lambda x,y: x%y == 0, "{}/{}")]


def evolve(lst, gen):
    # we assume that the Node values are unique

    if (len(lst) == 1):
        return lst
    
    p = combinations(lst, 2)

    
    news = []
    for pair in list(p):
        #Rewrite the list of elems
        newList = list(lst)
        newList.remove(pair[0])
        newList.remove(pair[1])

        results = []
    
        for operation in operations:
            if operation[2](pair[0].val, pair[1].val):
                n = Node( operation[0](pair[0].val, pair[1].val), pair[0], pair[1], operation, gen)
                results.append(n)
            else:
                pairN = (pair[1], pair[0])
                if operation[2](pairN[0].val, pairN[1].val):
                    n = Node( operation[0](pairN[0].val, pairN[1].val), pairN[0], pairN[1], operation, gen)
                    results.append(n)
   

        for k in results:
            fake = list(newList)
            fake.append(k)
            news.append(fake)

    return news

def evolution(origin):

    genesis = evolve(origin, 1)
    print("Working! YEAH BOIIIIIIII!")

    for i in range(2, 7):
        #print("LON: ", i)
        #print(genesis)
        next = []
        for block in genesis:
            for k in evolve(block,i):
                next.append(k)
        genesis = next

    return genesis

def compose(n, base):
    l = evolution(base)
    genes = list(filter(lambda x: x.val == n, l))
    if(genes):
        genes[0].recreate()
    else:
        print("No hay solución")

def is_magic(base):
    l = evolution(base)
    print("Generated full list")
    for i in  range(100,1000):
        if not list(filter(lambda x: x.val == i, l)):
            return False

        print("Se puede generar ", i, "✔")
    return True
            
    
#Manage from console
if __name__ == "__main__":

    if(len(sys.argv) == 1):
        print("Número de argumentos erroneo")
    
    elif sys.argv[1] == "compose" and len(sys.argv) == 3:
        compose(int(sys.argv[2]), base)

    elif sys.argv[1] == "is-magic"  and len(sys.argv) == 8:
        newBase = []
        for i in range(len(sys.argv) - 2):
            newBase.append(Node(int(sys.argv[i+2])))

        if is_magic(newBase):
            print("Es una cadena mágica")
        else:
            print("No es una cadena mágica")

    elif sys.argv[1] == "compose" and len(sys.argv) == 9:
        newBase = []
        for i in range(len(sys.argv) - 3):
            newBase.append(Node(int(sys.argv[i+3])))

        compose(int(sys.argv[2]), newBase)
        
    else:
        print("No se reconoció el número de argumentos")
