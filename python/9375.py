t = int(input())

for i in range(t):
    n = int(input())

    dicts = {}
    for j in range(n):
        info = input().split(' ')
        value = info[0]
        key = info[1]

        if key in dicts:
            dicts[key] = dicts[key] + 1
        else :
            dicts[key] = 1
    
    # 개수 + 1 (선택하지 않았을 경우가 있기 때문)
    ans = 1
    for key in dicts:
        ans = ans * (dicts[key]+1) 

    print(ans-1) # 모두 선택하지 않는 경우 빼기