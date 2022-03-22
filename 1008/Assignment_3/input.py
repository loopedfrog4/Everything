import sys

# array to hold all solutions
arrayAllSolutions = []

# every two subsets 
# i.e everyTwoSubArray[0] holds a pair of possible solution
#     everyTwoSubArray[1] holds another pair of possible solution
#     ... this array variable is populated until all pairs are found
everyTwoSubArray = []

# var to check if all possible solutions are found
allPossibleFound = False

def subsetSum(nums, n, total, checkIfPossibleSubset):
    global allPossibleFound,everyTwoSubArray

    if total == 0:
        return True

    if n < 0 or total < 0:
        return False

    checkIfPossibleSubset.append(nums[n])
    include = subsetSum(nums, n - 1, total - nums[n], checkIfPossibleSubset)


    if include:
        validArray = checkIfPossibleSubset.copy()     
        complimentOfValidArray = nums.copy()
        for x in validArray:
            complimentOfValidArray.remove(x)
        if sorted(validArray) not in arrayAllSolutions:
            tempSubset = [sorted(complimentOfValidArray),sorted(validArray)]
            everyTwoSubArray.append(tempSubset)
            arrayAllSolutions.append(sorted(validArray))
            arrayAllSolutions.append(sorted(complimentOfValidArray))
        allPossibleFound = True


    checkIfPossibleSubset.remove(nums[n])
    exclude = subsetSum(nums, n - 1, total,checkIfPossibleSubset)

    return exclude



def partition(nums):

    total = sum(nums)

    return (total & 1) == 0 and subsetSum(nums, len(nums) - 1, total/2,[])


if __name__ == '__main__':
    arrayAllSolutions = []
    everyTwoSubArray = []
    allPossibleFound = False
    for line in sys.stdin:
        nums = list(line[1:-1].split(","))
    nums = [int(item) for item in nums]
    nums.sort()
    # nums = [1,1,1,2,2,3]
    # nums.sort()
    partition(nums)
    if allPossibleFound:
        print(everyTwoSubArray)
    else:
        print("Cannot find all possible solutions")