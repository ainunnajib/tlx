import math
n = int(input())
x = n - 1
f = int(math.sqrt(x))
while x % f != 0:
    f -= 1
ans = ""
for _ in range(x//f - 1):
    ans += str(f) + " "
ans += str(f + 1)
print(x//f)
print(ans)