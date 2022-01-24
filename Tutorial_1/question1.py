# Write an algorithm that returns the index of the first occurrence of the largest element in an array s[0],…,s[n-1].
array = [3,2,1,5,3,2,1,5]

def findLargestIndex(a):
  largest = array[0]
  largest_index = 0
  for num in array:
    if largest < num:
      largest = num
      largest_index = array.index(num)
    
  return largest_index

print(findLargestIndex(array))