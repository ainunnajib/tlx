n = int(input())
f = []
for _ in range(n):
    f.append(int(input()))
for ans in range(1, 100000):
    found = True
    for x in f:
        if ans%x != 0:
            found = False
            break
    if found:
        print(ans)
        break