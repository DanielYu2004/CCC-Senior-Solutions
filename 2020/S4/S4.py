from collections import Counter
import math

string = "ABCABCABAAABBBCCCABABCABCBACBA"


def swap(string, a, b):
    if (a < b):
        return string[:a] + string[b] + string[a+1: b] + string[a] + string[b+1:]
    else:
        return string[:b] + string[a] + string[b+1: a] + string[b] + string[a+1:]


    # temp = string[a]
    # string[a] = string[b]
    # string[b] = temp
    # return string

def calc_optimal(optimal):
    global string
    optimal_score = {
        "A": [],
        "B": [],
        "C": []
    }
    for i in range(len(optimal)):    
        if (optimal[i] != string[i]):
            optimal_score[optimal[i]].append(i)
    return optimal_score

def count_optimal(optimal_score):
    score = 0
    for value in optimal_score.values():
        score += len(value)
    return score

def optimal(string):
    count = {
        "A": string.count("A"),
        "B": string.count("B"),
        "C": string.count("C")
    }

    optimal = "A" * count["A"] + "B" * count["B"] + "C" * count["C"]
    optimal_score = {
        "A": [],
        "B": [],
        "C": []
    } #indexes of positions that need to be changed

    count = {
        "A": [],
        "B": [],
        "C": []
    }

    for i in range(len(optimal)):    
        if (optimal[i] != string[i]):
            optimal_score[optimal[i]].append(i)

    next_optimal = optimal
    next_optimal_score = optimal_score

    for i in range(len(optimal) - 1):
        
        next_optimal = next_optimal[len(optimal)-1] + next_optimal[:len(optimal)-1]
        next_optimal_score = calc_optimal(next_optimal)
        if (count_optimal(next_optimal_score) < count_optimal(optimal_score)):
            optimal = next_optimal
            optimal_score = next_optimal_score

    # print(optimal)
    # print(optimal_score)
    return [optimal, optimal_score]
    # print(string)


   

    



arr = optimal(string)

optimal = arr[0]
values = arr[1]


available = {
    "A": [],
    "B": [],
    "C": []
}

for i in ["A", "B", "C"]:
    for t in values[i]:
        available[string[t]].append(t)
print(string)
print(optimal)
print(values)
print(available)

aValues = values["A"]
for i in aValues:
    to_find = string[i]
    inter = list(set(values["A"]).intersection(available[to_find]))
    if (len(inter) > 1 or (len(inter) == 1 and inter[0] != i)):
        index = inter[0]
        for i in range:
        print(inter)
        string = swap(string, i, index)
        # values["A"].remove(i)
        # available[""]
        # available["A"].remove()



# newA = []
# for i in values["A"]:
#     letter = string[i]
#     print(string, "FUCK")
#     if (len(values[letter]) > 0):
#         switch_letter = values[letter][0]
#         string = swap(string, i, switch_letter)
#         print(string, "SWITCHED")
#         values[letter].remove(switch_letter)
#     else:
#         newA.append(i)

# values["A"] = newA

# print("A END")

# newB = []
# for i in values["B"]:
#     letter = string[i]
#     print(string, "FUCK")
#     if (len(values[letter]) > 0):
#         switch_letter = values[letter][0]
#         string = swap(string, i, switch_letter)
#         print(string, "SWITCHED")
#         values[letter].remove(switch_letter)
#     else:
#         newB.append(i)

# values["B"] = newB

# print(string)
# print(values)
        
    



# total = 0
# for value in arr[1].values():
#     total+=len(value)
# print(math.ceil(total / 2))

