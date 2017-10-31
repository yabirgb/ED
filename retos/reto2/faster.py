import sys

from itertools import combinations
from collections import defaultdict
import operator


class Node(object):
    """
    Representation of a computed value result of operate 2 previous elements
    """

    def __init__(self, value, previous1=None, previous2=None, op=None, gen=0):
        self.p1 = previous1
        self.p2 = previous2
        self.op = op
        self.val = value       
        self.gen = gen

    #Reprs as string of the class
    def __str__(self):
        return str(self.val)

    def __repr__(self):
        return str(self.val)

    #Comparator of the class
    def __eq__(self,obj):
        return self.val == obj.val

    #Create hash of class. Used when cheching for magic chains
    def __hash__(self):
        return hash(self.val)

    #Follow the branch to recreate the operations required
    def recreate(self):
        if(self.gen > 0):
            #Recreate the parents first
            self.p1.recreate()
            self.p2.recreate()
            #Print the operation with parents to obtain this node value
            print(self.op[3].format(self.p1.val,self.p2.val), "=", self.val)

    
#Now we define the set op operations following the sintax:
#(operation, conmutative, restriction(optional), repr )
operations = [(operator.add, False, lambda x,y: True, "{}+{}"),
              (operator.sub, True, lambda x,y: x > y, "{}-{}"),
              (operator.mul, False, lambda x,y: True, "{}*{}"),
              (operator.truediv, True, lambda x,y: x%y == 0, "{}/{}")]


def evolve(lst, gen):
    # we assume that the Node values are unique

    #When we got just one element we have finished
    if (len(lst) == 1):
        return lst

    #We will operate with pairs since all our operations are binary
    p = combinations(lst, 2)

    #The output of compute the parent nodes will be stores in news
    news = []
    
    for pair in list(p):
        #Rewrite the list of elems. For each pair we remove the pair
        #and insert the new elements.
        newList = list(lst)
        newList.remove(pair[0])
        newList.remove(pair[1])

        #At this point newList is unique for each pair

        #Fore each opearation we create a new node
        for operation in operations:
            aux = list(newList)
            #We chech if the pair satisfies the conditions of the operator
            if operation[2](pair[0].val, pair[1].val):
                n = Node( operation[0](pair[0].val, pair[1].val), pair[0], pair[1], operation, gen)
                aux.append(n)
                news.append(aux)

            else:
                pairN = (pair[1], pair[0])
                #Since combinations doesn't count permutation in position we swap the components
                if operation[2](pairN[0].val, pairN[1].val):
                    n = Node( operation[0](pairN[0].val, pairN[1].val), pairN[0], pairN[1], operation, gen)
                    aux.append(n)
                    news.append(aux)

    return news

def evolution(origin):

    #We create the first generation
    genesis = evolve(origin, 1)
    print("Working!")

    #And repeat the process until complete.
    for i in range(2, 7):
        next2= []
        for block in genesis:
            for k in evolve(block,i):
                    next2.append(k)
        genesis = next2

    return genesis

def compose(n, base):
    l = evolution(base)
    #Chech for the Nodes with the desired value
    genes = list(filter(lambda x: x.val == n, l))
    if(genes):
        genes[0].recreate()
    else:
        print("No hay solución")

def is_magic(base):
    groups = defaultdict(list)
    print("Generated full list")
    #We create a hash table with unique keys. As we perform multiple
    #queries this increments the speed.
    for obj in evolution(base):
        groups[obj.val].append(obj)

    for i in  range(100,1000):
        if i not in groups.keys():
            return False

        #print("Se puede generar ", i, "✔")
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
