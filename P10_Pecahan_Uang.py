l = [1000, 500, 200, 100, 50, 20, 10, 5, 2, 1]
x = {}
k = int(input())
for i in l:
    x[i] = k // i
    k %= i
for i in x:
    if x[i] > 0:
        print(i, x[i])