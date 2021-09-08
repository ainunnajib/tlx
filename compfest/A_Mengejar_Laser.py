n = int(input())
x = abs(n)*2
if n > 0:
    x -= 1
print(x*(x+1)//2)