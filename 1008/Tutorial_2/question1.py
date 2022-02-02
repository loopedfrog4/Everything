class Stack:
    def __init__(self):
        self.top = -1
        self.data = []
    def push(self, value):
        self.data.append(0)
        self.top += 1
        self.data[self.top] = value
    def pop(self):
        value = self.data[self.top]
        del self.data[self.top]
        self.top -= 1
        return value
    def isEmpty(self):
        return (self.top == -1)
    def peek(self):
        return self.data[self.top]
    def printStack(self):
        print(self.data)
    def invert(self):
        for num in range(0, round(len(self.data) / 2)):
            tempFront = self.data[num]
            tempBack = self.data[-(num+1)]
            self.data[num] = tempBack
            self.data[-(num+1)] = tempFront

stack1 = Stack()
stack1.push(10)
stack1.push(23)
stack1.push(56)
stack1.printStack()
stack1.invert()
stack1.printStack()
