# An algorithm for finding the maximum element of an array is in the following
def arrayMax(a,n):
    currentMax = a[0]
    for i in range(1,n):
        if a[i] > currentMax:
            currentMax = a[i]
    return currentMax


array = [3,2,11,8,1,33,25,100,5]
print(arrayMax(array,8))

#   Determine the number of times that the statement “currentMax = a[i]” will be executed in the best case and in the worst case.
# Best case: 0 times (first element in largest)
# Worst case: n - 1 times (n-1th element in array is the largest)