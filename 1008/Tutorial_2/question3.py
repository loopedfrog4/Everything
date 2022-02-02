# Question 2 Attempted in Tablet


# Question 3

class SinglyListNode:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
    #return the value of the node at index

    def search(self, index):
        temp = self.head
        prev = None
        counter = 0
        while temp is not None and counter < index:
            prev = temp
            temp = temp.next
            counter += 1

        if temp is None:
            print ('search error: invalid index')
        else:
            return temp

    def insertAtHead(self, node):
        if self.head is None:
            self.head = node
        else:
            node.next = self.head
            self.head = node

    def delete(self, value):
        prev = None
        temp = self.head

        while temp != None and temp.data != value:
            prev = temp
            temp = temp.next

        #node to be deleted is head
        if temp == self.head:
            self.deleteAtHead()

        #Value found
        elif temp != None:
            prev.next = temp.next
            del temp
        #Value not found
        else:
            print('Value ', value, ' cannot be found')

    #delete the node at index
    def deleteAt(self,index):
        temp = self.head
        prev = None
        counter = 0
        while temp is not None and counter < index:
            prev = temp
            temp = temp.next
            counter += 1

        if temp is None:
            print ('search error: invalid index')
        else:
            if prev is None:
                self.head = temp.next
            else:
                prev.next = temp.next
            del temp

    def deleteAtHead(self):
        temp = self.head
        self.head = self.head.next
        del temp

    def printList(self):
        print("Current list content:")
        temp = self.head
        while temp is not None:
            print (temp.data, end=" ")
            temp = temp.next
        print()

    #return the number of elements in the queue
    def size(self):
        temp = self.head
        size = 0
        while temp is not None:
            size += 1
            temp = temp.next
        return size


class MyQueue:
    def __init__ (self):
        self.q = SinglyLinkedList()

    def enqueue(self, value):
        self.q.insertAtHead(value)

    def printQueue(self):
        self.q.printList()

    def dequeue(self):
        value = self.q.search(self.q.size() - 1)
        self.q.deleteAt(self.q.size() - 1)
        return value

    def peek(self):
        last = self.q.size() - 1
        return self.q.search(last).data

queue = MyQueue()
node1 = SinglyListNode(10)
node2 = SinglyListNode(3)
node3= SinglyListNode(55)
node4= SinglyListNode(27)
queue.enqueue(node1)
queue.enqueue(node2)
queue.enqueue(node3)
queue.enqueue(node4)
queue.dequeue()
print(queue.peek())
queue.printQueue()
