a, b = map(int, input().split())
x = (a+b)//2
print(x)
s = input()
while s != 'selamat':
    if s == 'terlalu kecil':
        a = x+1
    else:
        b = x-1
    x = (a+b)//2
    print(x)

    s = input()