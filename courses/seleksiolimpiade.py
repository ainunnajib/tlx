t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    p = input()
    l = []
    for __ in range(n):
        s = input().split()
        t = (int(s[3]), int(s[2]), int(s[1]), s[0])
        l.append(t)
    l.sort(reverse = True)

    lolos = False
    for i in range(m):
        if l[i][3] == p:
            lolos = True
            break

    print('YA' if lolos else 'TIDAK')
