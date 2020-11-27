n = input()
h = input()
length = len(n)

needle = {}

for i in n:
    if i not in needle:
        needle[i] = 1
    else:
        needle[i] += 1

print(needle) 


dict = {}



for i in range(len(h) - length + 1):
    print(h[i:i+length])

# a = {"a" : 1, "b" : 2}
# b = {"a" : 1, "b" : 2}

# print(a == b)