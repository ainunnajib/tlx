n, m = map(int, input().split())
n -= m
if n < 0 or n > 4*m:
    print(-1, -1)
else:
    maximum = n // 4
    n -= 3 * m
    minimum = 0
    if n > 0:
        minimum = n
    print(minimum, maximum)