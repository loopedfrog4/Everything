def blocks(n):
    if (n <= 1):
        print(1)
    else:
        return blocks(n - 1)

blocks(5)
