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
            print(self.p1.val,self.op[3],self.p2.val,"=", self.val)

    
        

#n = [6,8,10,9,4,75]
n = [Node(value=6),Node(8), Node(10), Node(9), Node(4), Node(75)]

max = 999


#(operation, conmutative, restriction(optional), repr )
operations = [(operator.add, False, lambda x,y: x+y < max, "+"), (operator.sub, True, lambda x,y: x > y, "-"),
              (operator.mul, False, lambda x,y: x*y < max, "*"), (operator.truediv, True, lambda x,y: x%y == 0, "/")]


def evolve(lst, gen):

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

def evolution(lst):

    genesis = evolve(n, 1)
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

def compose(n):
    genes = list(filter(lambda x: x.val == n, evolution(n)))
    if(genes):
        genes[0].recreate()
    else:
        print("No hay solución")
    

compose(0)
