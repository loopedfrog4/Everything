# Question 2 Attempted in Tablet


# Question 3
from email import header


class Queue:
    def __init__(self):
        self.rear = -1
        self.data = []
    def enqueue(self,value):
        self.data.append(0)
        self.rear += 1
        self.data[self.rear] = value
    def isEmpty(self):
        return (self.rear == -1)
    def dequeue(self):
        if (self.rear == -1):
            print("Operation Failed, Queue is empty")
        else:
            value = self.data[0]
            del self.data[0]
            self.rear -= 1
            return value
    def printQueue(self):
        print(self.data)
    def peek(self):
        return self.data[0]
    

class SinglyListNode:
    def __init__(self, data):
        self.data = data
        self.next= None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
    
    def search(self,value):
        temp = self.head
        while temp is not None:
            if temp.data is value:
                return temp
            temp = temp.next
        print(f"Search Error: {value} cannot be found")

    def insertAtHead(self, node):
        if self.head is None:
            self.head = node
        else:
            node.next = self.head
            self.head = node

    def deleteAtHead(self):
        temp = self.head
        self.head = self.head.next
        del temp

    def delete(self, value):
        prev = None
        temp = self.head
        while temp is not None:
            # Keeping track of previous node
            # In current iteration, value is not yet found
            if temp.data is not value:
                prev = temp
                temp = temp.next

            # Value is found
            else:
                if temp is self.head:
                    self.deleteAtHead()
                else:
                    prev.next = temp.next
                    del temp
                return
        print(f"Value: {value} cannot be found")


    def printList(self):
        print("Printing List...")
        temp = self.head
        while temp is not None:
            print(f"Data: {temp.data}")
            temp = temp.next
list1 = SinglyLinkedList()

node1 = SinglyListNode(1)
node2 = SinglyListNode(55)
node3 = SinglyListNode(444)
node4 = SinglyListNode(22)
node5 = SinglyListNode(33)

list1.insertAtHead(node1)
list1.insertAtHead(node2)
list1.insertAtHead(node3)
list1.insertAtHead(node4)
list1.insertAtHead(node5)
list1.delete(33)
list1.printList()



print("===Queue===")
queue1 = Queue()
queue1.enqueue(3)
queue1.enqueue(121)
queue1.enqueue(236)
queue1.printQueue()
queue1.dequeue()
queue1.printQueue()
print(queue1.isEmpty())
print(queue1.peek())
