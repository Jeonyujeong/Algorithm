wordlist = []
searchlist = []

instr = input().split(' ')
n = int(instr[0])
m = int(instr[1])

for i in range(n):
    wordlist.append(input())

for i in range(m):
    searchlist.append(input())

wordlist.sort()
searchlist.sort()

cnt = 0
for search in searchlist:
    for word in wordlist:
        if word[0] < search[0] : 
            continue
        elif word[0] > search[0] :
            break

        if word.startswith(search):
            cnt = cnt + 1
            break
print(cnt)