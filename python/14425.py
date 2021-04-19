# 14425
# dict 안에 있는 key 찾는 방법
'''
instr = input().split(' ')
n = int(instr[0])
m = int(instr[1])

sets = {}
for _ in range(n):
    sets[input()] = 1

cnt = 0
for i in range(m):
    mstr = input()
    
    if mstr in sets :
        cnt = cnt + 1

print(cnt)
'''

# 1085
'''
instr = input().split(' ')
instr = [int(i) for i in instr]
x = instr[0]
y = instr[1]
w = instr[2]
h = instr[3]

hmin = min(abs(y-0), abs(y-h))
wmin = min(abs(x-0), abs(x-w))
print(min(hmin, wmin))
'''

# 11656
'''
instr = input()
strlist = []
for i in range(len(instr)):
    suffix = instr[i:]
    strlist.append(suffix)
strlist.sort()

for suff in strlist:
    print(suff)
'''

# 1977
'''
import math

m = int(input())
n = int(input())

m = math.ceil(math.sqrt(m))
n = math.floor(math.sqrt(n))

nums = []
for i in range(m, n+1):
    nums.append(i**2)

if len(nums) == 0:
    print(-1)
else:
    print(sum(nums))
    print(min(nums))
'''

# 9375 - 패션왕
'''
t = int(input())
for _ in range(t):
    n = int(input())
    psitems = {}

    for _ in range(n):
        instr = input().split(' ')
        cate = instr[1]
        if cate in psitems:
            cnt = psitems[cate]
            psitems[cate] = cnt + 1
            print(cnt)
        else :
            psitems[cate] = 1
'''