import math

num_inputs = int(input())

inputs_list = []
for x in range(num_inputs):
    inputs_list.append(int(input()))

primes = set()
primes.add(2)
composites = set()
composites.add(1)



def find_primes(target):
    checked = {}



    for i in primes:
        if i not in checked:
            checked[target - i] = i
        else: 
            print(checked[i] ,i)
            return()    
  
    for i in range(max(primes),target):
        isPrime = True
        for x in range(2, math.ceil(math.sqrt(i)) + 1):

            if i % x == 0:
                isPrime = False
                break

        if isPrime == True:
            primes.add(i)
            #print(i)
            if i not in checked:
                checked[target - i] = i

                tempcheck = target-i

                for p in range(2,math.ceil(math.sqrt(tempcheck)) + 1):
                    if (tempcheck % p) == 0:
                        break

                else:
                    print(i, tempcheck)
                    return()

            else: 
                print(checked[i] ,i)
                #print(primes)
                return()
        else:
            composites.add(i)



for i in range(len(inputs_list)):
    find_primes(inputs_list[i]*2)





