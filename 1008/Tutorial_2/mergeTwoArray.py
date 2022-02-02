from cv2 import merge


array1 = [3, 6, 6, 10, 45, 45, 50]
array2 = [2, 3, 55, 60, 76, 333, 1111]

def mergeListHelper(list1, list2):
    array3 = []
    for index in range(0, len(list1)):
        if index >= len(list2):
            array3.append(list1[index])
        else:
            if list1[index] > list2[index]:
                array3.append(list2[index])
                array3.append(list1[index])
            else:
                array3.append(list1[index])
                array3.append(list2[index])
    return array3

def mergeList(list1,list2):
    if len(list1) > len(list2):
        return mergeListHelper(list1,list2)

    else:
        return mergeListHelper(list2,list1)
        
    
print(mergeList(array1,array2))
    