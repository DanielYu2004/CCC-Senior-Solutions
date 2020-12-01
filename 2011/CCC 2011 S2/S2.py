n = int(input())

ans = []
res = []

score = 0
for i in range(n):
    res.append(input())
for i in range(n):
    if (input() == res[i]):
        score+=1

print (score)
