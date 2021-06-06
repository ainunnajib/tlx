n = int(input())
s = input()
prev = ''
ans = ''
for c in s:
    if c != prev:
        ans += c
        prev = c
print(ans)