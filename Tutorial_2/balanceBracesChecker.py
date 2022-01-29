from numpy import char


class Stack:
    def __init__(self):
        self.top = -1
        self.data = []

    def isEmpty(self):
        if self.top == -1:
            return True
        else:
            return False

    def push(self, value):
        self.top += 1
        self.data.append(value)
    def pop(self):
        if self.isEmpty():
            return
        else:
            top_element = self.data[self.top]
            self.top -= 1
            return top_element
    
    def peek(self):
        if self.isEmpty():
            return
        else:
            return self.data[self.top]


input = "print(f\"Hello, {self.queue.deleteAt(self.queue.size() - 1)}\")"
# input = "()()))"
# input = "((()))"

def checkForBalance(input):
    stack = Stack()
    opening_braces = ['(', '{', '[']
    closing_braces = [')', '}', ']']

    for character in input:
        pos = input.index(character)
        if character in opening_braces:
            stack.push(character)
        elif stack.top != 1 and 

    
print(checkForBalance(input))




