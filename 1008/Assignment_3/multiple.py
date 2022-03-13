from collections import defaultdict
def best_full_partition(nums) -> int:
    """Given a list of integers (positive or negative) 'nums',
    return the maximum number of disjoint equal sum subarrays we can
    partition nums into (using all elements)"""

    total = sum(nums)

    # Special case where total sum is 0
    if total == 0:
        # Count the number of times 0 is a partial sum
        answer = 0
        current_sum = 0
        for x in nums:
            current_sum += x
            if current_sum == 0:
                answer += 1
        return answer

    best_found = 1

    # Prefix sums we're trying to find; all share common factor with total
    looking_for = set()

    """ Map from prefix sums to the common factor/original prefix sum.
        There may be several: e.g. total/6 and total/3 may be targets
        of 2*total/3. """
    looking_to_original_sums = defaultdict(set)

    current_sum = 0

    for x in nums:
        current_sum += x
        if current_sum == 0:
            continue

        if current_sum in looking_for:
            for original_sum in looking_to_original_sums[current_sum]:
                new_target = current_sum + original_sum

                # If we've found all matches in this chain
                if new_target == total:
                    best_found = max(best_found, total // original_sum)
                    continue

                looking_for.add(new_target)
                looking_to_original_sums[new_target].add(original_sum)

            looking_to_original_sums.pop(current_sum)
            looking_for.discard(current_sum)

        # Check if current sum is a divisor of full array sum
        if total % current_sum == 0:
            # If this splits array in half by sum, we've reached its end
            if 2 * current_sum == total:
                best_found = max(best_found, 2)
            else:
                # Add the next multiple of this sum to our search set
                looking_for.add(2 * current_sum)
                looking_to_original_sums[2 * current_sum].add(current_sum)

    return best_found


nums = [1,1,1,2,2,3]
print(best_full_partition(nums))