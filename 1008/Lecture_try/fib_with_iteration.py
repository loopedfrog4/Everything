


def fibIteration(n):
    if n == 2: return 2
    if n == 1: return 1
    if n == 0: return 1
    if n > 2:
        count = 0
        m = 0
        m1 = 1
        while count < n:
            nth = m + m1
            m = m1
            m1 = nth
            count += 1
        return count
print(fibIteration(3))