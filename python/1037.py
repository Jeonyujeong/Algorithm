# 2021.02.25
# 1037
'''
cnt = int(input())

instr = input().split(' ')
instr = [int (i) for i in instr]
instr.sort()

result = int(instr[0]) * int(instr[cnt-1])
print(result)
'''

# 10870
'''
def fibo(num):
    if num==1:
        return 1
    elif num==0:
        return 0
    else:
        return fibo(num-1) + fibo(num-2)

n = int(input())
print(fibo(n))
'''

# 3036
# sep 연산자, 최대공약수
'''
def gcd(a,b):
    if b > a:
        tmp = a
        a = b
        b = tmp
    while b > 0:
        c = b
        b = a % b
        a = c
    return a

n = int(input())

strN = input().split(' ')
strN = [int(i) for i in strN]
ring = strN[0]
for i in range(1,len(strN)):
    val = strN[i]
    gcdValue = gcd(ring, val)
    print(ring//gcdValue, val//gcdValue, sep='/')
'''

# 2609
# 최대공약수, 최대공배수 구하기
'''
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

def lcm(a, b):
    return (a*b)//gcd(a,b)

inputN = input().split(' ')
a = int(inputN[0])
b = int(inputN[1])

print(gcd(a,b))
print(lcm(a,b))
'''

# 11723
# 최소공배수 
'''
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

def lcm(a, b):
    return (a*b)//gcd(a,b)

t = int(input())
for _ in range(t):
    inputN = input().split(' ')
    a = int(inputN[0])
    b = int(inputN[1])

    print(lcm(a,b))
'''