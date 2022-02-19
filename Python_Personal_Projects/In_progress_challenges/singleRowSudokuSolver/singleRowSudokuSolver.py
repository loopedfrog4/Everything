# Functions returns all possible solutions given one incomplete row
def solveOneRow(incompleteRow):
    completedRow = incompleteRow
    possibleNumbers = [1,2,3,4,5,6,7,8,9]

    # Loop through entire row, remove existing value from possible pool of numbers
    for i in range(0,10):
        ele = 0
        if completedRow[i] in possibleNumbers:
            possibleNumbers.remove(completedRow[i])
            ele = possibleNumbers[i]
            continue
        
    return completedRow
    

row = [5,3,0,0,7,0,0,0,0]
print(solveOneRow(row))