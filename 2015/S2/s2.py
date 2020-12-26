j = int(input())
a = int(input())
sol = 0

jerseys = {"M": set(), "S": set(), "L": set()}

for i in range(j):
    s = input()
    jerseys[s].add(i + 1)


for i in range(a):
    size, num = input().split()
    num = int(num)
    if size == "S":
        if num in jerseys["L"]:
            sol += 1
            jerseys["L"].remove(num)
        elif num in jerseys["M"]:
            sol += 1
            jerseys["M"].remove(num)

        elif num in jerseys["S"]:
            sol += 1
            jerseys["S"].remove(num)
    elif size == "M":
        if num in jerseys["L"]:
            sol += 1
            jerseys["L"].remove(num)
        elif num in jerseys["M"]:
            sol += 1
            jerseys["M"].remove(num)
    elif size == "L":
        if num in jerseys["L"]:
            sol += 1
            jerseys["L"].remove(num)

print(sol)