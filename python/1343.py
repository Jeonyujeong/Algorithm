board = input()

cnt = 0
for i in range(len(board)):
    if board[i] == 'X':
        cnt = cnt + 1
    else:
        if cnt%2 == 0:
            while cnt >= 4:
                board = board.replace("XXXX", "AAAA", 1)
                cnt = cnt - 4
            while cnt > 0:
                board = board.replace("XX", "BB", 1)
                cnt = cnt - 2
        else:
            print(-1)
            exit()
        cnt = 0

if cnt%2 == 0:
    while cnt >= 4:
        board = board.replace("XXXX", "AAAA", 1)
        cnt = cnt - 4
    while cnt > 0:
        board = board.replace("XX", "BB", 1)
        cnt = cnt - 2
else:
    print(-1)
    exit()

print(board)