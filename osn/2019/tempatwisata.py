n, m = map(int, input().split())
x = []
for _ in range(n):
    a, b = map(int, input().split())
    x.append((a, b))
for i in range(n):
    count = 0
    p, q = x[i]
    for j in range(n):
        if i != j:
            r, s = x[j]
            if not (r > q or s < p):
                count += 1
    print(count)
