# LCM (최소공배수)

n = int(input())

def gcd(a, b) :
    if (b <= 0) :
        return a
    return gcd(b, a%b)

def lcm(a, b) :
    return (a*b)/gcd(a,b)

for i in range(n) :
    nums = input().split(' ')
    a = int(nums[0])
    b = int(nums[1])
    print(int(lcm(a, b)))