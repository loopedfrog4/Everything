import numpy as np

def naive_knapsack(cap,wt,val,n):
    density = np.array(val) / np.array(wt)
    
    t_sort = np.argsort(density)[::-1]
    density = np.array(density)[t_sort]
    wt = np.array(wt)[t_sort]
    val = np.array(val)[t_sort]
    
    return_val = 0
    index = 0

    while cap > 0: #while there's space to add items
        if cap >= wt[index]: #if the current(and the whole of) item in the space can considered to add into the truck
            cap -= wt[index]
            return_val += val[index]
        else: # means the full item cannot fit into the truck, so must take fractional
            return_val += cap * density[index]
            cap = 0
        index += 1 # go to next item in list
    return return_val

val = [4,3,10]
wt = [5,3,5]
# density = [0.8, 1, 2]
capacity = 10
naive_knapsack(capacity, wt, val, len(wt))