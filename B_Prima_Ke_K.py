isprime = [True for i in range(990000)]
for x in range(2, 990000):
    if isprime[x]:
        for i in range(x*x, 990000, x):
            isprime[i] = False
listprimes = []
for x in range(2, 990000):
    if isprime[x]:
        listprimes.append(x)

t = int(input())
for i in range(t):
    print(listprimes[int(input())-1])