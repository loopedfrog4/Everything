# Write an algorithm that reverses the array s[0],…,s[n-1].
array = [10,9,8,7,6,5,4,3,2,1]

def reverse(a):
  for num_index,num in enumerate(a[::-1]):
    array[num_index] = num
    
  return (a)

reverse(array)
print(array)