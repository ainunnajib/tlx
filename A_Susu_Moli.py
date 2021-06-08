t = int(input())
for _ in range(t):
    n, a, b, k = map(int, input().split())
    print('Kasus #'+str(_+1)+':', n + (b-a)*k)