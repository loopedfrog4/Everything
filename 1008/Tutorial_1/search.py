
import time

array = [11,13,1,3,45,7,899,90,10,14,125,6,19,24]

def half_search(array,value_to_search):
    start = time.time()

    sorted_array = sorted(array)
    print(sorted_array)


    end = time.time()
    print(f"Time taken: {end - start}")
    

half_search(array,899)
