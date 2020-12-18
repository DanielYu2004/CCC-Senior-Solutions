n = int(input())

arr = []

for i in range(n):
    arr.append(int(input()))

arr = sorted(arr)

sol = (arr[2] - arr[0])/2

for i in range(1,n-2):
    sol = min(sol, (arr[i+2] - arr[i])/2 )

if (int(sol) == sol):
    print(str(int(sol)) + ".0")
else:
    print(sol)