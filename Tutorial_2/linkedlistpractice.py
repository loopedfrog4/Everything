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
    def printLinkedList(self):
        temp = self.head
        if temp is None:
            print("Linked List is empty")
        else:
            while temp is not None:
                print(temp.data)
                temp = temp.next

    def delete(self,value):
        prev = None
        next = None
        temp = self.head
        if temp.data is value:
            temp.next = self.head
            del self.head
        while temp is not None and temp.data is not value:
            prev = temp
            temp = temp.next
            next = temp.next
        prev.next = next
        print(f"Deleting {temp}")
        del temp
        
    def deleteAt(self,index):
        prev = None
        next = None
        temp = self.head
        counter = 0
        if index is 0:
            temp.next = self.head
            del self.head
        else:
            while temp is not None and counter < index:
                prev = temp
                temp = temp.next
                next = temp.next
                counter += 1
                if counter is index:
                    prev.next = next
                    print(f"Deleting {temp}")
                    del temp
        

firstList = linkedList()

firstNode = node(42)
secondNode = node(4235)
thirdNode = node(325)
fourthNode = node(864)
fifthNode = node(5463)

firstList.insertAtHead(firstNode)
firstList.insertAtHead(secondNode)
firstList.insertAtHead(thirdNode)
firstList.insertAtHead(fourthNode)
firstList.insertAtHead(fifthNode)
# firstList.delete(325)
firstList.deleteAt(1)
firstList.printLinkedList()
