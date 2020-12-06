import math

t = int(input())

base1 = [
    ["empty", "crystal", "crystal", "crystal", "empty",],
    ["empty", "empty", "crystal", "empty", "empty",],
    ["empty", "empty", "empty", "empty", "empty",],
    ["empty", "empty", "empty", "empty", "empty",],
    ["empty", "empty", "empty", "empty", "empty",]
]

base2 = [
    ["empty", "crystal", "crystal", "crystal", "empty",],
    ["empty", "continue", "crystal", "continue", "empty",],
    ["empty", "empty", "continue", "empty", "empty",],
    ["empty", "empty", "empty", "empty", "empty",],
    ["empty", "empty", "empty", "empty", "empty",]
]

def recur(x, y, level):
    if (level == 1):
        return base1[y][x]
    else:
        localX = math.floor(x/(5 ** (level - 1)))
        localY = math.floor(y/(5 ** (level - 1)))
        if (base2[localY][localX] == "continue"):
            newX = x - (localX) * (5 ** (level-1))
            newY = y - (localY) * (5 ** (level-1))
            return recur(newX, newY, level-1)
        else:
            return base1[localY][localX]
        



def solve():
    array = [int(x) for x in input().split()]

    level = array[0]
    x = array[1]
    y = array[2]

    print(recur(x ,y, level))

    return 0

for i in range(t):
    solve()

    