t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    print((a*b*c-1)%1000000007)