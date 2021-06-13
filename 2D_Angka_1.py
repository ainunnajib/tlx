n = int(input())
x, d = 0, 1
for _ in range(n):
    x += d
    d += 1
    print(x)