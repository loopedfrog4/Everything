class node:
    def __init__(self,data):
        self.data = data
        self.next = None
    
class linkedList:
    def __init__(self):
        self.head = None
    def insertAtHead(self,node):
        if self.head is None:
            self.head = node
        else:
            node.next = self.head
            self.head = node
    def printList(self):
        temp = self.head
        while temp is not None:
            print(temp.data)
            temp = temp.next

    def searchByIndex(self,index):
        if self.head is None:
            print("Linked List is empty")
            return
        else:
            counter = 0
            temp = self.head
            while temp is not None and counter < index:
                temp = temp.next
                counter += 1
            if temp is None:
                print("Invalid Index")
            else:
                return temp
    def delete(self,value):
        prev = None
        next = None
        temp = self.head
        if temp.data == value:
            self.head = temp.next
            del temp
            return
        if temp is None:
            print("Linked list is empty")
            return
        while temp is not None and temp.data != value:
            prev = temp
            temp = temp.next
        prev.next = temp.next
        del temp
                
    def deleteAt(self,index):
        prev = None
        next = None
        temp = self.head
        counter = 0
        if index == 0:
            self.head = temp.next
            del temp
            return
        if temp is None:
            print("Linked list is empty")
            return
        while temp != None and counter < index:
            prev = temp
            temp = temp.next
            counter += 1
        prev.next = temp.next
        tempReturn = temp
        del temp
        return tempReturn

    def size(self):
        counter = 0
        temp = self.head
        if temp == None:
            return counter
        else:
            while temp != None:
                temp = temp.next
                counter += 1
            return counter

class myQueue:
    def __init__(self):
        self.queue = linkedList()
    
    def enqueue(self, value):
        self.queue.insertAtHead(value)
    
    def printQueue(self):
        self.queue.printList()

    def dequeue(self):
        self.queue.deleteAt(self.queue.size() - 1)

    def peek(self):
        return self.queue.searchByIndex(self.queue.size() - 1)

firstList = linkedList()

firstNode = node(1)
secondNode = node(2)
thirdNode = node(3)
fourthNode = node(4)
fifthNode = node(5)

# firstList.insertAtHead(firstNode)
# firstList.insertAtHead(secondNode)
# firstList.insertAtHead(thirdNode)
# firstList.insertAtHead(fourthNode)
# firstList.insertAtHead(fifthNode)
# firstList.printList()

queue = myQueue()
queue.enqueue(firstNode)
queue.enqueue(secondNode)
queue.enqueue(thirdNode)
queue.enqueue(fourthNode)
queue.enqueue(fifthNode)
queue.dequeue()
print(queue.peek().data)
queue.printQueue()