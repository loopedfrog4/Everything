# hash table opening addressing with linear probing
class HashTable:
    def __init__(self):
        self.Max = 5
        self.arr = [None for i in range(self.Max)]

    def get_hash(self,key):
        hash = 0
        for ch in key:
            val = ord(ch)
            hash += val
        return hash % self.Max

    def set_item(self,key,value):
        tableFull = False
        if tableFull == True:
            return
        index = self.get_hash(key)
        i = index
        traversedListCounter = 0
        if self.arr[index] == None:
            self.arr[index] = (key,value)
        else:
            while self.arr[i] != None:
                i += 1
                traversedListCounter += 1
                if traversedListCounter == self.Max:
                    tableFull = True
                    return
                if i == self.Max:
                    i = 0
                
            self.arr[i] = (key,value)

            
        
    def get_item(self,key,value):
        index = self.get_hash(key)
        
        
    
 
table = HashTable()
table.set_item("Ada", "March 7")
table.set_item("Ada", "March 23")
table.set_item("Ada", "March 5")
table.set_item("Ada", "March 7")
table.set_item("Ada", "March 9")
table.set_item("Ted", "March 11")
table.set_item("Ada", "March 12")
table.set_item("Ada", "March 9")
table.set_item("Ted", "March 11")
table.set_item("Ada", "March 12")
x = 1