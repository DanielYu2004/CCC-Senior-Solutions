visited = set()
def convert(array):
    for i in range(len(array) - 3):
        if (array[i] == array[i+1] and array[i] == array[i+2] and array[i] == array[i+3] and array[i] == 1):
            for t in range(len(array) - i):
                if (array[i+t] == 1):
                    array[i+t] = 0
                else:
                    break
    return array
def is_off(array):
    for i in array:
        if (i != 0):
            return False
    return True
def recur(array, steps):
    global visited
    next_array = []

    for arr in array:
        arr = convert(arr)
        if (tuple(arr) not in visited):
            visited.add(tuple(arr))
            if is_off(arr):
                return steps
            else:
                for i in range(len(arr)):
                    if (arr[i] == 0):
                        temp = list(arr)
                        temp[i] = 1
                        if (not(tuple(temp) in visited) and not(temp in next_array)):
                            next_array.append(temp)

    return recur(next_array, steps + 1)  

n = int(input())
lights = []

for i in range(n):
    lights.append(int(input()))
    
print(recur([lights], 0))