MAX = 10001

isprime = [True for i in range(MAX)]
isprime[0], isprime[1] = False, False
for i in range(2, MAX):
    if isprime[i]:
        for x in range(i*2, MAX, i):
            isprime[x] = False

allprimes = []
for p in range(MAX):
    if isprime[p]:
        allprimes.append(p)

m, n = map(int, input().split())
primes = []
for i in range(m, n+1):
    if isprime[i]:
        primes.append(i)

ada = False
for p in primes:
    for q in primes:
        z = int(str(p) + str(q))
        zisprime = True
        for x in allprimes:
            if x > z:
                break
            if z % x == 0 and z > x:
                zisprime = False
                break
        if zisprime:
            print(p, q)
            ada = True
if not ada:
    print('TIDAK ADA')