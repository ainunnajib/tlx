n = int(input())
if n == 0:
    print(1)
elif n == 1:
    print(2)
else:
    a, b = 0, 1
    i = 3
    while a+b < n:
        a, b = b, a+b
        i += 1
    if a+b == n:
        print(i)
    else:
        print(0)