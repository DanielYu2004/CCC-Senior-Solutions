from collections import Counter
import math

string = input()

def calc_optimal(optimal):
    global string
    optimal_score = 0
    for i in range(len(optimal)):    
        if (optimal[i] != string[i]):
            optimal_score += 1
    return optimal_score


def optimal(string):
    count = {
        "A": string.count("A"),
        "B": string.count("B"),
        "C": string.count("C")
    }

    optimal = "A" * count["A"] + "B" * count["B"] + "C" * count["C"]
    optimal_score = 0

    for i in range(len(optimal)):    
        if (optimal[i] != string[i]):
            optimal_score+=1

    next_optimal = optimal
    next_optimal_score = optimal_score

    for i in range(len(optimal) - 1):
        
        next_optimal = next_optimal[len(optimal)-1] + next_optimal[:len(optimal)-1]
        next_optimal_score = calc_optimal(next_optimal)
        if (next_optimal_score < optimal_score):
            optimal = next_optimal
            optimal_score = next_optimal_score

    # print(optimal)
    # print(optimal_score)
    return [optimal, optimal_score]
    # print(string)


   

    



arr = optimal(string)
# print(arr[0])
# print(arr[1])

print(math.ceil(arr[1] / 2))

