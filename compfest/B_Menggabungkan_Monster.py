n, m = map(int, input().split())
l = list(map(int, input().split()))
a = [0 for _ in range(n)]
a[0] = l[0]
for i in range(1, n):
    a[i] = a[i-1] + l[i]
r = a[m]
for i in range(1, n-m):
    r = max(r, a[i+m] - a[i-1])
print(r)
