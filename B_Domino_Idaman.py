n, m = map(int, input().split())
r = 1
for _ in range(n*m-1):
    r *= 2
    r %= 998244353
print(r)