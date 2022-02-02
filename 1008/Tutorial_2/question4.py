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

    def mergeList(s1, s2):
        

s1 = SinglyLinkedList()
s2 = SinglyLinkedList()
n1 = SinglyListNode(3)
n2 = SinglyListNode(6)
n3 = SinglyListNode(6)
n4 = SinglyListNode(10)
n5 = SinglyListNode(45)
n6 = SinglyListNode(45)
n7 = SinglyListNode(50)
n8 = SinglyListNode(2)
n9 = SinglyListNode(3)
n10 = SinglyListNode(55)
n11 = SinglyListNode(60)
s1.insertAtHead(n7)
s1.insertAtHead(n6)
s1.insertAtHead(n5)
s1.insertAtHead(n4)
s1.insertAtHead(n3)
s1.insertAtHead(n2)
s1.insertAtHead(n1)
s2.insertAtHead(n11)
s2.insertAtHead(n10)
s2.insertAtHead(n9)
s2.insertAtHead(n8)
s1.printList()
s2.printList()

# s3 = mergeList(s1,s2)
# s3.printList()