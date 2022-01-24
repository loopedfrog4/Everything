# Given an array s[0],…,s[n-1] such that n > 1 and s[i] ≤ s[i+1] for all i. 
# Write an algorithm that inserts an input value x into the array so that s[i] ≤ s[i+1] for all i.

array = [1,3,5,7,8,9,11,13,15,16,19,24]

def orderInsert(a,value):
    place_to_insert = 0
    for num_index,num in enumerate(a):
        if num < value: 
            place_to_insert = num_index
    a.insert(place_to_insert+1, value)
    return a
print(orderInsert(array,18))




