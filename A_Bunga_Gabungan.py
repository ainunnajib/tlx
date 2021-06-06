p, q = map(int, input().split())
total = p*p + q*q + 1
if total % 4 == 0:
    print(total//4)
else:
    print(-1)