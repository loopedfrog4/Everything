# Q5
def hash_function(x,list):
    return x % 13
list = [8,2,7,20,33,15,19,34,12,21]

for i in range(len(list)):
    print(hash_function(list[i],list))