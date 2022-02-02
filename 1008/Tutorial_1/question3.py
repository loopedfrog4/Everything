# Write an algorithm that output the largest and the second largest values in the array s[0],…s[n-1]. Assume that n>1 and the values in the array are distinct.
array = [433,22,130,6,111,222,4,7,5,3,1,17,16,55,2]
def find2Largest(a):
  largest = 0
  second_largest = 0
  
  for num in array:
    if num > largest:
      second_largest = largest
      largest = num
      
    if num >= second_largest and num < largest:
      second_largest = num
  print(f"largest is {largest}")
  print(f"second largest is {second_largest}")
  return largest, second_largest


print(find2Largest(array))