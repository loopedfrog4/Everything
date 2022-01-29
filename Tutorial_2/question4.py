class SinglyListNode:
    def __init__(self, data):
        self.data = data
        self.next= None

class SinglyLinkedlist:
    pass

def mergeList(s1, s2):
  #todo
  pass

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
n9 = SinglyListNode(35)
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

s3 = mergeList(s1,s2)
s3.printList()