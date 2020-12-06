def factorial(n):
    if (n == 1):
        return 1
    else:
        return n * factorial(n-1)

def choose(a, b):
    return (factorial(a) / (factorial(b) * factorial(a-b)))

num = int(input())

if (num < 4):
    print(0)
else:
    print(int(choose(num-1, 3)))


