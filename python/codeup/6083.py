nArr = [ int(i) for i in input().split(' ') ]

for i in range(0,nArr[0]):
    for j in range(0, nArr[1]):
        for k in range(0, nArr[2]):
            print(i, j, k)

print(nArr[0]*nArr[1]*nArr[2])