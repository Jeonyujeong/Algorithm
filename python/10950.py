# 10950
'''
t = int(input())

for _ in range(t):
    str = input().split(' ')
    a = int(str[0])
    b = int(str[1])

    print(a+b)
'''

# 2753
'''
year = int(input())
flag = 0
if year%4 == 0 :
    if year%100 != 0 or year%400 == 0:
        flag = 1
print(flag)        
'''

#1966

def checkTop(top):
    if lists[top] < max(lists):
        return False
    else :
        return True

t = int(input())
for _ in range(t):
    str = input().split(' ')
    n = int(str[0])
    m = int(str[1])

    lists = input().split(' ')
    lists = [int (i) for i in lists]
    queue = [i for i in range(0,n)]
    
    cnt = 0
    while len(queue)!=0:
        top = queue[0]
        queue.pop(0)
        print(top)
        if checkTop(top):
            cnt = cnt + 1
            if top == m:
                print(cnt)
                break
        else:
            queue.append(top)



        

    




