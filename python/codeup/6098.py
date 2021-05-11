n = 10
board = [list(map(int, input().split())) for _ in range(n)]

y = 1
x = 1
board[y][x] = 9
while True:
    if x+1 < 10 and board[y][x+1] == 0:
        board[y][x+1] = 9
        x = x+1
    elif y+1 < 10 and board[y+1][x] == 0:
        board[y+1][x] = 9
        y = y+1
    elif x+1 < 10 and board[y][x+1] == 2:
        board[y][x+1] = 9
        break
    elif y+1 < 10 and board[y+1][x] == 2:
        board[y+1][x] = 9
        break
    else:
        break

for i in range(10):
    for j in range(10):
        print(board[i][j], end=' ')
    print("\n", end='')
    