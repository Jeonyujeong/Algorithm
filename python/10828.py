
import sys

n = int(sys.stdin.readline().rstrip())
stack = []

for i in range(0, n):
    order = sys.stdin.readline().rstrip()
    if 'push' in order:
        x = order[5:]
        stack.append(x)
    elif order == 'pop':
        if len(stack) == 0:
            print(-1)
        else :
            top = stack.pop()
            print(top)
    elif order == 'size':
        print(len(stack))
    elif order == 'empty':
        if len(stack) == 0:
            print(1)
        else :
            print(0)
    elif order == 'top':
        if len(stack) == 0:
            print(-1)
        else :
            top = stack.pop()
            print(top)
