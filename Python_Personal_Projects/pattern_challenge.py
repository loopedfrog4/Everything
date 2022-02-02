# Inverted Half Star Pyramid
def printInvertedHalfStarPyramid(n):
    for x in range(n,0,-1):
        for y in range(x,0,-1):
            print(" x", end="")
        print()
    print()

def printFullDiamond(n):
    # number of spaces
    k = n - 1
 
    # outer loop to handle number of rows
    for i in range(0, n):
     
        # inner loop to handle number spaces
        # values changing acc. to requirement
        for j in range(0, k):
            print(end=" ")
     
        # decrementing k after each loop
        k = k - 1
     
        # inner loop to handle number of columns
        # values changing acc. to outer loop
        for j in range(0, i+1):
         
            # printing stars
            print("* ", end="")
     
        # ending line after each row
        print("\r")


printInvertedHalfStarPyramid(20)
printFullDiamond(10)