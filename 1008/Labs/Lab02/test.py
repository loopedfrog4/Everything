import time

start = time.time()


input().split()
arr_input = [int(x) for x in input().split()]
setA = [int(x) for x in set(input().split())]
setB = [int(x) for x in set(input().split())]

happiness = 0

for ele in arr_input:
    if ele in setA:
        happiness += 1
    if ele in setB:
        happiness -= 1
print(happiness)

end = time.time()
print(end - start)