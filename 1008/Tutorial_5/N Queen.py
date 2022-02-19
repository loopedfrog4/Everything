def isValid(col, row, chessBoard):
  #check if there is another queen that makes the position 
  #check through upper vetical 
  pass

def printSolution(chessBoard):
  print("\n")
  for i in range(len(chessBoard)):
    print(chessBoard[i])

def putAQueen(row, chessBoard):
  N = len(chessBoard)
  for col in range(N):
    if isValid(col, row, chessBoard):
      chessBoard[row][col] = 1
      if (row < N-1):
        putAQueen(row+1, chessBoard)
      else:
        printSolution(chessBoard)
        chessBoard[row][col] = 0
        return
      chessBoard[row][col] = 0

N = 5
chessBoard = []
for i in range(N):
  chessBoard.append([])
  for j in range(N):
    chessBoard[i].append(0)

putAQueen(0, chessBoard)