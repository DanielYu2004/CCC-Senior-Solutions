n = input()
h = input()
length = len(n)

needle = {}

for i in n:
    if i not in needle:
        needle[i] = 1
    else:
        needle[i] += 1



dict = {}

def is_perm(s):
    global needle
    for letter in set(s):
        if not(letter in needle and s.count(letter) == needle[letter]):
            return False

    return True

visited = set()

for i in range(len(h) - len(n) + 1):
    temp = h[i:i+length]
    if (is_perm(temp) and temp not in visited):
        visited.add(temp)

print(len(visited))