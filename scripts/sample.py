import os

class Tensor:
    def __init__(self, val, children=[], op=None):
        self.val = val
        self.grad = 0
        self.children = children
        self.op = op

    def __repr__(self):
        return f"Val:{self.val} -- Grad:{self.grad}"

    def __add__(self, other):
        return Tensor(self.val + other.val, [self, other], op="add")
    
    def __mul__(self, other):
        return Tensor(self.val * other.val, [self, other], op="mul")
    
    def __sub__(self, other):
        return Tensor(self.val - other.val, [self, other], op="sub")

    
    def backward(self):
        if self.op == "add":
            self.children[0].grad += self.grad
            self.children[1].grad += self.grad
        if self.op == "mul":
            a, b = self.children[0].val, self.children[1].val
            self.children[0].grad += (b*self.grad)
            self.children[1].grad += (a*self.grad)
        if self.op == "sub":
            self.children[0].grad += self.grad
            self.children[1].grad -= self.grad
        for child in self.children:
            child.backward()
        return self.grad
    
    def zero_grad(self):
        self.grad = 0
        for child in self.children:
            child.zero_grad()


a = Tensor(1)
b = Tensor(2)

c = a + b
e = Tensor(4)

d = c * e
d.grad = 1

d.backward()

print(a, b, e)

for i in range(10):
    d.zero_grad()
    d.grad = 1
    d.backward()
    #print(a, b, e)
    a.val -= a.grad * 0.01
    b.val -= b.grad * 0.01
    e.val -= e.grad * 0.01
    print((a.val + b.val) * e.val)