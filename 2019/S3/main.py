from copy import copy, deepcopy

def simplify(arr):
    for i in range(3):
        #Horizontal
        count = arr[i].count("X")
        if count == 1:
            #Left
            if (arr[i][0] == "X"):
                arr[i][0] = int(arr[i][1] - (arr[i][2] - arr[i][1]))

            #Middle
            if (arr[i][1] == "X"):
                arr[i][1] = int(arr[i][2] - ((arr[i][2] - arr[i][0]) / 2))

            #Right
            if (arr[i][2] == "X"):
                arr[i][2] = int(arr[i][1] + ((arr[i][1] - arr[i][0])))

        #Vertical
        count = 0

        if (arr[0][i] == "X"):
            count += 1
        if (arr[1][i] == "X"):
            count += 1
        if (arr[2][i] == "X"):
            count += 1

        if count == 1:
            #Left
            if (arr[0][i] == "X"):
                arr[0][i] = int(arr[1][i] - (arr[2][i] - arr[1][i]))
            if (arr[1][i] == "X"):
                arr[1][i] = int(arr[2][i] - ((arr[2][i] - arr[0][i])/2))
            if (arr[2][i] == "X"):
                arr[2][i] = int(arr[1][i] + (arr[1][i] - arr[0][i]))
    for i in range(3):
        #Horizontal
        count = arr[i].count("X")
        if count == 1:
            #Left
            if (arr[i][0] == "X"):
                arr[i][0] = int(arr[i][1] - (arr[i][2] - arr[i][1]))

            #Middle
            if (arr[i][1] == "X"):
                arr[i][1] = int(arr[i][2] - ((arr[i][2] - arr[i][0]) / 2))

            #Right
            if (arr[i][2] == "X"):
                arr[i][2] = int(arr[i][1] + ((arr[i][1] - arr[i][0])))

        #Vertical
        count = 0

        if (arr[0][i] == "X"):
            count += 1
        if (arr[1][i] == "X"):
            count += 1
        if (arr[2][i] == "X"):
            count += 1

        if count == 1:
            #Left
            if (arr[0][i] == "X"):
                arr[0][i] = int(arr[1][i] - (arr[2][i] - arr[1][i]))
            if (arr[1][i] == "X"):
                arr[1][i] = int(arr[2][i] - ((arr[2][i] - arr[0][i])/2))
            if (arr[2][i] == "X"):
                arr[2][i] = int(arr[1][i] + (arr[1][i] - arr[0][i]))
    return arr

def total(arr):
    count = 0
    for i in range(3):
        count += arr[i].count("X")
    return count

def print_sol(arr):
    for i in range(3):
        print(arr[i][0], arr[i][1], arr[i][2])

def dfs(arr):
    arr = simplify(arr)

    if (total(arr) == 0):
        return arr
    else:
        for y in range(3):
            for x in range(3):
                if (arr[y][x] == "X"):
                    temp = deepcopy(arr)
                    for i in range(1,11):
                        temp[y][x] = i
    



arr = []

for i in range(3):
    arr.append([])
    l = input().split()
    for t in range(3):
        if (l[t] == "X"):
            arr[i].append("X")
        else:
            arr[i].append(int(l[t]))

    # arr.append(int(x) for x in input().split())
        
# print(arr)



# print(simplify(arr))

arr = simplify(arr)

if (total(arr) == 0):
    print_sol(arr)
else:
    dfs()

