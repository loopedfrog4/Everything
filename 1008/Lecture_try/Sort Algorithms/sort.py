def merge(a,b):
    c = []
    sizeA = len(a)
    sizeB = len(b)

    indexA = 0
    indexB = 0
    while indexA < sizeA and indexB < sizeB:
        if a[indexA] <= b[indexB]:
            c.append(a[indexA])
            indexA += 1
        else:
            c.append(b[indexB])
            indexB += 1

    for i in range(indexA, sizeA):
        c.append(a[i])
    
    for i in range(indexB, sizeB):
        c.append(b[i])

    return c

def mergeSort(arr):
    n = (int) (len(arr) / 2)

    if n == 1:
        return arr

    firstHalf = arr[0:n]
    secondHalf = arr[n:len(arr)]

    firstHalf = mergeSort(firstHalf)
    secondHalf = mergeSort(secondHalf)
    arr = merge(firstHalf, secondHalf)

    return arr

arr = [4,6,1,7,3,5]
array = [54, 26, 93, 17, 77, 31, 44, 55, 20]
mergeSort(array)
print(array)