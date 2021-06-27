# 단어 뒤집기

t = int(input())

for i in range(t):
    strArr = input().split(' ')

    for str in strArr:
        str = str[::-1]
        print(str, end=' ')
    print()