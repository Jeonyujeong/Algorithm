t = int(input())
num = [0 for i in range(10001)]

for i in range(2, 10001):
    for j in range(i+i, 10001, i):
        num[j] = 1

for i in range(t):
    n = int(input())

    x = int(n/2)
    y = n-x
    while True:
        if num[x] == 0 and num[y] == 0:
            print(x, y)
            break 
        x = x-1
        y = y+1

            