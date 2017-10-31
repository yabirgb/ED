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

    def __eq__(self,obj):
        return self.val == obj.val
    
    def recreate(self):
        if(self.gen > 0):
            self.p1.recreate()
            self.p2.recreate()
            print(self.op[3].format(self.p1.val,self.p2.val), "=", self.val)

    
a = [Node(3), Node(4), Node(5, Node(3), Node(4), "p", 1)]

b = Node(5, Node(3), Node(4), "sum",2)

print(b in a)
