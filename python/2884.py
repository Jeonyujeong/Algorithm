str = input().split(' ')
h = int(str[0])
m = int(str[1])

setTime = m - 45
if setTime < 0 :
    m = 60 + setTime
    h = h - 1
    if h < 0:
        h = 23
else :
    m = setTime        

print(h, m)