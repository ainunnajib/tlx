n, k, c, p = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

#brute force first
for x in range(n):
    maxdist = 0
    mincost = 10**19
    for y in range(n):
        if p == 1:
            cost = a[x] + b[y] + abs(x-y)*c
        else:
            cost = a[x] + b[y] + (abs(x-y)**2)*c
        if cost <= k:
            dist = abs(x-y) + 1
            if maxdist < dist or (maxdist == dist and mincost > cost):
                maxdist = dist
                mincost = cost
    if mincost < 10**19:
        print(maxdist, k - mincost)
    else:
        print(0, k)