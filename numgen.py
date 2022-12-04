import random
n = int(input())
lst = []
for i in range(n):
    rand = random.randint(0,n)
    while (rand in lst):
        rand = random.randint(0,n)
    lst.append(rand)
for i in lst:
    print(i, end = ' ')
