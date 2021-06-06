n, m = map(int, input().split())
b = m * 'B'
w = m * 'W'
while n > 0:
    print(b)
    if n > 1:
        print(w)
    n -= 2