def printBitString(n, w):
    if n == 0:
        print(w)
    else:
        printBitString(n-1, w+"0")
        printBitString(n-1, w+"1")

printBitString(4,"")