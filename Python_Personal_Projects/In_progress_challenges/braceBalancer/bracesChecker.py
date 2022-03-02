import os

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
            del self.data[self.top]
            return top_element
    
    def peek(self):
        if self.isEmpty():
            return
        else:
            return self.data[self.top]



input = "print(f\"Hello, {self.queue.deleteAt(self.queue.size() - 1)}\")"
# input = "()()))"
# input = "((()))"
# input = "return self.queue.searchByIndex(self.queue.size() - 1)"
# input = "())"
# input = "(())"
# input = input("Enter Expression: ")

def braceBalanceCheck(input):
    stack = Stack()
    opening_braces = ['(', '{', '[']
    closing_braces = [')', '}', ']']

    for character in input:
        if character in opening_braces:
            stack.push(character)
        elif character in closing_braces:
            pos = closing_braces.index(character)
            if stack.top != -1 and opening_braces[pos] == stack.peek():
                stack.pop()
            else:
                return "Unbalanced"
    if stack.isEmpty():
        return "Balanced"
    else:
        return "Unbalanced"
        

print(braceBalanceCheck(input))