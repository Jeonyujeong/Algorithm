n = int(input())
load = [int(i) for i in input().split(' ')]
price = [int(i) for i in input().split(' ')]

loadLen = sum(load)
result = 0
i = 0
while i < n-1:
    result = result + (price[i] * load[i])
    j = i + 1
    while j < n-1:
        if price[i] > price[j]:
            break
        result = result + (price[i] * load[j])  # i 위치의 값으로 계산
        j = j + 1
    i = j   # i보다 작은 값의 위치로 점프

print(result)

    
