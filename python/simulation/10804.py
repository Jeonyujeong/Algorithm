'''
arr = [i for i in range(0,21)]

for i in range(0,10):
    str = input().split(' ')
    a = int(str[0])
    b = int(str[1])
    
    arrReverse = arr[b:a-1:-1]
    for j in range(0,len(arrReverse)):
        arr[a+j] = arrReverse[j]
    
for i in arr[1:]:
    print(i, end=' ')
'''

str = input().split(' ')
n = int(str[0])
m = int(str[1])
l = int(str[2])

friends = [0 for i in range(n+1)]
index = 0
cnt = 0
while True:
    friends[index] = friends[index] + 1

    if friends[index] == m:
        break

    if friends[index]%2 != 0:
        index = (index+l)%n
    else :
        if index-l < 0:
            index = n + (index-l)
        else :
            index = index - l
    cnt = cnt+1
print(cnt)
