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

    def __truediv__(self, other):
        return Tensor(self.val / other.val, [self, other], op="div")
 
    def backward(self, head=True):
        if head:
            self.grad = 1
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
        if self.op == "div":
            a, b = self.children[0].val, self.children[1].val
            self.children[0].grad += (1/b*self.grad)
            self.children[1].grad += (-a/(b**2)*self.grad)
        for child in self.children:
            child.backward(head=False)
        return self.grad
    
    def zero_grad(self):
        self.grad = 0
        for child in self.children:
            child.zero_grad()
    
    def update(self, lr=0.01):
        self.val -= self.grad * lr
        for child in self.children:
            child.update(lr=lr)

    def forward(self):
        if len(self.children) == 0:
            return self.val
        if self.op == "add":
            return self.children[0].forward() + self.children[1].forward()
        if self.op == "mul":
            return self.children[0].forward() * self.children[1].forward()
        if self.op == "sub":
            return self.children[0].forward() - self.children[1].forward()
        if self.op == "div":
            return self.children[0].forward() / self.children[1].forward()
        raise AssertionError("Invalid operation")

a = Tensor(1)
b = Tensor(2)

c = a + b
e = Tensor(4)

d = c * e
f = Tensor(5)
g = d / f

for i in range(10):
    g.zero_grad()
    g.backward()
    g.update()
    #print(a, b, e)
    print(g.forward())
    print(f.val)
#    print((a.val + b.val) * e.val)