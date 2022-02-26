def insert_sort(array):
    for i in range(1, len(array)):
        current = array[i]
        currentIndex = i

        
array = [54, 26, 93, 17, 77, 31, 44, 55, 20]
# bubbleSort(array)
# select_sort(array)
insert_sort(array)
print(array)