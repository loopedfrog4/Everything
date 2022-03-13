subsets = [[],[]]

def subsetSum(nums, n, total):
    if total == 0:
        
        return True

    if n < 0 or total < 0:
        return False

    include = subsetSum(nums, n - 1, total - nums[n])
    
    if include:
        subsets[0].append(nums[n])
        return True

    exclude = subsetSum(nums, n - 1, total)
    return exclude

def partition(nums):

    total = sum(nums)
    return (total & 1) == 0 and subsetSum(nums, len(nums) - 1, total / 2)

# nums = [7, 3, 1, 5, 4, 8]
nums = [1,1,1,2,2,3]
# nums = [1,5,4,2]
# nums = [1,5,4,2,3,3,6,0]

if partition(nums):
    subsets[1] = [item for item in nums if item not in subsets[0]]
    print(f"Subset 1: {subsets[0]}\nSubset 2: {subsets[1]}")
else:
    print("Set cannot")






# subsets = [[],[]]

# def subsetSum(nums, n, total):
#     if total == 0:
        
#         return True

#     if n < 0 or total < 0:
#         return False

#     include = subsetSum(nums, n - 1, total - nums[n])
    
#     if include:
#         subsets[0].append(nums[n])
#         return True
    
#     exclude = subsetSum(nums, n - 1, total)
#     return exclude

# def partition(nums):

#     total = sum(nums)
#     return (total & 1) == 0 and subsetSum(nums, len(nums) - 1, total / 2)

# # nums = [7, 3, 1, 5, 4, 8]
# # nums = [3,4,2,1]
# # nums = [1,4,6,3]
# # nums = [1,5,4,2,3,3,6,0]
# nums = [1,1,1,2,2,3]

# if partition(nums):
#     print(f"Subset 1: {subsets[0]}\nSubset 2: {subsets[1]}")
# else:
#     print("Set cannot")

