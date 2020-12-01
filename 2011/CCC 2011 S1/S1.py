rows = int(input())

text = ""

for i in range(rows):
    text += input()

t = 0 
s = 0

t += text.count("t") + text.count("T")

s += text.count("s") + text.count("S")

if (t > s):
    print("English")
else:
    print("French")