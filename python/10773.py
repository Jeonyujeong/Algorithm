#2021-02-24

#10773
# list 의 합
'''
k = int(input())

nums = []
for _ in range(k):
    n = int(input())
    if n != 0:
        nums.append(n)
    else :
        nums.pop()

print(sum(nums))
'''

# 10872
'''
def factorial(n):
    if n == 1 or n == 0:
        return 1
    else :
        return n * factorial(n-1)
    
n = int(input())
print(factorial(n))
'''

# 2562
# list 의 max 값과, max index 값 찾기
'''
nums = []
for _ in range(9):
    nums.append(int(input()))
print(max(nums))
print(nums.index(max(nums)) + 1)
'''

#11557
# dict 이용하기
'''
t = int(input())

for _ in range(t):
    info = {}
    n = int(input())

    for _ in range(n) :
        instr = input().split(' ')
        info[int(instr[1])] = instr[0]
    
    md = max(info.keys())
    print(info[md])
'''

#7567
'''
plates = input()
height = 10
pre = plates[0]
for i in range (1,len(plates)):
    cur = plates[i]
    
    if pre == cur:
        height = height + 5
    else:
        height = height + 10
    pre = cur

print(height)
'''
