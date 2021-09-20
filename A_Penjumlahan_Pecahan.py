from math import gcd
a, b = map(int, input().split())
c, d = map(int, input().split())
e = a*d + b*c
f = b*d
g = gcd(e, f)
print(e//g, f//g)