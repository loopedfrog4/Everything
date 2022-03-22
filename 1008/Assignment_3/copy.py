import sys

def subsetSum(nums, n, total,testArray):
    global answerArray,isFound,setArray

    if total == 0:
        return True


    if n < 0 or total < 0:
        return False


    testArray.append(nums[n])
    include = subsetSum(nums, n - 1, total - nums[n],testArray)


    if include:
        validArray = testArray.copy()     
        complimentArray = nums.copy()
        for x in validArray:
            complimentArray.remove(x)
        if sorted(validArray) not in allArray:
            tempSet = [sorted(complimentArray) ,sorted(validArray)]
            setArray.append(tempSet)
            allArray.append(sorted(validArray))
            allArray.append(sorted(complimentArray))
        isFound = True


    testArray.remove(nums[n])
    exclude = subsetSum(nums, n - 1, total,testArray)

    return exclude



def partition(nums):

    total = sum(nums)
    total = round(total,1)

    return (total*10) % 2 == 0 and subsetSum(nums, len(nums) - 1, total/2,[])


if __name__ == '__main__':
    allArray = []
    setArray = []
    isFound = False
    for line in sys.stdin:
        nums = list(line[1:-1].split(","))
    nums = [int(item) for item in nums]
    nums.sort()
    partition(nums)
    if isFound:
        print(setArray)
    else:
        print("NA")