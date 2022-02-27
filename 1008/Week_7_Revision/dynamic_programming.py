import numpy as np

# 0/1 knapsack
def dp_knapsack(c, wt, val, n):
    array = [[0] * (c + 1) for i in range(n+1)]
    
    for i in range(n,-1,-1):
        for currentcap in range(c+1):
            if currentcap < wt[i-1]:
                array[i-1][currentcap] = array[i][currentcap]
            else:
                array[i-1][currentcap] = max(array[i][currentcap], val[i-1] + array[i][currentcap - wt[i-1]])
    return array[0][c]

def naive_knapsack(c,wt,val,n):
    density = np.array(val) / np.array(wt)
    
    t_sort = np.argsort(density)[::-1]
    density = np.array(density)[t_sort]
    wt = np.array(wt)[t_sort]
    val = np.array(val)[t_sort]
    
    return_val = 0
    index = 0

    while c > 0:
        if c >= wt[index]: #if the current(and the whole of) item in the space can considered to add into the truck
            c -= wt[index]
            return_val += val[index]
        else:
            return_val += c * density[index]
            c = 0
        index += 1
    return return_val
    
# capacity = 50
# val = [60, 100, 120]
# wt = [10, 20, 30]

capacity = 10
val = [4,3,10]
wt = [5,3,5]

# print(dp_knapsack(capacity, wt, val, len(wt)))
print(naive_knapsack(capacity,wt,val,len(wt)))