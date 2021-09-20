a = input()
b = input()
i = 0
if 1 != len(a) - len(b):
    print('Wah, tidak bisa :(')
else:
    while i < len(b) and a[i]==b[i]:
        i += 1
    if i == len(b):
        print('Tentu saja bisa!')
    else:
        i += 1
        while i < len(a) and a[i]==b[i-1]:
            i += 1
        if i == len(a):
            print('Tentu saja bisa!')
        else:
            print('Wah, tidak bisa :(')
