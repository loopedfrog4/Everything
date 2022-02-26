def dp_knapsack(cap,wt,val,n):
    array = [[0] * (cap+1) for i in range(n+1)] 
    
    for i in range(n, -1, -1): # iterate from right to left
        for currentCap in range(0, cap+1): # iterate down the rows from Capacity: 0 to Capacity to 10 (so 11 times total)
            if currentCap < wt[i-1]: # if current capacity of truck is less than currently considered item
                array[i-1][currentCap] = array[i][currentCap] # cannot take item, so take state of the right side
            else: # capacity is bigger than the currently considered item, so take OR don't take
                array[i-1][currentCap] = max(array[i][currentCap], val[i-1] + array[i][currentCap - wt[i-1]])
                #                        ^ don't take the currently considered item so take state at right
                #                                                  ^ take ( currently considered item + the state of right after removing the weight of the currently considered item)
    return array[0][cap]


# capacity = 10
# val = [4,3,10]
# wt = [5,3,5]

capacity = 50
val = [60, 100, 120]
wt = [10, 20, 30]

dp_knapsack(capacity, wt, val, len(val))