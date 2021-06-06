import math
n = int(input())
f = int(math.sqrt(n))
while n % f != 0:
    f -= 1
print(f, n//f)