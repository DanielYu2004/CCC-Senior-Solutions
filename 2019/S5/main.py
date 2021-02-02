i = input().split()

n = int(i[0])
k = int(i[1])

v = []

def calcLenTwo(x, y):
    return max(v[y][x], max(v[y+1][x], v[y+1][x+1]))

def calc(x, y, len, sub_len):
    return max(v[y][x], max(v[y+(len-sub_len)][x], v[y+(len-sub_len)][ x+(len-sub_len)]))

def solve(len):
    global v, n, k
    if (len == 1):
        return
    if (len == 2):
        return
    
    sub_len = int((2 * len + 2) / 3)
    solve(sub_len)

    for y in range(n-len+1):
        for x in range(y+1):
            v[y][x] = calc(x, y, len, sub_len)


for i in range(n):
    temp = [int(x) for x in input().split()]
    v.append(temp)

if (k == 1):   
    sol = 0
    for i in range(n-k+1):
        for j in range(i+1):
            sol+=v[i][j] 
    print(sol)
else:   
    for y in range(n-2+1):
        for x in range(y+1):
            v[y][x] = calcLenTwo(x,y)

    solve(k)

    sol = 0
    for i in range(n-k+1):
        for j in range(i+1):
            sol+=v[i][j]

    print(sol)

    