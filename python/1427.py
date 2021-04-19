# 1427
'''
instr = input()
ns = []
for i in range(len(instr)):
    ns.append(int(instr[i]))
ns.sort(reverse=True)
print(''.join([str(_) for _ in ns]))
'''

#9012
'''
t = int(input())
for _ in range(t):
    ps = input()
    st = []
    flag = False
    for i in range(len(ps)):
        if ps[i] == '(':
            st.append(ps[i])
        else:
            if len(st) != 0:
                st.pop()
            else :
                flag = True
    if flag:
        print("NO")
        continue
    if len(st) == 0:
        print("YES")
    else :
        print("NO")
'''    

# 1541
'''
instr = input().split(' ')
a = instr[0]
b = instr[1]
result = 1e9
for i in range(len(b)-len(a)+1):
    cnt = 0
    for j in range(len(a)):
        if b[i+j] != a[j]:
            cnt = cnt+1
    result = min(result, cnt)
print(result)
'''
    
t = int(input())
for _ in range(t):
    ps = input()
    st = []
    flag = False
    for i in range(len(ps)):
        if ps[i] == '(':
            st.append(ps[i])
        elif ps[i] == ')':
            if len(st) != 0:
                st.pop()
            else :
                flag = True
    if flag:
        print("NO")
        continue
    if len(st) == 0:
        print("YES")
    else :
        print("NO")