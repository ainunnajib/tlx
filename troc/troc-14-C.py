n = int(input())
s = list(map(int, input().split()))
if n == 1:
    print(0)
else:
    print(2*(n//2)+1)
    r = 'GL' * (n//2)
    r += 'G'
    print(r)
